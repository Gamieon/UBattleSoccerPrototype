/** MainMenuUI.cpp - This widget implements all of the root level main menu items.
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "ErrorUI.h"
#include "MagicBattleSoccerEngine.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"

void SErrorUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");
	UMagicBattleSoccerEngine *Engine = (UMagicBattleSoccerEngine*)GEngine;

	ChildSlot
	[
		// Overlay level
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
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
					.Padding(FMargin(0, 15, 0, 15))
					.MaxWidth(800)
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.Padding(10.0f)
						.MaxHeight(600)
						[
							SNew(STextBlock)
							.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
							.Text(this, &SErrorUI::GetLastErrorString)
							.WrapTextAt(770)
						]
						+ SVerticalBox::Slot()
						.Padding(10.0f)
						[
							// OK button
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(ButtonStyle)
							.ContentPadding(FMargin(80.0, 2.0))
							.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
							.Text(FText::FromString("OK"))
							.OnClicked(this, &SErrorUI::OnOK)
						]
					]
				]
			]
		]
	];
}

/** Gets the most recent engine error string */
FString SErrorUI::GetLastErrorString() const
{
	return Cast<UMagicBattleSoccerEngine>(GEngine)->GetLastErrorString();
}

/** Called when the user presses OK */
FReply SErrorUI::OnOK()
{
	Cast<UMagicBattleSoccerEngine>(GEngine)->ClearLastErrorString();
	MenuHUD->HideErrorScreen();
	return FReply::Handled();
}