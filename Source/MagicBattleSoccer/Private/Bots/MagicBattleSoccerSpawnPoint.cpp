
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccerAIController.h"
#include "MagicBattleSoccerCharacter.h"

AMagicBattleSoccerSpawnPoint::AMagicBattleSoccerSpawnPoint(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	BotTeamNumber = 0;
	MaxPlayersOnField = 0;
}

/** Called by the GameMode object when a spawned player is about to be destroyed */
void AMagicBattleSoccerSpawnPoint::SpawnedPlayerBeingDestroyed_Implementation(AMagicBattleSoccerAIController* Controller)
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}
