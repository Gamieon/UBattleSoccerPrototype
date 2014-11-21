/**
 * GameState is replicated and is valid on servers and clients.
 */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerInstance.h"
#include "MagicBattleSoccerPlayerState.h"
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
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerGameState::GetTeammates(AMagicBattleSoccerPlayerState* PlayerState)
{
	TArray<AMagicBattleSoccerPlayer*> Teammates;
	if (nullptr != PlayerState)
	{
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if ((*It)->PlayerState != PlayerState
				&& nullptr != Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)
				&& Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)->GetTeamNum() == PlayerState->GetTeamNum())
			{
				Teammates.Add(*It);
			}
		}
	}
	return Teammates;
}

/** Gets all the opponents of a specified player */
TArray<AMagicBattleSoccerPlayer*> AMagicBattleSoccerGameState::GetOpponents(AMagicBattleSoccerPlayerState* PlayerState)
{
	TArray<AMagicBattleSoccerPlayer*> Opponents;
	if (nullptr != PlayerState)
	{
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(SoccerPlayers.CreateConstIterator()); It; ++It)
		{
			if ((*It)->PlayerState != PlayerState
				&& nullptr != Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)
				&& Cast<AMagicBattleSoccerPlayerState>((*It)->PlayerState)->GetTeamNum() != PlayerState->GetTeamNum())
			{
				Opponents.Add(*It);
			}
		}
	}
	return Opponents;
}

/** Gets the closest enemy to this player that can be pursued */
AMagicBattleSoccerPlayer* AMagicBattleSoccerGameState::GetClosestOpponent(AMagicBattleSoccerPlayer* Player)
{
	if (nullptr == Player)
	{
		return nullptr;
	}
	else
	{
		const TArray<AMagicBattleSoccerPlayer*>& Opponents = GetOpponents(Cast<AMagicBattleSoccerPlayerState>(Player->PlayerState));
		AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(GetWorld()->GetAuthGameMode());
		AMagicBattleSoccerPlayer* ClosestOpponent = nullptr;

		float ClosestOpponentDistance = 0.0f;
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
		{
			if (nullptr == ClosestOpponent || Player->GetDistanceTo(*It) < ClosestOpponentDistance && GameMode->CanBePursued(*It))
			{
				ClosestOpponent = *It;
				ClosestOpponentDistance = Player->GetDistanceTo(*It);
			}
		}
		return ClosestOpponent;
	}
}
