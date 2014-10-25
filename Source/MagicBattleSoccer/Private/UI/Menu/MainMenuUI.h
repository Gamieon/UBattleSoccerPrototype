/**
MainMenuUI.h - Provides an implementation of the Slate UI representing the main menu.
-------
Written by Minalien as part of a Slate UI Tutorial - http://minalien.com/
DWYW License [Do Whatever You Want]
**/

#pragma once

#include "Slate.h"

/**
* Lays out and controls the Main Menu UI for our tutorial.
**/
class SMainMenuUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SMainMenuUI)
		: _MenuHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MenuHUD);

	SLATE_END_ARGS()

public:
	/**
	* Constructs and lays out the Main Menu UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

private:
	/** Click handler for the Host button - Calls MenuHUD's HostClicked() event. */
	FReply HostClicked();

	/** Click handler for the Options button - Calls MenuHUD's OptionsClicked() event. */
	FReply OptionsClicked();

	/** Click handler for the Quit button - Calls MenuHUD's QuitClicked() event. */
	FReply QuitClicked();

	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMainMenuHUD> MenuHUD;
};