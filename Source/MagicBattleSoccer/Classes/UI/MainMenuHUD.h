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

public:
	/* Initializes the Slate UI and adds it as widget content to the game viewport. */
	virtual void PostInitializeComponents() override;

	/** Called by SMainMenu whenever the Host button has been clicked. */
	void HostClicked();

	/** Called by SMainMenu whenever the Options button has been clicked. */
	void OptionsClicked();

	/** Called by SMainMenu whenever the Quit Game button has been clicked. */
	void QuitClicked();

private:
	/** The top level menu. This object contains menu items including HOST, OPTIONS, QUIT, etc.  */
	TSharedPtr<class SMainMenuUI> MainMenuUI;
};