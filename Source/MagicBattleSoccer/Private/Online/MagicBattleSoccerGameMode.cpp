

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerGameSession.h"

AMagicBattleSoccerGameMode::AMagicBattleSoccerGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Assign the in-game player controller class
	PlayerControllerClass = AMagicBattleSoccerPlayerController::StaticClass();

	// Assign the player state class. Player-specific variables will persist during the game even if levels change
	PlayerStateClass = AMagicBattleSoccerPlayerState::StaticClass();

	SoccerBall = NULL;
	Team1Goal = NULL;
	Team2Goal = NULL;
	PenetratedGoal = NULL;
}

/** This occurs when play ends */
void AMagicBattleSoccerGameMode::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
	SoccerPlayers.Empty();
	SoccerBall = NULL;
	Team1Goal = NULL;
	Team2Goal = NULL;
	PenetratedGoal = NULL;
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AMagicBattleSoccerGameMode::GetGameSessionClass() const
{
	return AMagicBattleSoccerGameSession::StaticClass();
}

