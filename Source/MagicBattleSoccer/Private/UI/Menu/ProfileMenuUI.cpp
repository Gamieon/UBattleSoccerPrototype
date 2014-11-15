/** ProfileMenuUI.cpp - This widget implements all of the profile menu items. 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "ProfileMenuUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"
#include "MenuItemWidgetStyle.h"
#include "MagicBattleSoccerUserSettings.h"

void SProfileMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;

	UserSettings = CastChecked<UMagicBattleSoccerUserSettings>(GEngine->GetGameUserSettings());
	PlayerName = UserSettings->PlayerName;

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FMenuItemStyle* ItemStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuItemStyle>("DefaultMenuItemStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");
	const FEditableTextBoxStyle *EditableTextBoxStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FEditableTextBoxStyle>("DefaultEditableTextBoxStyle");

	ChildSlot
	[
		// Overlay level
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Bottom)
		.Padding(FMargin(100, 0, 0, 80))
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
						// Resolution widgets
						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[							
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(STextBlock)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
								.Text(FText::FromString("NAME"))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(SEditableTextBox)
								.MinDesiredWidth(300)
								.Style(EditableTextBoxStyle)
								.Text(this, &SProfileMenuUI::GetPlayerName)
								.OnTextCommitted(this, &SProfileMenuUI::SetPlayerName)
							]
						]


						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(SButton)
								.ButtonStyle(ButtonStyle)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
								.Text(FText::FromString("SAVE"))
								.OnClicked(this, &SProfileMenuUI::OnSave)
							]
						]
						+ SVerticalBox::Slot()
						.Padding(0.0f)
						[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(SButton)
								.ButtonStyle(ButtonStyle)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
								.Text(FText::FromString("CANCEL"))
								.OnClicked(this, &SProfileMenuUI::OnCancel)
							]
						]
					]
				]
			]
		]
	];
}

FText SProfileMenuUI::GetPlayerName() const
{
	return FText::FromString(PlayerName);
}

void SProfileMenuUI::SetPlayerName(const FText& NewText, ETextCommit::Type TextType)
{
	PlayerName = NewText.ToString();
}

/** Click handler for the Save button. */
FReply SProfileMenuUI::OnSave()
{
	UserSettings->PlayerName = PlayerName;
	UserSettings->ApplySettings(false);
	MenuHUD->PopMenu();
	return FReply::Handled();
}

/** Click handler for the Cancel button. */
FReply SProfileMenuUI::OnCancel()
{
	PlayerName = UserSettings->PlayerName;
	MenuHUD->PopMenu();
	return FReply::Handled();
}
