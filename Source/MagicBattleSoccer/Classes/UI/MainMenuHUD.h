/**
MainMenuHUD.h - The HUD class for the Main Menu map. This class contains all the SCompoundWidget objects that make up the
complete collection of menus for the Main Menu; including HOST, OPTIONS, QUIT, etc. and all of their children.
**/

#pragma once

#include "MagicBattleSoccerHUD.h"
#include "MainMenuHUD.generated.h"

/**
* Provides an implementation of the game's Main Menu HUD, which will embed and respond to events triggered
* within SMainMenuUI.
**/
UCLASS()
class AMainMenuHUD : public AMagicBattleSoccerHUD
{
	GENERATED_UCLASS_BODY()

public:
	/** The top level menu. This object contains menu items including HOST, OPTIONS, QUIT, etc. */
	TSharedPtr<class SMainMenuUI> MainMenuUI;

	/** The join menu. This object contains an interface to join a game */
	TSharedPtr<class SJoinMenuUI> JoinMenuUI;

	/** The manual join menu. This object contains an interface to join a game */
	TSharedPtr<class SManualJoinMenuUI> ManualJoinMenuUI;

	/** The profile menu. This object contains menu items including NAME, etc. */
	TSharedPtr<class SProfileMenuUI> ProfileMenuUI;

	/** The options menu. This object contains menu items including RESOLUTION, QUALITY, etc. */
	TSharedPtr<class SOptionsMenuUI> OptionsMenuUI;

public:
	/* Initializes the Slate UI and adds it as widget content to the game viewport. */
	virtual void PostInitializeComponents() override;
};