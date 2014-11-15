/**
 * GameState is replicated and is valid on servers and clients.
 */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerInstance.h"
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
