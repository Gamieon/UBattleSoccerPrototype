

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerAIController.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerBall.h"
#include "Engine/TriggerBox.h"

AMagicBattleSoccerAIController::AMagicBattleSoccerAIController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bWantsPlayerState = true;
}

//////////////////////////////////////////////////////////////////////////
// AI

/** [AI] True if the player can be pursued by AI */
bool AMagicBattleSoccerAIController::CanBePursued()
{
	return true;
}

/** [AI] Clips the value n so that it will be within o+d and o-d */
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

/** [AI] If this player is in their action zone, call this function to ensure the location will not leave the zone bounds */
FVector AMagicBattleSoccerAIController::ClipToActionZone(const FVector& Location)
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

/** Gets all the teammates of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerAIController::GetTeammates()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	return GameState->GetTeammates(MyBot);
}

/** Gets all the opponents of this player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerAIController::GetOpponents()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	return GameState->GetOpponents(MyBot);
}

/** [AI] Gets the closest actor between this player and a point */
AActor* AMagicBattleSoccerAIController::GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore)
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
			, GetPawn()->GetActorLocation()
			, Point
			, ECC_Pawn
			, CollisionQueryParams
			);
		AActor* ObstructingActor = HitResult.Actor.Get(false);
		return ObstructingActor;
	}
}

/** [AI] Gets the closest enemy to this player that can be pursued */
AMagicBattleSoccerPlayer* AMagicBattleSoccerAIController::GetClosestOpponent()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	const TArray<AMagicBattleSoccerPlayer*>& Opponents = GameState->GetOpponents(MyBot);
	AMagicBattleSoccerPlayer* ClosestOpponent = NULL;
	float ClosestOpponentDistance = 0.0f;
	for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
	{
		if (NULL == ClosestOpponent || MyBot->GetDistanceTo(*It) < ClosestOpponentDistance && (*It)->CanBePursued())
		{
			ClosestOpponent = *It;
			ClosestOpponentDistance = MyBot->GetDistanceTo(*It);
		}
	}
	return ClosestOpponent;
}

/** [AI] Gets the ideal teammate to pass the soccer ball to, or NULL if there is none */
AMagicBattleSoccerPlayer* AMagicBattleSoccerAIController::GetIdealPassMate()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	const TArray<AMagicBattleSoccerPlayer*>& Teammates = GameState->GetTeammates(MyBot);
	AMagicBattleSoccerPlayer* IdealPassMate = NULL;
	float MyDistanceToGoal = MyBot->GetDistanceTo(EnemyGoal);
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
				ActorsToIgnore.Add(GameState->SoccerBall);
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

/** [AI] Gets the ideal object to run to if the player is idle */
AActor* AMagicBattleSoccerAIController::GetIdealPursuitTarget()
{
	// By default we want to pursue the soccer ball
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	AActor* PursuitTarget = GameState->SoccerBall;

	// Find out the closest obstructing actor
	TArray<AActor*> ActorsToIgnore;
	ActorsToIgnore.Add(GameState->SoccerBall);
	// Ignore players that cannot be pursued
	const TArray<AMagicBattleSoccerPlayer*>& Opponents = GameState->GetOpponents(MyBot);
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
		if (NULL != ObstructingPlayer && Opponents.Contains(ObstructingPlayer) && !ActorsToIgnore.Contains(ObstructingPlayer))
		{
			PursuitTarget = ObstructingPlayer;
		}
	}

	return PursuitTarget;
}

/** [AI] Gets the ideal point to run to when not chasing another actor while following the ball possessor */
FVector AMagicBattleSoccerAIController::GetIdealPossessorFollowLocation()
{
	AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	AMagicBattleSoccerPlayer* Possessor = GameState->SoccerBall->Possessor;
	if (nullptr == Possessor)
	{
		// The possessor could have been reset before we got to this function from an AI task blueprint.
		return GetPawn()->GetActorLocation();
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

/** [AI] Attacks a soccer player */
void AMagicBattleSoccerAIController::AttackPlayer(AMagicBattleSoccerPlayer* Target)
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (!MyBot->PossessesBall() && nullptr != MyBot->CurrentWeapon)
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

/** [AI] Stops attacking a soccer player */
UFUNCTION(BlueprintCallable, Category = Soccer)
void AMagicBattleSoccerAIController::StopAttackingPlayer()
{
	AMagicBattleSoccerPlayer* MyBot = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (IsAttacking)
	{
		MyBot->StopWeaponFire();
		IsAttacking = false;
	}
}
