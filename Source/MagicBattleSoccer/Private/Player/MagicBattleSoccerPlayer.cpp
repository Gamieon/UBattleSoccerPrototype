
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccerPlayerController.h"
#include "AIController.h"
#include "Engine/TriggerBox.h"

AMagicBattleSoccerPlayer::AMagicBattleSoccerPlayer(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	this->OnActorBeginOverlap.AddDynamic(this, &AMagicBattleSoccerPlayer::OnBeginOverlap);
	this->OnActorEndOverlap.AddDynamic(this, &AMagicBattleSoccerPlayer::OnEndOverlap);
	this->SetActorTickEnabled(true);

	CapsuleComponent->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
	CapsuleComponent->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);

	CurrentWeapon = nullptr;
	IsAttacking = false;
	bWantsToFire = false;
	LastTakeHitTimeTimeout = 0;
}

void AMagicBattleSoccerPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (Role == ROLE_Authority)
	{
		// Reset the health count
		Health = MaxHealth;

		// Give this player their default weapons
		SpawnDefaultInventory();
	}
}

void AMagicBattleSoccerPlayer::PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);

	// Only replicate this property for a short duration after it changes so join in progress players don't get spammed with fx when joining late
	DOREPLIFETIME_ACTIVE_OVERRIDE(AMagicBattleSoccerPlayer, LastTakeHitInfo, GetWorld() && GetWorld()->GetTimeSeconds() < LastTakeHitTimeTimeout);
}

void AMagicBattleSoccerPlayer::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AMagicBattleSoccerPlayer, EnemyGoal);
	DOREPLIFETIME(AMagicBattleSoccerPlayer, SpawnPoint);
	DOREPLIFETIME(AMagicBattleSoccerPlayer, MaxHealth);
	DOREPLIFETIME(AMagicBattleSoccerPlayer, Health);
	DOREPLIFETIME(AMagicBattleSoccerPlayer, CurrentMovementSpeed);
	DOREPLIFETIME(AMagicBattleSoccerPlayer, CurrentWeapon);
}

void AMagicBattleSoccerPlayer::OnRep_CurrentWeapon(AMagicBattleSoccerWeapon* LastWeapon)
{
	SetCurrentWeapon(CurrentWeapon, LastWeapon);
}

/** Called on clients when the server changes this character's default
movement speed */
void AMagicBattleSoccerPlayer::OnRep_CurrentMovementSpeed()
{
	// Update the default movement speed of the movement component
	// with the replicated value
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	MovementComponent->MaxWalkSpeed = CurrentMovementSpeed;
}

