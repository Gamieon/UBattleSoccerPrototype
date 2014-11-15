/**
GameHUD.h - The HUD class for game maps.
**/

#include "MagicBattleSoccer.h"
#include "SoccerGameHUD.h"
#include "MagicBattleSoccerEngine.h"

ASoccerGameHUD::ASoccerGameHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

void ASoccerGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ASoccerGameHUD::DrawHUD()
{
	Super::DrawHUD();
}