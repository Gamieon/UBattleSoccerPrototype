/**
GameHUD.h - The HUD class for game maps.
**/

#pragma once

#include "MagicBattleSoccerHUD.h"
#include "SoccerGameHUD.generated.h"


UCLASS()
class ASoccerGameHUD : public AMagicBattleSoccerHUD
{
	GENERATED_UCLASS_BODY()

public:
	/* Initializes the Slate UI and adds it as widget content to the game viewport. */
	virtual void PostInitializeComponents() override;

protected:
	virtual void DrawHUD() override;

	void DrawAllSoccerPlayerStats();
	void DrawSoccerPlayerStats(class AMagicBattleSoccerCharacter *Player);
};