
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerProjectile.h"
#include "AIController.h"

AMagicBattleSoccerPlayer::AMagicBattleSoccerPlayer(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	this->OnActorBeginOverlap.AddDynamic(this, &AMagicBattleSoccerPlayer::OnBeginOverlap);
	this->OnActorEndOverlap.AddDynamic(this, &AMagicBattleSoccerPlayer::OnEndOverlap);
	this->SetActorTickEnabled(true);
	IsAttacking = false;
	IsStunned = false;
	StunReleaseTime = 0;
}

/** Gets the game mode */
AMagicBattleSoccerGameMode* AMagicBattleSoccerPlayer::GetGameMode()
{
	return Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

/** Gets the soccer ball */
AMagicBattleSoccerBall* AMagicBattleSoccerPlayer::GetSoccerBall()
{
	return GetGameMode()->SoccerBall;
}

/** Gets all the teammates of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerPlayer::GetTeammates()
{
	const TArray<AMagicBattleSoccerPlayer*>& Players = GetGameMode()->SoccerPlayers;
	TArray<AMagicBattleSoccerPlayer*> Teammates;

	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Players.CreateConstIterator()); It; ++It)
	{
		if (this != *It && (*It)->EnemyGoal == EnemyGoal)
		{
			Teammates.Add(*It);
		}
	}

	return Teammates;
}

/** Gets all the opponents of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerPlayer::GetOpponents()
{
	const TArray<AMagicBattleSoccerPlayer*>& Players = GetGameMode()->SoccerPlayers;
	TArray<AMagicBattleSoccerPlayer*> Opponents;

	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Players.CreateConstIterator()); It; ++It)
	{
		if ((*It)->EnemyGoal != EnemyGoal)
		{
			Opponents.Add(*It);
		}
	}

	return Opponents;
}

/** True if this player possesses the ball */
bool AMagicBattleSoccerPlayer::PossessesBall()
{
	AMagicBattleSoccerPlayer *Possessor = GetSoccerBall()->Possessor;
	return (this == Possessor);
}

/** True if the player can be pursued */
bool AMagicBattleSoccerPlayer::CanBePursued()
{
	return !IsStunned;
}

/** Updates the movement speed based on conditions (ball possessor, stunned, etc) */
void AMagicBattleSoccerPlayer::UpdateMovementSpeed()
{
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	AMagicBattleSoccerBall *Ball = GetSoccerBall();
	float NewSpeed = DefaultMovementSpeed;

	if (IsStunned)
	{
		NewSpeed = 0;
	}
	else if (Ball->Possessor == this)
	{
		NewSpeed *= 0.65f;
	}

	MovementComponent->MaxWalkSpeed = NewSpeed;
}

/** Kicks the ball in the forward direction */
UFUNCTION(BlueprintCallable, Category = Soccer)
void AMagicBattleSoccerPlayer::KickBallForward()
{
	AMagicBattleSoccerBall *Ball = GetSoccerBall();
	FVector BallLocation = Ball->GetActorLocation();
	const float KickForce = 28000.0f;	
	Ball->Kick(GetActorForwardVector() * KickForce);
}

/** Kicks the ball to the specified location */
UFUNCTION(BlueprintCallable, Category = Soccer)
void AMagicBattleSoccerPlayer::KickBallToLocation(const FVector& Location)
{
	AMagicBattleSoccerBall *Ball = GetSoccerBall();
	FVector BallLocation = Ball->GetActorLocation();
	const float KickForce = 60.0f;
	Ball->Kick(FVector(Location.X - BallLocation.X, Location.Y - BallLocation.Y, 0.0f) * KickForce);
}

/** Tries to kick ball into the goal. Returns true if the ball was kicked. */
bool AMagicBattleSoccerPlayer::KickBallToGoal()
{
	AMagicBattleSoccerBall *Ball = GetSoccerBall();
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(EnemyGoal);
	ActorsToIgnore.Add(GetSoccerBall());

	if (this != Ball->Possessor)
	{
		return false;
	}
	else if (GetDistanceTo(EnemyGoal) > 1500.0f)
	{
		return false;
	}
	else if (NULL != GetClosestActorObstructingPoint(EnemyGoal->GetActorLocation() + FVector(0, 0, 100), ActorsToIgnore))
	{
		return false;
	}
	else
	{
		KickBallToLocation(EnemyGoal->GetActorLocation());
		return true;
	}		
}

/** Clips the value n so that it will be within o+d and o-d */
void AMagicBattleSoccerPlayer::ClipAxe(float& n, float o, float d)
{
	if (n < o - d)
	{
		n = o - d;
	}
	else if (n > o + d)
	{
		n = o + d;
	}
}

/** If this player is in their action zone, call this function to ensure the location will not leave the zone bounds */
FVector AMagicBattleSoccerPlayer::ClipToActionZone(const FVector& Location)
{
	FVector ClippedPoint = Location;
	if (NULL != ActionZone)
	{
		FVector BoxOrigin, BoxExtent;
		ActionZone->GetActorBounds(false, BoxOrigin, BoxExtent);

		// Clipping is easy since the action box is always aligned with the major axes.
		ClipAxe(ClippedPoint.X, BoxOrigin.X, BoxExtent.X);
		ClipAxe(ClippedPoint.Y, BoxOrigin.Y, BoxExtent.Y);
	}
	return ClippedPoint;
}

/** Gets the closest actor between this player and a point */
AActor* AMagicBattleSoccerPlayer::GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore)
{
	if (NULL == EnemyGoal)
	{
		return NULL;
	}
	else
	{
		FHitResult HitResult;
		FCollisionQueryParams CollisionQueryParams(FName(TEXT("GetClosestActorObstructingPoint Trace")), false, this);
		CollisionQueryParams.AddIgnoredActors(ActorsToIgnore);
		FCollisionObjectQueryParams CollisionObjectQueryParams;
		CollisionObjectQueryParams.AddObjectTypesToQuery(ECC_Pawn);
		GetWorld()->LineTraceSingle(
			HitResult
			, GetActorLocation()
			, Point
			, ECC_Pawn
			, CollisionQueryParams
			);
		AActor* ObstructingActor = HitResult.Actor.Get(false);
		return ObstructingActor;
	}
}

