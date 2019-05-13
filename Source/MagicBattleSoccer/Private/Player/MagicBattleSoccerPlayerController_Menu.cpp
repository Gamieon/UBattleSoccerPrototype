/**
MagicBattleSoccerPlayerController_Menu.cpp - The player controller class for the main menu
**/

#include "MagicBattleSoccerPlayerController_Menu.h"
#include "MagicBattleSoccer.h"

AMagicBattleSoccerPlayerController_Menu::AMagicBattleSoccerPlayerController_Menu(const class FObjectInitializer& OI)
	: Super(OI)
{
	bShowMouseCursor = true;
}

void AMagicBattleSoccerPlayerController_Menu::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
