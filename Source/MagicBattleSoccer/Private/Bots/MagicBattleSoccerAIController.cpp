

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerAIController.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerBall.h"
#include "Engine/TriggerBox.h"

AMagicBattleSoccerAIController::AMagicBattleSoccerAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bWantsPlayerState = true;
	IsAttacking = false;
}

//////////////////////////////////////////////////////////////////////////
// AI

/** True if the player can be pursued by AI */
bool AMagicBattleSoccerAIController::CanBePursued()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return false;
	}
	else
	{
		AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(GetWorld()->GetAuthGameMode());
		return GameMode->CanBePursued(MyBot);
	}
}

/** The goal we want to kick the ball into */
AMagicBattleSoccerGoal* AMagicBattleSoccerAIController::GetEnemyGoal()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayerState* Player = Cast<AMagicBattleSoccerPlayerState>(PlayerState);
	if (nullptr == Player)
	{
		return nullptr;
	}
	else switch (Player->GetTeamNum())
	{
	case 1:
		return GameState->Team2Goal;
	case 2:
		return GameState->Team1Goal;
	default:
		return nullptr;
	}
}

/** Clips the value n so that it will be within o+d and o-d */
void AMagicBattleSoccerAIController::ClipAxe(float& n, float o, float d)
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
FVector AMagicBattleSoccerAIController::ClipToActionZone(const FVector& Location)
{
	FVector ClippedPoint = Location;
	if (nullptr != ActionZone)
	{
		FVector BoxOrigin, BoxExtent;
		ActionZone->GetActorBounds(false, BoxOrigin, BoxExtent);

		// Clipping is easy since the action box is always aligned with the major axes.
		ClipAxe(ClippedPoint.X, BoxOrigin.X, BoxExtent.X);
		ClipAxe(ClippedPoint.Y, BoxOrigin.Y, BoxExtent.Y);
	}
	return ClippedPoint;
}

/** Gets all the teammates of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerAIController::GetTeammates()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return TArray<AMagicBattleSoccerPlayer*>();
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		return GameState->GetTeammates(Cast<AMagicBattleSoccerPlayerState>(PlayerState));
	}
}

/** Gets all the opponents of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerAIController::GetOpponents()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return TArray<AMagicBattleSoccerPlayer*>();
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		return GameState->GetOpponents(Cast<AMagicBattleSoccerPlayerState>(PlayerState));
	}
}

/** Gets the closest actor between this player and a point */
AActor* AMagicBattleSoccerAIController::GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore)
{
	if (nullptr == GetPawn())
	{
		return nullptr;
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
			, GetPawn()->GetActorLocation()
			, Point
			, ECC_Pawn
			, CollisionQueryParams
			);
		AActor* ObstructingActor = HitResult.Actor.Get(false);
		return ObstructingActor;
	}
}

/** Gets the closest enemy to this player that can be pursued */
AMagicBattleSoccerPlayer* AMagicBattleSoccerAIController::GetClosestOpponent()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return nullptr;
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		return GameState->GetClosestOpponent(MyBot);
	}
}

/** Gets the ideal teammate to pass the soccer ball to, or NULL if there is none */
AMagicBattleSoccerPlayer* AMagicBattleSoccerAIController::GetIdealPassMate()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return nullptr;
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		const TArray<AMagicBattleSoccerPlayer*>& Teammates = GameState->GetTeammates(Cast<AMagicBattleSoccerPlayerState>(PlayerState));
		AMagicBattleSoccerGoal* EnemyGoal = GetEnemyGoal();
		float MyDistanceToGoal = MyBot->GetDistanceTo(EnemyGoal);
		AMagicBattleSoccerPlayer* IdealPassMate = NULL;

		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Teammates.CreateConstIterator()); It; ++It)
		{
			float DistanceToGoal = (*It)->GetDistanceTo(EnemyGoal);
			float DistanceToSelf = MyBot->GetDistanceTo(*It);

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
				AMagicBattleSoccerPlayer *ClosestOpponent = GameState->GetClosestOpponent(*It);
				if (NULL != ClosestOpponent && ClosestOpponent->GetDistanceTo(*It) < 300)
				{
					continue;
				}
				else
				{
					// Skip this teammate if there's something in between us and them
					TArray<AActor*> ActorsToIgnore;
					ActorsToIgnore.Add(*It);
					ActorsToIgnore.Add(GameState->SoccerBall);
					ActorsToIgnore.Add(MyBot);
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
}

/** Gets the ideal object to run to if the player is idle */
AActor* AMagicBattleSoccerAIController::GetIdealPursuitTarget()
{
	// By default we want to pursue the soccer ball
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == MyBot)
	{
		return nullptr;
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(GetWorld()->GetAuthGameMode());
		AActor* PursuitTarget = GameState->SoccerBall;

		// Find out the closest obstructing actor
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(GameState->SoccerBall);
		ActorsToIgnore.Add(MyBot);
		// Ignore players that cannot be pursued
		const TArray<AMagicBattleSoccerPlayer*>& Opponents = GameState->GetOpponents(Cast<AMagicBattleSoccerPlayerState>(PlayerState));
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
		{
			AMagicBattleSoccerPlayer *Player = *It;
			if (!GameMode->CanBePursued(Player))
			{
				ActorsToIgnore.Add(*It);
			}
		}

		AActor* ObstructingActor = GetClosestActorObstructingPoint(PursuitTarget->GetActorLocation(), ActorsToIgnore);
		if (nullptr != ObstructingActor)
		{
			// If the obstructing actor is an opponent, then pursue them
			AMagicBattleSoccerPlayer *ObstructingPlayer = Cast<AMagicBattleSoccerPlayer>(ObstructingActor);
			if (nullptr != ObstructingPlayer && Opponents.Contains(ObstructingPlayer) && !ActorsToIgnore.Contains(ObstructingPlayer))
			{
				PursuitTarget = ObstructingPlayer;
			}
		}

		return PursuitTarget;
	}
}

