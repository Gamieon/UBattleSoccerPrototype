/** ProfileMenuUI.h - This widget implements all of the profile menu items. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#pragma once

#include "SlateBasics.h"

/**
* Lays out and controls the Options Menu UI.
**/
class SProfileMenuUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SProfileMenuUI)
		: _MenuHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMagicBattleSoccerHUD>, MenuHUD);

	SLATE_END_ARGS()

public:
	/**
	* Constructs and lays out the Main Menu UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

private:
	/** Player name */
	FString PlayerName;

	/** Widget access to the player name */
	FText GetPlayerName() const;

	/** Widget access to the player name */
	void SetPlayerName(const FText& NewText, ETextCommit::Type TextType);

private:
	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMagicBattleSoccerHUD> MenuHUD;

	/** User settings pointer */
	class UMagicBattleSoccerUserSettings* UserSettings;

	/** Click handler for the Save button. */
	FReply OnSave();

	/** Click handler for the Cancel button. */
	FReply OnCancel();
};