/** play hit or death on client */
void AMagicBattleSoccerPlayer::OnRep_LastTakeHitInfo()
{
	if (LastTakeHitInfo.bKilled)
	{
		OnDeath(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
	else
	{
		PlayHit(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
}

/** This occurs when play begins for a character */
void AMagicBattleSoccerPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (ROLE_Authority == Role)
	{
		// Servers should add this character to the game mode cache
		GetGameState()->SoccerPlayers.Add(this);

		// Assign the character max walk speed to the default movement speed
		UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
		DefaultMovementSpeed = CurrentMovementSpeed = MovementComponent->MaxWalkSpeed;
	}
	else
	{
		// The server manages the game state; the player list will be replicated to us.
	}
}

void AMagicBattleSoccerPlayer::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Servers should manage ball assignments
	if (ROLE_Authority == Role)
	{
		// If the ball is overlapping us and doesn't presently have a possessor, try to assign ourselves
		// possession. This can fail if we just had possession moments ago (otherwise we could kick the ball
		// and immediately take possession again)
		if (NULL != OverlappingBall && NULL == OverlappingBall->Possessor)
		{
			OverlappingBall->SetPossessor(this);
		}
	}
}

/** This occurs when play ends */
void AMagicBattleSoccerPlayer::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::ReceiveEndPlay(EndPlayReason);

	if (ROLE_Authority == Role)
	{
		// Remove this character from the game mode cache
		GetGameState()->SoccerPlayers.Remove(this);
	}
	else
	{
		// The server manages the game state; the player list will be replicated to us.
	}
}

/** This occurs when the player is destroyed */
void AMagicBattleSoccerPlayer::Destroyed()
{
	if (ROLE_Authority != Role)
	{
		// The server manages the game state; the player list will be replicated to us.
	}
	else
	{
		if (NULL != this->SpawnPoint)
		{
			this->SpawnPoint->SpawnedPlayerBeingDestroyed(this);
		}

		if (NULL != GetGameState())
		{
			// Release the ball
			if (PossessesBall())
			{
				GetSoccerBall()->SetPossessor(NULL);
			}

			// Remove this character from the game mode cache
			GetGameState()->SoccerPlayers.Remove(this);
		}
	}

	Super::Destroyed();
	DestroyInventory();
}

void AMagicBattleSoccerPlayer::OnBeginOverlap(AActor* OtherActor)
{
	AMagicBattleSoccerBall *Ball = Cast<AMagicBattleSoccerBall>(OtherActor);
	if (NULL != Ball)
	{
		OverlappingBall = Ball;
	}
	else
	{
		/*
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
				// Destroy the projectile
				OtherActor->Destroy();

				if ((Health -= Projectile->Damage) <= 0)
				{
					Destroy();
				}
			}
		}*/
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

//////////////////////////////////////////////////////////////////////////
// Damage & death

float AMagicBattleSoccerPlayer::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	AMagicBattleSoccerPlayerController* MyPC = Cast<AMagicBattleSoccerPlayerController>(Controller);

	if (Health <= 0.f)
	{
		return 0.f;
	}

	// Modify based on game rules.
	AMagicBattleSoccerGameMode* const Game = GetWorld()->GetAuthGameMode<AMagicBattleSoccerGameMode>();
	Damage = Game ? Game->ModifyDamage(Damage, this, DamageEvent, EventInstigator, DamageCauser) : 0.f;

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		if (Health <= 0.f)
		{
			Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
		}
		else
		{
			PlayHit(ActualDamage, DamageEvent, EventInstigator ? EventInstigator->GetPawn() : NULL, DamageCauser);
		}
	}

	return ActualDamage;
}

bool AMagicBattleSoccerPlayer::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	if (IsPendingKill()								// already destroyed
		|| Role != ROLE_Authority						// not authority
		|| GetWorld()->GetAuthGameMode() == NULL
		|| GetWorld()->GetAuthGameMode()->GetMatchState() == MatchState::LeavingMap)	// level transition occurring
	{
		return false;
	}

	return true;
}

bool AMagicBattleSoccerPlayer::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = FMath::Min(0.0f, Health);

	// if this is an environmental death then refer to the previous killer so that they receive credit (knocked into lava pits, etc)
	UDamageType const* const DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
	Killer = GetDamageInstigator(Killer, *DamageType);

	AController* const KilledPlayer = (Controller != NULL) ? Controller : Cast<AController>(GetOwner());
	GetWorld()->GetAuthGameMode<AMagicBattleSoccerGameMode>()->Killed(Killer, KilledPlayer, this, DamageType);

	NetUpdateFrequency = GetDefault<AMagicBattleSoccerPlayer>()->NetUpdateFrequency;
	CharacterMovement->ForceReplicationUpdate();

	OnDeath(KillingDamage, DamageEvent, Killer ? Killer->GetPawn() : NULL, DamageCauser);
	return true;
}

void AMagicBattleSoccerPlayer::OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	bReplicateMovement = false;
	bTearOff = true;

	if (Role == ROLE_Authority)
	{
		ReplicateHit(KillingDamage, DamageEvent, PawnInstigator, DamageCauser, true);
	}

	// remove all weapons
	DestroyInventory();

	// now destroy the player
	Destroy();
}

void AMagicBattleSoccerPlayer::PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	if (Role == ROLE_Authority)
	{
		ReplicateHit(DamageTaken, DamageEvent, PawnInstigator, DamageCauser, false);
	}

	if (DamageTaken > 0.f)
	{
		ApplyDamageMomentum(DamageTaken, DamageEvent, PawnInstigator, DamageCauser);
	}

	AMagicBattleSoccerPlayerController* MyPC = Cast<AMagicBattleSoccerPlayerController>(Controller);
	/*AShooterHUD* MyHUD = MyPC ? Cast<AShooterHUD>(MyPC->GetHUD()) : NULL;
	if (MyHUD)
	{
		MyHUD->NotifyHit(DamageTaken, DamageEvent, PawnInstigator);
	}*/

	if (PawnInstigator && PawnInstigator != this && PawnInstigator->IsLocallyControlled())
	{
		AMagicBattleSoccerPlayerController* InstigatorPC = Cast<AMagicBattleSoccerPlayerController>(PawnInstigator->Controller);
		/*AShooterHUD* InstigatorHUD = InstigatorPC ? Cast<AShooterHUD>(InstigatorPC->GetHUD()) : NULL;
		if (InstigatorHUD)
		{
			InstigatorHUD->NotifyEnemyHit();
		}*/
	}
}