/** Gets the closest enemy to this player that can be pursued */
AMagicBattleSoccerPlayer* AMagicBattleSoccerPlayer::GetClosestOpponent()
{
	const TArray<AMagicBattleSoccerPlayer*>& Opponents = GetOpponents();
	AMagicBattleSoccerPlayer* ClosestOpponent = NULL;
	float ClosestOpponentDistance = 0.0f;
	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
	{
		if (NULL == ClosestOpponent || GetDistanceTo(*It) < ClosestOpponentDistance && (*It)->CanBePursued())
		{
			ClosestOpponent = *It;
			ClosestOpponentDistance = GetDistanceTo(*It);
		}
	}
	return ClosestOpponent;
}

/** Gets the ideal teammate to pass the soccer ball to, or NULL if there is none */
AMagicBattleSoccerPlayer* AMagicBattleSoccerPlayer::GetIdealPassMate()
{
	const TArray<AMagicBattleSoccerPlayer*>& Teammates = GetTeammates();
	AMagicBattleSoccerPlayer* IdealPassMate = NULL;
	float MyDistanceToGoal = GetDistanceTo(EnemyGoal);
	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Teammates.CreateConstIterator()); It; ++It)
	{
		float DistanceToGoal = (*It)->GetDistanceTo(EnemyGoal);
		float DistanceToSelf = GetDistanceTo(*It);

		// Skip this teammate if they're farther from the goal
		if (MyDistanceToGoal < DistanceToGoal)
		{
			continue;
		}
		// Skip this teammate if they're farther from the goal than the ideal pass mate
		else if (NULL != IdealPassMate && IdealPassMate->GetDistanceTo(EnemyGoal) < DistanceToGoal)
		{
			continue;
		}
		// Skip this teammate if they're too close or too far
		else if (DistanceToSelf < 600 || DistanceToSelf > 1600)
		{
			continue;
		}
		// Skip this teammate if there's an opponent close to them
		else
		{
			AMagicBattleSoccerPlayer *ClosestOpponent = (*It)->GetClosestOpponent();
			if (NULL != ClosestOpponent && ClosestOpponent->GetDistanceTo(*It) < 300)
			{
				continue;
			}
			else
			{
				// Skip this teammate if there's something in between us and them
				TArray<AActor*> ActorsToIgnore;
				ActorsToIgnore.Add(*It);
				ActorsToIgnore.Add(GetSoccerBall());
				if (NULL != GetClosestActorObstructingPoint((*It)->GetActorLocation(), ActorsToIgnore))
				{
					continue;
				}

				// Success!
				IdealPassMate = *It;
			}
		}
	}
	return IdealPassMate;
}

