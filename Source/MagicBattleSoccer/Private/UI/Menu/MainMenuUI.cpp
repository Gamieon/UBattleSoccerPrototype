/** MainMenuUI.cpp - This widget implements all of the root level main menu items. */

#include "MagicBattleSoccer.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "OptionsMenuUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"

void SMainMenuUI::Construct(const FArguments& args)
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
						// Vertical box containing menu items
						SNew(SVerticalBox)
						+ SVerticalBox::Slot()
						.Padding(10.0f)
						[
							// Host button
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
						.Padding(10.0f)
						[
							// Options button
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
						.Padding(10.0f)
						[
							// Quit button
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
	/*
	if (ensure(GameInstance.IsValid()) && GetPlayerOwner() != NULL)
	{
		FString const StartURL = FString::Printf(TEXT("/Game/Maps/test_multiplayer"));
		FString const GameType = TEXT("");

		// TODO: Game instance needs to handle success, failure and dialogs
		GameInstance->HostGame(GetPlayerOwner(), GameType, StartURL);
	}*/
	return FReply::Handled();
}

/** Click handler for the Options button - Calls MenuHUD's OptionsClicked() event. */
FReply SMainMenuUI::OptionsClicked()
{
	// Push the Options menu onto the menu stack
	MenuHUD->PushMenu(MenuHUD->OptionsMenuUI);
	return FReply::Handled();
}

/** Click handler for the Quit button - Calls MenuHUD's QuitClicked() event. */
FReply SMainMenuUI::QuitClicked()
{
	// Quit the game
	UGameViewportClient* Viewport = GEngine->GameViewport;
	Viewport->ConsoleCommand("quit");
	return FReply::Handled();
}