void AMagicBattleSoccerPlayer::ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser, bool bKilled)
{
	const float TimeoutTime = GetWorld()->GetTimeSeconds() + 0.5f;

	FDamageEvent const& LastDamageEvent = LastTakeHitInfo.GetDamageEvent();
	if ((PawnInstigator == LastTakeHitInfo.PawnInstigator.Get()) && (LastDamageEvent.DamageTypeClass == LastTakeHitInfo.DamageTypeClass) && (LastTakeHitTimeTimeout == TimeoutTime))
	{
		// same frame damage
		if (bKilled && LastTakeHitInfo.bKilled)
		{
			// Redundant death take hit, just ignore it
			return;
		}

		// otherwise, accumulate damage done this frame
		Damage += LastTakeHitInfo.ActualDamage;
	}

	LastTakeHitInfo.ActualDamage = Damage;
	LastTakeHitInfo.PawnInstigator = Cast<AMagicBattleSoccerPlayer>(PawnInstigator);
	LastTakeHitInfo.DamageCauser = DamageCauser;
	LastTakeHitInfo.SetDamageEvent(DamageEvent);
	LastTakeHitInfo.bKilled = bKilled;
	LastTakeHitInfo.EnsureReplication();

	LastTakeHitTimeTimeout = TimeoutTime;
}

//////////////////////////////////////////////////////////////////////////
// Inventory and weapons

void AMagicBattleSoccerPlayer::SetCurrentWeapon(AMagicBattleSoccerWeapon* NewWeapon, AMagicBattleSoccerWeapon* LastWeapon)
{
	AMagicBattleSoccerWeapon* LocalLastWeapon = NULL;

	if (LastWeapon != NULL)
	{
		LocalLastWeapon = LastWeapon;
	}
	else if (NewWeapon != CurrentWeapon)
	{
		LocalLastWeapon = CurrentWeapon;
	}

	// unequip previous
	if (LocalLastWeapon)
	{
		LocalLastWeapon->OnUnEquip();
	}

	CurrentWeapon = NewWeapon;

	// equip new one
	if (NewWeapon)
	{
		NewWeapon->SetOwningPawn(this);	// Make sure weapon's MyPawn is pointing back to us. During replication, we can't guarantee APawn::CurrentWeapon will rep after AWeapon::MyPawn!
		NewWeapon->OnEquip();
	}
}

void AMagicBattleSoccerPlayer::SpawnDefaultInventory()
{
	if (Role < ROLE_Authority)
	{
		return;
	}

	int32 NumWeaponClasses = DefaultInventoryClasses.Num();
	for (int32 i = 0; i < NumWeaponClasses; i++)
	{
		if (DefaultInventoryClasses[i])
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.bNoCollisionFail = true;
			AMagicBattleSoccerWeapon* NewWeapon = GetWorld()->SpawnActor<AMagicBattleSoccerWeapon>(DefaultInventoryClasses[i], SpawnInfo);
			AddWeapon(NewWeapon);
		}
	}

	// equip first weapon in inventory
	if (Inventory.Num() > 0)
	{
		EquipWeapon(Inventory[0]);
	}
}

void AMagicBattleSoccerPlayer::DestroyInventory()
{
	if (Role < ROLE_Authority)
	{
		return;
	}

	// remove all weapons from inventory and destroy them
	for (int32 i = Inventory.Num() - 1; i >= 0; i--)
	{
		AMagicBattleSoccerWeapon* Weapon = Inventory[i];
		if (Weapon)
		{
			RemoveWeapon(Weapon);
			Weapon->Destroy();
		}
	}
}

bool AMagicBattleSoccerPlayer::ServerEquipWeapon_Validate(AMagicBattleSoccerWeapon* Weapon)
{
	return true;
}

void AMagicBattleSoccerPlayer::ServerEquipWeapon_Implementation(AMagicBattleSoccerWeapon* Weapon)
{
	EquipWeapon(Weapon);
}

void AMagicBattleSoccerPlayer::AddWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon && Role == ROLE_Authority)
	{
		Weapon->OnEnterInventory(this);
		Inventory.AddUnique(Weapon);
	}
}

void AMagicBattleSoccerPlayer::RemoveWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon && Role == ROLE_Authority)
	{
		Weapon->OnLeaveInventory();
		Inventory.RemoveSingle(Weapon);
	}
}