/** Gets the ideal object to run to if the player is idle */
AActor* AMagicBattleSoccerPlayer::GetIdealPursuitTarget()
{	
	// By default we want to pursue the soccer ball
	AMagicBattleSoccerBall *SoccerBall = GetSoccerBall();
	AActor* PursuitTarget = SoccerBall;

	// Find out the closest obstructing actor
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(SoccerBall);
	// Ignore stunned players
	const TArray<AMagicBattleSoccerPlayer*>& Opponents = GetOpponents();
	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
	{
		AMagicBattleSoccerPlayer *Player = *It;
		if (!Player->CanBePursued())
		{
			ActorsToIgnore.Add(*It);
		}
	}

	AActor* ObstructingActor = GetClosestActorObstructingPoint(PursuitTarget->GetActorLocation(), ActorsToIgnore);
	if (NULL != ObstructingActor)
	{
		// If the obstructing actor is an opponent, then pursue them
		AMagicBattleSoccerPlayer *ObstructingPlayer = Cast<AMagicBattleSoccerPlayer>(ObstructingActor);
		if (NULL != ObstructingPlayer && GetOpponents().Contains(ObstructingPlayer) && !ActorsToIgnore.Contains(ObstructingPlayer))
		{
			PursuitTarget = ObstructingPlayer;
		}
	}

	return PursuitTarget;
}

/** Gets the ideal point to run to when not chasing another actor while following the ball possessor */
FVector AMagicBattleSoccerPlayer::GetIdealPossessorFollowLocation()
{
	AMagicBattleSoccerPlayer* Possessor = GetSoccerBall()->Possessor;
	if (NULL == Possessor)
	{
		// The possessor could have been reset before we got to this function from an AI task blueprint.
		return GetActorLocation();
	}
	else
	{
		FVector MyLocation = GetActorLocation();
		FVector NewLocation = FVector(
			MyLocation.X,
			(Possessor->GetActorLocation().Y + EnemyGoal->GetIdealRunLocation(this).Y) * 0.5f,
			MyLocation.Z
			);
		return NewLocation;
	}
}

/** Attacks a soccer player */
void AMagicBattleSoccerPlayer::AttackPlayer(AMagicBattleSoccerPlayer* Target)
{
	if (!PossessesBall() && NULL != CurrentWeapon)
	{
		// Face the target
		FRotator faceRot = (Target->GetActorLocation() - GetActorLocation()).Rotation();
		SetActorRotation(faceRot);

		// Start attacking the player if we haven't already
		if (!IsAttacking)
		{
			CurrentWeapon->PrimaryActionPressed();
			IsAttacking = true;
		}
	}

	/*
	AMagicBattleSoccerBall *Ball = GetSoccerBall();
	if (NULL != Target)
	{
		// Stun the target for half a second
		if (!Target->IsStunned)
		{
			Target->Stun(1.0f);
		}

		// Kick the ball away from the target if they possess the ball
		if (Target == Ball->Possessor)
		{
			Ball->Kick(FVector(FMath::FRandRange(-35000.0f, 35000.0f), FMath::FRandRange(-35000.0f, 35000.0f), 0.0f));
		}
	}*/
}

/** Stops attacking */
void AMagicBattleSoccerPlayer::CeaseFire()
{
	if (IsAttacking && NULL != CurrentWeapon)
	{
		CurrentWeapon->PrimaryActionReleased();
		IsAttacking = false;
	}
}

/** Gives a weapon to the player */
void AMagicBattleSoccerPlayer::GiveWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (NULL != CurrentWeapon)
	{
		CurrentWeapon->Destroy();
	}
	if (NULL != (CurrentWeapon = Weapon))
	{
		USkeletalMeshComponent* SkeletalMesh = Cast<USkeletalMeshComponent>(GetComponentByClass(USkeletalMeshComponent::StaticClass()));
		Weapon->SetOwner(this);
		Weapon->AttachRootComponentTo(SkeletalMesh, FName(TEXT("RightHand")), EAttachLocation::SnapToTarget);
	}
}