/** Gets the ideal point to run to when not chasing another actor while following the ball possessor */
FVector AMagicBattleSoccerAIController::GetIdealPossessorFollowLocation()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerGoal* EnemyGoal = GetEnemyGoal();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	AMagicBattleSoccerPlayer* Possessor = GameState->SoccerBall->Possessor;
	if (nullptr == MyBot)
	{
		return FVector::ZeroVector;
	}
	else if (nullptr == Possessor)
	{
		// The possessor could have been reset before we got to this function from an AI task blueprint.
		return MyBot->GetActorLocation();
	}
	else if (nullptr == EnemyGoal)
	{
		// This should never happen; but if it did, just run to the possessor
		return Possessor->GetActorLocation();
	}
	else
	{
		FVector MyLocation = GetPawn()->GetActorLocation();
		FVector NewLocation = FVector(
			MyLocation.X,
			(Possessor->GetActorLocation().Y + EnemyGoal->GetIdealRunLocation(MyBot).Y) * 0.5f,
			MyLocation.Z
			);
		return NewLocation;
	}
}

/** Attacks a soccer player */
void AMagicBattleSoccerAIController::AttackPlayer(AMagicBattleSoccerPlayer* Target)
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != MyBot 
		&& nullptr != Target
		&& nullptr != MyBot->CurrentWeapon
		&& !MyBot->PossessesBall() 
		)
	{
		FRotator faceRot = ((Target->GetActorLocation() + Target->GetVelocity()) - MyBot->GetActorLocation()).Rotation();
		// Face the target
		MyBot->SetActorRotation(faceRot);

		// Start attacking the player if we haven't already
		if (!IsAttacking)
		{
			MyBot->StartWeaponFire();
			IsAttacking = true;
		}
	}
}

/** Stops attacking a soccer player */
UFUNCTION(BlueprintCallable, Category = Soccer)
void AMagicBattleSoccerAIController::StopAttackingPlayer()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != MyBot)
	{
		if (IsAttacking)
		{
			MyBot->StopWeaponFire();
			IsAttacking = false;
		}
	}
}

/** Tries to kick ball into the goal. Returns true if the ball was kicked. */
bool AMagicBattleSoccerAIController::KickBallToGoal()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerGoal* EnemyGoal = GetEnemyGoal();

	if (nullptr == MyBot)
	{
		return false;
	}
	else if (nullptr == EnemyGoal)
	{
		return false;
	}
	else if (MyBot != GameState->SoccerBall->Possessor)
	{
		return false;
	}
	else if (MyBot->GetDistanceTo(EnemyGoal) > 1500.0f)
	{
		return false;
	}
	else
	{
		TArray<AActor*> ActorsToIgnore;
		ActorsToIgnore.Add(EnemyGoal);
		ActorsToIgnore.Add(GameState->SoccerBall);
		ActorsToIgnore.Add(MyBot);
		if (NULL != GetClosestActorObstructingPoint(EnemyGoal->GetActorLocation() + FVector(0, 0, 100), ActorsToIgnore))
		{
			return false;
		}
		else
		{
			KickBallToLocation(EnemyGoal->GetActorLocation());
			return true;
		}
	}
}


/** [local] Kicks the ball to the specified location */
void AMagicBattleSoccerAIController::KickBallToLocation(const FVector& Location)
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	if (nullptr != MyBot)
	{
		AMagicBattleSoccerBall *Ball = GameState->SoccerBall;
		FVector BallLocation = Ball->GetActorLocation();
		const float KickForce = 60.0f;
		MyBot->KickBall(FVector(Location.X - BallLocation.X, Location.Y - BallLocation.Y, 0.0f) * KickForce);
	}
}
