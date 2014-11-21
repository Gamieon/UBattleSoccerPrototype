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
	void DrawRect(float X, float Y, float Width, float Height, const FLinearColor& Color);
	void DrawRectFrame(float X, float Y, float Width, float Height, float Thickness, const FLinearColor& Color);
	void DrawString(
		UFont* TheFont,
		const FString& TheStr,
		float X, float Y,
		const FLinearColor& TheColor,
		float TheScale,
		bool DrawOutline = false,
		const FLinearColor& OutlineColor = FLinearColor(0, 0, 0, 1)
		);

protected:
	virtual void DrawHUD() override;

	void DrawAllSoccerPlayerStats();
	void DrawSoccerPlayerStats(class AMagicBattleSoccerPlayer *Player);
};