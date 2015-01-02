/**
 * GameState is replicated and is valid on servers and clients.
 */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerInstance.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "UnrealNetwork.h"

AMagicBattleSoccerGameState::AMagicBattleSoccerGameState(const class FObjectInitializer& OI)
	: Super(OI)
{
	SoccerBall = nullptr;
	Team1Goal = nullptr;
	Team2Goal = nullptr;
	Team1SoccerBallSpawnPoint = nullptr;
	Team2SoccerBallSpawnPoint = nullptr;
	PenetratedGoal = nullptr;
	RoundInProgress = false;
}

void AMagicBattleSoccerGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AMagicBattleSoccerGameState, SoccerPlayers);
	DOREPLIFETIME(AMagicBattleSoccerGameState, SoccerBall);
	DOREPLIFETIME(AMagicBattleSoccerGameState, PenetratedGoal);
	DOREPLIFETIME(AMagicBattleSoccerGameState, RoundInProgress);
}

/** Gets all the teammate controllers of a specified player */
TArray<AController*> AMagicBattleSoccerGameState::GetTeammateControllers(class AMagicBattleSoccerPlayerState* PlayerState)
{
	TArray<AController*> Teammates;
	if (nullptr != PlayerState)
	{
		for (TObjectIterator<AController> Itr; Itr; ++Itr)
		{
			if ((*Itr)->PlayerState != PlayerState
				&& nullptr != Cast<AMagicBattleSoccerPlayerState>((*Itr)->PlayerState)
				&& Cast<AMagicBattleSoccerPlayerState>((*Itr)->PlayerState)->TeamNumber == PlayerState->TeamNumber)
			{
				Teammates.Add(*Itr);
			}
		}
	}
	return Teammates;
}

/** Gets all the teammates of a specified player */
TArray<AMagicBattleSoccerCharacter*> AMagicBattleSoccerGameState::GetTeammates(AMagicBattleSoccerPlayerState* PlayerState)
{
	TArray<AMagicBattleSoccerCharacter*> Teammates;
	if (nullptr != PlayerState)
	{
		for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if ((*It)->PlayerState != PlayerState
				&& nullptr != Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)
				&& Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)->TeamNumber == PlayerState->TeamNumber)
			{
				Teammates.Add(*It);
			}
		}
	}
	return Teammates;
}

/** Gets all the opponents of a specified player */
TArray<AMagicBattleSoccerCharacter*> AMagicBattleSoccerGameState::GetOpponents(AMagicBattleSoccerPlayerState* PlayerState)
{
	TArray<AMagicBattleSoccerCharacter*> Opponents;
	if (nullptr != PlayerState)
	{
		for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if ((*It)->PlayerState != PlayerState
				&& nullptr != Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)
				&& Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)->TeamNumber != PlayerState->TeamNumber)
			{
				Opponents.Add(*It);
			}
		}
	}
	return Opponents;
}

/** Gets the closest enemy to this player that can be pursued */
AMagicBattleSoccerCharacter* AMagicBattleSoccerGameState::GetClosestOpponent(AMagicBattleSoccerCharacter* Player)
{
	if (nullptr == Player)
	{
		return nullptr;
	}
	else
	{
		return GetClosestOpponentToLocation(Player, Player->GetActorLocation());
	}
}

/** Gets the closest enemy to a world location that can be pursued */
AMagicBattleSoccerCharacter* AMagicBattleSoccerGameState::GetClosestOpponentToLocation(AMagicBattleSoccerCharacter* Player, FVector Location)
{
	const TArray<AMagicBattleSoccerCharacter*>& Opponents = GetOpponents(Cast<AMagicBattleSoccerPlayerState>(Player->PlayerState));
	AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(GetWorld()->GetAuthGameMode());
	AMagicBattleSoccerCharacter* ClosestOpponent = nullptr;

	float ClosestOpponentDistance = 0.0f;
	for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
	{
		float d = FVector::DistSquared((*It)->GetActorLocation(), Location);
		if (nullptr == ClosestOpponent || d < ClosestOpponentDistance && GameMode->CanBePursued(*It))
		{
			ClosestOpponent = *It;
			ClosestOpponentDistance = d;
		}
	}
	return ClosestOpponent;
}

/** Called when the state transitions to WaitingToStart */
void AMagicBattleSoccerGameState::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();

	// Ensure the goal and spawn points are populated
	EnsureGameStateActors();
}

/** Called when the state transitions to InProgress */
void AMagicBattleSoccerGameState::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	// Ensure the goal and spawn points are populated
	EnsureGameStateActors();
}

/** Populates the goals and ball spawn point members with values */
void AMagicBattleSoccerGameState::EnsureGameStateActors()
{
	for (TObjectIterator<AMagicBattleSoccerGoal> Itr; Itr; ++Itr)
	{
		if ((*Itr)->TeamNumber == 1)
		{
			Team1Goal = *Itr;
		}
		else if ((*Itr)->TeamNumber == 2)
		{
			Team2Goal = *Itr;
		}
	}

	for (TObjectIterator<AMagicBattleSoccerSpawnPoint> Itr; Itr; ++Itr)
	{
		if (1 == (*Itr)->OwningTeamNumber && (*Itr)->SpawnSoccerBalls)
		{
			Team1SoccerBallSpawnPoint = *Itr;
		}
		else if (2 == (*Itr)->OwningTeamNumber && (*Itr)->SpawnSoccerBalls)
		{
			Team2SoccerBallSpawnPoint = *Itr;
		}
	}
}