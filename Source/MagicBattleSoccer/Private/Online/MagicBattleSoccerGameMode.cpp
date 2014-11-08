/**
* The GameMode defines the game being played. It governs the game rules, scoring, what actors
* are allowed to exist in this game type, and who may enter the game.
* A GameMode actor is instantiated when the level is initialized for gameplay in
* C++ UGameEngine::LoadMap().  The class of this GameMode actor is determined by
* (in order) either the URL ?game=xxx, or the
* DefaultGameMode entry in the game's .ini file (in the /Script/Engine.Engine section).
* The GameMode used can be overridden in the GameMode function GetGameModeClass(), called
* on the game class picked by the above process.
*/

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
}

/** This occurs when play ends */
void AMagicBattleSoccerGameMode::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AMagicBattleSoccerGameMode::GetGameSessionClass() const
{
	return AMagicBattleSoccerGameSession::StaticClass();
}

