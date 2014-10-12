

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerAIController.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerSpawnPoint.h"

AMagicBattleSoccerGameMode::AMagicBattleSoccerGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = AMagicBattleSoccerPlayerController::StaticClass();
	SoccerBall = NULL;
	Team1Goal = NULL;
	Team2Goal = NULL;
	PenetratedGoal = NULL;
}

/** Destroys a soccer player */
void AMagicBattleSoccerGameMode::DestroySoccerPlayer(AMagicBattleSoccerPlayer *SoccerPlayer)
{
	if (NULL != SoccerPlayer->SpawnPoint)
	{
		SoccerPlayer->SpawnPoint->SpawnedPlayerBeingDestroyed(SoccerPlayer);
	}

	if (SoccerPlayer->PossessesBall())
	{
		this->SoccerBall->SetPossessor(NULL);
	}

	if (NULL != SoccerPlayer->CurrentWeapon)
	{
		SoccerPlayer->CurrentWeapon->Destroy();
	}
	
	this->SoccerPlayers.Remove(SoccerPlayer);
	SoccerPlayer->Destroy();
}

#pragma region Events

/** This occurs when play ends */
void AMagicBattleSoccerGameMode::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
	SoccerPlayers.Empty();
	SoccerBall = NULL;
	Team1Goal = NULL;
	Team2Goal = NULL;
	PenetratedGoal = NULL;
}

#pragma endregion
