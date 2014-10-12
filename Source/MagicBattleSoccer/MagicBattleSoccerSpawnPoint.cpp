
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccerPlayer.h"

AMagicBattleSoccerSpawnPoint::AMagicBattleSoccerSpawnPoint(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	EnemyGoal = NULL;
	MaxPlayersOnField = 0;
	NumberOfPlayersOnField = 0;
}

#pragma region Events

/** Called by the GameMode object when a spawned player is about to be destroyed */
void AMagicBattleSoccerSpawnPoint::SpawnedPlayerBeingDestroyed_Implementation(AMagicBattleSoccerPlayer* SoccerPlayer)
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}

#pragma endregion