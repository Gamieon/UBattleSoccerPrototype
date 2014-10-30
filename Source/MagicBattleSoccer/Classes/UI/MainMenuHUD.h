/**
MainMenuHUD.h - The HUD class for the Main Menu map. This class contains all the SCompoundWidget objects that make up the
complete collection of menus for the Main Menu; including HOST, OPTIONS, QUIT, etc. and all of their children.
**/

#pragma once

#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

/**
* Provides an implementation of the game's Main Menu HUD, which will embed and respond to events triggered
* within SMainMenuUI.
**/
UCLASS()
class AMainMenuHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

private:
	/** The current menu stack. MainMenuUI should always be at the bottom. */
	TArray<TSharedRef<class SWidget>> MenuStack;

public:
	/** The top level menu. This object contains menu items including HOST, OPTIONS, QUIT, etc. */
	TSharedPtr<class SMainMenuUI> MainMenuUI;

	/** The options menu. This object contains menu times including RESOLUTION, QUALITY, etc. */
	TSharedPtr<class SOptionsMenuUI> OptionsMenuUI;

public:
	/* Initializes the Slate UI and adds it as widget content to the game viewport. */
	virtual void PostInitializeComponents() override;

	/** Drills down from the current menu into the specified menu. */
	void PushMenu(TSharedPtr<class SCompoundWidget> Menu);

	/** Returns to the previous menu. */
	void PopMenu();
};