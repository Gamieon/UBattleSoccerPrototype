/**
MainMenuPawn.cpp - The default pawn class for the main menu
**/

#include "MainMenuPawn.h"
#include "MagicBattleSoccer.h"

AMainMenuPawn::AMainMenuPawn(const class FObjectInitializer& OI)
	: Super(OI)
{
	// Prevent the player from moving around the main menu scene
	bAddDefaultMovementBindings = false;
}