void AMagicBattleSoccerPlayer::EquipWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon)
	{
		if (Role == ROLE_Authority)
		{
			SetCurrentWeapon(Weapon);
		}
		else
		{
			ServerEquipWeapon(Weapon);
		}
	}
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerPlayer::StartWeaponFire()
{
	if (!bWantsToFire)
	{
		bWantsToFire = true;
		if (CurrentWeapon)
		{
			CurrentWeapon->StartFire();
		}
	}
}

void AMagicBattleSoccerPlayer::StopWeaponFire()
{
	if (bWantsToFire)
	{
		bWantsToFire = false;
		if (CurrentWeapon)
		{
			CurrentWeapon->StopFire();
		}
	}
}

bool AMagicBattleSoccerPlayer::CanFire() const
{
	return IsAlive();
}

//////////////////////////////////////////////////////////////////////////
// Player attributes

/** Gets the game mode (only the authority instance should be interested in this) */
AMagicBattleSoccerGameMode* AMagicBattleSoccerPlayer::GetGameMode()
{
	return Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

/** Gets the game state (all instances should be interested in this) */
AMagicBattleSoccerGameState* AMagicBattleSoccerPlayer::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
}

/** Gets the soccer ball */
AMagicBattleSoccerBall* AMagicBattleSoccerPlayer::GetSoccerBall()
{
	return GetGameState()->SoccerBall;
}

/** Gets all the teammates of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerPlayer::GetTeammates()
{
	const TArray<AMagicBattleSoccerPlayer*>& Players = GetGameState()->SoccerPlayers;
	TArray<AMagicBattleSoccerPlayer*> Teammates;

	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Players.CreateConstIterator()); It; ++It)
	{
		// We have to test labels because when a human player is assigned their goal, the pointer to the goal may
		// not be the same as the pointer that a bot player retains although they are the same object.
		if (this != *It && (*It)->EnemyGoal->TeamNumber == EnemyGoal->TeamNumber)
		{
			Teammates.Add(*It);
		}
	}

	return Teammates;
}

/** Gets all the opponents of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerPlayer::GetOpponents()
{
	const TArray<AMagicBattleSoccerPlayer*>& Players = GetGameState()->SoccerPlayers;
	TArray<AMagicBattleSoccerPlayer*> Opponents;

	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Players.CreateConstIterator()); It; ++It)
	{
		// We have to test labels because when a human player is assigned their goal, the pointer to the goal may
		// not be the same as the pointer that a bot player retains although they are the same object.
		if (this != *It && (*It)->EnemyGoal->TeamNumber != EnemyGoal->TeamNumber)
		{
			Opponents.Add(*It);
		}
	}

	return Opponents;
}

bool AMagicBattleSoccerPlayer::IsAlive() const
{
	return Health > 0;
}

/** True if this player possesses the ball */
bool AMagicBattleSoccerPlayer::PossessesBall()
{
	AMagicBattleSoccerPlayer *Possessor = GetSoccerBall()->Possessor;
	return (this == Possessor);
}

//////////////////////////////////////////////////////////////////////////
// Player actions

/** Updates the movement speed based on conditions (ball possessor, etc) */
void AMagicBattleSoccerPlayer::UpdateMovementSpeed()
{
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	AMagicBattleSoccerBall *Ball = GetSoccerBall();

	if (Ball->Possessor == this)
	{
		CurrentMovementSpeed = DefaultMovementSpeed * 0.75f;
	}

	MovementComponent->MaxWalkSpeed = CurrentMovementSpeed;
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

/** Stops attacking */
void AMagicBattleSoccerPlayer::CeaseFire()
{
	if (IsAttacking && NULL != CurrentWeapon)
	{
		CurrentWeapon->StopFire();
		IsAttacking = false;
	}
}


//////////////////////////////////////////////////////////////////////////
// AI

/** True if the player can be pursued by AI */
bool AMagicBattleSoccerPlayer::CanBePursued()
{
	return true;
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
	// Ignore players that cannot be pursued
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
		FRotator faceRot = ((Target->GetActorLocation() + Target->GetVelocity()) - GetActorLocation()).Rotation();
		// Face the target
		SetActorRotation(faceRot);

		/*
		// Start attacking the player if we haven't already
		if (!IsAttacking)
		{
			CurrentWeapon->StartFire();
			IsAttacking = true;
		}*/
	}

}
