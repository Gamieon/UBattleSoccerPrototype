
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerAIController.h"
#include "MagicBattleSoccerCharacter.h"

AMagicBattleSoccerSpawnPoint::AMagicBattleSoccerSpawnPoint(const class FObjectInitializer& OI)
	: Super(OI)
{
	OwningTeamNumber = 0;
	MaxBotsOnField = 0;
	SpawnHumanPlayers = false;
}

/** Called by the GameMode object when the next round has begun */
void AMagicBattleSoccerSpawnPoint::RoundHasStarted_Implementation()
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}

/** Called by the GameMode object when a spawned player is about to be destroyed */
void AMagicBattleSoccerSpawnPoint::SpawnedPlayerBeingDestroyed_Implementation(AMagicBattleSoccerAIController* Controller)
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}