/** Stuns this player */
void AMagicBattleSoccerPlayer::Stun(float Duration)
{
	/*
	StunReleaseTime = GetWorld()->TimeSeconds + Duration;
	IsStunned = true;
	UpdateMovementSpeed();*/
}

#pragma region Event Handlers

void AMagicBattleSoccerPlayer::OnBeginOverlap(AActor* OtherActor)
{
	AMagicBattleSoccerBall *Ball = Cast<AMagicBattleSoccerBall>(OtherActor);
	if (NULL != Ball)
	{
		OverlappingBall = Ball;
	}
	else
	{
		// Handle projectile collisions
		AMagicBattleSoccerProjectile* Projectile = Cast<AMagicBattleSoccerProjectile>(OtherActor);
		if (NULL != Projectile)
		{
			bool ignore = false;

			// Ignore the event if the owner is on our team
			const AMagicBattleSoccerPlayer *spawnedByPlayer = Cast<AMagicBattleSoccerPlayer>(Projectile->SpawnedByActor);
			if (NULL != spawnedByPlayer)
			{
				const AMagicBattleSoccerGoal *owningPlayerEnemyGoal = spawnedByPlayer->EnemyGoal;
				if (owningPlayerEnemyGoal == EnemyGoal)
				{
					ignore = true;
				}
			}

			if (!ignore)
			{
				if ((Hitpoints -= Projectile->Damage) <= 0)
				{
					GetGameMode()->DestroySoccerPlayer(this);
				}

				// Destroy the projectile
				OtherActor->Destroy();
			}
		}
	}
}

void AMagicBattleSoccerPlayer::OnEndOverlap(AActor* OtherActor)
{
	AMagicBattleSoccerBall *Ball = Cast<AMagicBattleSoccerBall>(OtherActor);
	if (NULL != Ball)
	{
		OverlappingBall = NULL;
	}
}

void AMagicBattleSoccerPlayer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// If we're stunned then try to expire the stun timer
	if (IsStunned && GetWorld()->TimeSeconds > StunReleaseTime)
	{
		IsStunned = false;
		UpdateMovementSpeed();
	}

	// If the ball is overlapping us and doesn't presently have a possessor, try to assign ourselves
	// possession. This can fail if we just had possession moments ago (otherwise we could kick the ball
	// and immediately take possession again)
	if (NULL != OverlappingBall && NULL == OverlappingBall->Possessor && !IsStunned)
	{
		OverlappingBall->SetPossessor(this);
	}
}

/** This occurs when play begins */
void AMagicBattleSoccerPlayer::BeginPlay()
{
	Super::BeginPlay();

	// Add ourselves to the game mode cache
	GetGameMode()->SoccerPlayers.Add(this);

	// Reset the hitpoint count
	Hitpoints = MaxHitpoints;

	// Retain the current walk speed as the default movement speed
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	DefaultMovementSpeed = MovementComponent->MaxWalkSpeed;

	// Assign the player's default weapon
	if (NULL != DefaultWeaponBlueprint)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.bNoCollisionFail = true;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = this->Instigator;
		SpawnParameters.bDeferConstruction = false;
		GiveWeapon(GetWorld()->SpawnActor<AMagicBattleSoccerWeapon>(DefaultWeaponBlueprint->GeneratedClass, SpawnParameters));
	}

}

/** This occurs when play ends */
void AMagicBattleSoccerPlayer::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::ReceiveEndPlay(EndPlayReason);

	// Remove ourselves from the game mode cache
	GetGameMode()->SoccerPlayers.Remove(this);
}

/** Handle the primary action press of the player controlling this character */
void AMagicBattleSoccerPlayer::HandleControllerPrimaryActionPressed()
{
	if (PossessesBall())
	{
		KickBallForward();
	}
	else if (!IsAttacking)
	{
		if (NULL != CurrentWeapon)
		{
			CurrentWeapon->PrimaryActionPressed();
		}
		IsAttacking = true;
	}
}

/** Handle the primary action press of the player controlling this character */
void AMagicBattleSoccerPlayer::HandleControllerPrimaryActionReleased()
{
	if (NULL != CurrentWeapon && IsAttacking)
	{
		CurrentWeapon->PrimaryActionReleased();
	}

	IsAttacking = false;
}

#pragma endregion
