/** MainJoinMenuUI.h - This widget implements the ability to join by IP
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#pragma once

#include "SlateBasics.h"

/**
* Lays out and controls the Options Menu UI.
**/
class SManualJoinMenuUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SManualJoinMenuUI)
		: _MenuHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMagicBattleSoccerHUD>, MenuHUD);

	SLATE_END_ARGS()

	/**
	* Constructs and lays out the Main Menu UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

private:
	/** Server IP*/
	FString ServerIP;

	/** Widget access to the server IP */
	FText GetServerIP() const;

	/** Widget access to the server IP */
	void SetServerIP(const FText& NewText, ETextCommit::Type TextType);

private:
	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMagicBattleSoccerHUD> MenuHUD;

	/** Click handler for the Join button. */
	FReply OnJoin();

	/** Click handler for the Cancel button. */
	FReply OnCancel();
};