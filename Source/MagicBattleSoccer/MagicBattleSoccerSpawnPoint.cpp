
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

/** This occurs when play begins */
/*void AMagicBattleSoccerSpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	// Gather a list of players which already have us as existing spawn points
	NumberOfPlayersOnField = 0;
	for (TActorIterator<AMagicBattleSoccerPlayer> It(GetWorld()); It; ++It)
	{
		if ((*It)->SpawnPoint == this)
		{
			NumberOfPlayersOnField++;
		}
	}

	// Spawn all the bots until we reach our limit
	// TODO: Blueprint
	// TODO: Server only
}*/

#pragma endregion