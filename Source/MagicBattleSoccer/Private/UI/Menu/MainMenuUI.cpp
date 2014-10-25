/**
Written by Minalien as part of a Slate UI Tutorial - http://minalien.com/
DWYW License [Do Whatever You Want]
**/

#include "MagicBattleSoccer.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"

void SMainMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		.Padding(FMargin(100,0,0,200))
		[
			SNew(SBorder)
			.BorderImage(&BackgroundStyle->BackgroundBrush)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.Padding(FMargin(0,15,0,15))
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(FMargin(15,0,15,0))
					[
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(ButtonStyle)
							.ContentPadding(FMargin(80.0, 2.0))
							.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
							.Text(FText::FromString("HOST"))
							.OnClicked(this, &SMainMenuUI::HostClicked)
						]
						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ButtonStyle(ButtonStyle)
							.ContentPadding(FMargin(80.0, 2.0))
							.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
							.Text(FText::FromString("OPTIONS"))
							.OnClicked(this, &SMainMenuUI::OptionsClicked)
						]
						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[
							SNew(SButton)
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.ContentPadding(FMargin(80.0, 2.0))
							.ButtonStyle(ButtonStyle)
							.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
							.Text(FText::FromString("QUIT"))
							.OnClicked(this, &SMainMenuUI::QuitClicked)
						]
					]
				]
			]
		]

	];
}


/** Click handler for the Host button - Calls MenuHUD's HostClicked() event. */
FReply SMainMenuUI::HostClicked()
{
	MenuHUD->HostClicked();
	return FReply::Handled();
}

/** Click handler for the Options button - Calls MenuHUD's OptionsClicked() event. */
FReply SMainMenuUI::OptionsClicked()
{
	MenuHUD->OptionsClicked();
	return FReply::Handled();
}

/** Click handler for the Quit button - Calls MenuHUD's QuitClicked() event. */
FReply SMainMenuUI::QuitClicked()
{
	MenuHUD->QuitClicked();
	return FReply::Handled();
}
