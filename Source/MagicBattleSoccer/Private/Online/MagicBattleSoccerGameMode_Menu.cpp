

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode_Menu.h"
#include "MagicBattleSoccerPlayerController_Menu.h"

AMagicBattleSoccerGameMode_Menu::AMagicBattleSoccerGameMode_Menu(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	PlayerControllerClass = AMagicBattleSoccerPlayerController_Menu::StaticClass();
}

void AMagicBattleSoccerGameMode_Menu::RestartPlayer(class AController* NewPlayer)
{
	// don't restart
}
