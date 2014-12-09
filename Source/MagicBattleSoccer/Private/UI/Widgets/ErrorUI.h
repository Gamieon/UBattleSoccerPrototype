/** MainMenuUI.h - This widget implements all of the root level main menu items. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#pragma once

#include "SlateBasics.h"

/**
* Lays out and controls the error message UI.
**/
class SErrorUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SErrorUI)
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

	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMagicBattleSoccerHUD> MenuHUD;

private:
	/** Gets the most recent engine error string */
	FString GetLastErrorString() const;

	/** Called when the user presses OK */
	FReply OnOK();
};