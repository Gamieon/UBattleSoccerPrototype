/** OptionsMenuUI.h - This widget implements all of the option menu items. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#pragma once

#include "Slate.h"

/** supported resolutions */
const FIntPoint DefaultResolutions[] = { FIntPoint(1024, 768), FIntPoint(1280, 720), FIntPoint(1920, 1080) };

/** supported resolutions count*/
const int32 DefaultResolutionCount = ARRAY_COUNT(DefaultResolutions);

/**
* Lays out and controls the Options Menu UI.
**/
class SOptionsMenuUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SOptionsMenuUI)
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
	void BuildResolutionList();

	int32 GetCurrentResolutionIndex() const;

	FString GetResolutionText() const;
	FString GetFullScreenText() const;

private:
	/** Click handlers for the Resolution button. */
	FReply OnPrevResolution(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);
	FReply OnNextResolution(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	/** Click handler for the Full Screen button. */
	FReply OnToggleFullScreen(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

	/** Click handler for the Save button. */
	FReply OnSave();

	/** Click handler for the Cancel button. */
	FReply OnCancel();

private:
	/**
	* Stores a weak reference to the HUD controlling this class.
	**/
	TWeakObjectPtr<class AMagicBattleSoccerHUD> MenuHUD;

	/** User settings pointer */
	class UMagicBattleSoccerUserSettings* UserSettings;

#if PLATFORM_DESKTOP
	/** resolution setting set in options */
	FIntPoint ResolutionOpt;

	/** full screen setting set in options */
	EWindowMode::Type FullScreenOpt;
#endif

	/**
	* Contains the list of all supported resolutions
	**/
	TArray<FText> ResolutionList;

	/** available resolutions list */
	TArray<FIntPoint> Resolutions;
};