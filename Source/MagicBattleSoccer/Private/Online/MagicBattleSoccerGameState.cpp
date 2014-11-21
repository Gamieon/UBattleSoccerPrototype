/**
 * GameState is replicated and is valid on servers and clients.
 */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerInstance.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerGoal.h"
#include "UnrealNetwork.h"

AMagicBattleSoccerGameState::AMagicBattleSoccerGameState(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	SoccerBall = NULL;
	Team1Goal = NULL;
	Team2Goal = NULL;
	PenetratedGoal = NULL;
}

void AMagicBattleSoccerGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AMagicBattleSoccerGameState, SoccerPlayers);
	DOREPLIFETIME(AMagicBattleSoccerGameState, SoccerBall);
	DOREPLIFETIME(AMagicBattleSoccerGameState, Team1Goal);
	DOREPLIFETIME(AMagicBattleSoccerGameState, Team2Goal);
	DOREPLIFETIME(AMagicBattleSoccerGameState, PenetratedGoal);
}

/** Gets all the teammates of a specified player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerGameState::GetTeammates(AMagicBattleSoccerPlayer* Player)
{
	TArray<AMagicBattleSoccerPlayer*> Teammates;

	if (nullptr != Player && nullptr != Player->EnemyGoal)
	{
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if (Player != *It
				&& nullptr != (*It)->EnemyGoal
				&& (*It)->EnemyGoal->TeamNumber == Player->EnemyGoal->TeamNumber)
			{
				Teammates.Add(*It);
			}
		}
	}

	return Teammates;
}

/** Gets all the opponents of a specified player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerGameState::GetOpponents(AMagicBattleSoccerPlayer* Player)
{
	TArray<AMagicBattleSoccerPlayer*> Opponents;

	if (nullptr != Player && nullptr != Player->EnemyGoal)
	{
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if (Player != *It
				&& nullptr != (*It)->EnemyGoal
				&& (*It)->EnemyGoal->TeamNumber != Player->EnemyGoal->TeamNumber)
			{
				Opponents.Add(*It);
			}
		}
	}

	return Opponents;
}
