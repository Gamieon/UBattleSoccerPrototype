/**
MagicBattleSoccerGameMode_Menu.cpp - The game mode class for the main menu
**/

#include "MagicBattleSoccerGameMode_Menu.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerController_Menu.h"
#include "MagicBattleSoccerGameSession.h"
#include "MainMenuPawn.h"
#include "MainMenuHUD.h"

AMagicBattleSoccerGameMode_Menu::AMagicBattleSoccerGameMode_Menu(const class FObjectInitializer& OI) : Super(OI)
{
	// This game mode requires a specific player controller class that is nothing more than a APlayerController with the mouse cursor enabled.
	// Otherwise the player couldn't select any menu items.
	PlayerControllerClass = AMagicBattleSoccerPlayerController_Menu::StaticClass();

	// Make the main menu HUD appear in the presence of this game mode
	HUDClass = AMainMenuHUD::StaticClass();

	// This game mode requires a specific pawn class that is nothing more than a ADefaultPawn with movement disabled. Otherwise the player
	// could aimlessly navigate around the main menu scene.
	SpectatorClass = AMainMenuPawn::StaticClass();
}

void AMagicBattleSoccerGameMode_Menu::RestartPlayer(class AController* NewPlayer)
{
	// don't restart
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AMagicBattleSoccerGameMode_Menu::GetGameSessionClass() const
{
	return AMagicBattleSoccerGameSession::StaticClass();
}
