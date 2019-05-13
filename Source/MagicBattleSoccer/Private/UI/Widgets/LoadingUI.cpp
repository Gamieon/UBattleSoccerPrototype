/** MainMenuUI.cpp - This widget implements all of the root level main menu items.
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "LoadingUI.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"

void SLoadingUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");

	ChildSlot
	[
		// Overlay level
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		.Padding(FMargin(100,0,0,80))
		[
			// Border level (fills overlay with background image)
			SNew(SBorder)
			.BorderImage(&BackgroundStyle->BackgroundBrush)
			[
				// Vertical margins (space between menu items and border) level
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(FMargin(0,15,0,15))
				[
					// Horizontal margins (space between menu items and border) level
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(FMargin(15,0,15,0))
					[
						SNew(STextBlock)
						.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
						.Text(FText::FromString("LOADING..."))
					]
				]
			]
		]

	];
}
