/**
MagicBattleSoccerPlayerController_Menu.cpp - The player controller class for the main menu
**/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerController_Menu.h"

AMagicBattleSoccerPlayerController_Menu::AMagicBattleSoccerPlayerController_Menu(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bShowMouseCursor = true;
}

void AMagicBattleSoccerPlayerController_Menu::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}
