/**
MagicBattleSoccerHUD.h - The base class for all other soccer HUD's. This has the capability to display a loading screen
or the most recent error message from the shooter engine class.
**/

#pragma once

#include "GameFramework/HUD.h"
#include "MagicBattleSoccerHUD.generated.h"

/**
* The root HUD from which to derive all actual HUD's to be instantiated.
**/
UCLASS()
class AMagicBattleSoccerHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	/* Initializes the Slate UI and adds it as widget content to the game viewport. */
	virtual void PostInitializeComponents() override;

	//////////////////////////////////////////////////////////////////////////
	// Drawing helpers

	/** draws a frame */
	UFUNCTION()
	void DrawFrame(FLinearColor FrameColor, float X, float Y, float Width, float Height, float Thickness);

	//////////////////////////////////////////////////////////////////////////
	// Menu helpers

protected:
	/** The current menu stack. MainMenuUI should always be at the bottom. */
	TArray<TSharedRef<class SWidget>> MenuStack;

public:
	/** Drills down from the current menu into the specified menu. */
	void PushMenu(TSharedPtr<class SCompoundWidget> Menu);

	/** Returns to the previous menu. */
	void PopMenu();

	//////////////////////////////////////////////////////////////////////////
	// System widget helpers

private:
	/** True if a loading or error prompt are visible */
	bool IsSystemPromptVisible();

public:
	/** The generic "LOADING..." text */
	TSharedPtr<class SLoadingUI> LoadingUI;
	bool bIsLoadingUIVisible;

	/** The error message confirmation box */
	TSharedPtr<class SErrorUI> ErrorUI;
	bool bIsErrorUIVisible;

public:
	/** Shows the loading screen */
	void ShowLoadingScreen();

	/** Hides the loading screen */
	void HideLoadingScreen();

	/** Shows the most recently retained error message in the MagicBattleSoccerEngine object with a dismiss button */
	void ShowLastEngineErrorScreen();

	/** Hides the error screen */
	void HideErrorScreen();
};