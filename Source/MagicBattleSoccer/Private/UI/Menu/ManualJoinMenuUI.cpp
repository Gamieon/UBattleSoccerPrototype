/** MainJoinMenuUI.cpp - This widget implements the ability to join by IP 
*
* For a basic tutorial on creating menus with Slate, visit http://minalien.com/unreal-engine-4-creating-menus-with-slatec-part-1/
*
*/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "ManualJoinMenuUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"
#include "MenuItemWidgetStyle.h"

void SManualJoinMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;
	ServerIP = TEXT("192.168.1.4");

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
				.Padding(FMargin(0, 15, 0, 15))
				[
					// Horizontal margins (space between menu items and border) level
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.Padding(FMargin(15, 0, 15, 0))
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
								.Text(FText::FromString("SERVER IP"))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(SEditableTextBox)
								.Style(EditableTextBoxStyle)
								.Text(this, &SManualJoinMenuUI::GetServerIP)
								.OnTextCommitted(this, &SManualJoinMenuUI::SetServerIP)
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
								.Text(FText::FromString("JOIN"))
								.OnClicked(this, &SManualJoinMenuUI::OnJoin)
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
								.OnClicked(this, &SManualJoinMenuUI::OnCancel)
							]
						]
					]
				]
			]
		]
	];

}

FText SManualJoinMenuUI::GetServerIP() const
{
	return FText::FromString(ServerIP);
}

void SManualJoinMenuUI::SetServerIP(const FText& NewText, ETextCommit::Type TextType)
{
	ServerIP = NewText.ToString();
}

/** Click handler for the Join button. */
FReply SManualJoinMenuUI::OnJoin()
{
	UMagicBattleSoccerInstance *GI = Cast<UMagicBattleSoccerInstance>(GEngine->GameViewport->GetGameInstance());
	APlayerController *Controller = GI->GetFirstLocalPlayerController();
	FString CommandString = FString::Printf(TEXT("Travel %s"), *ServerIP);
	Controller->ConsoleCommand(CommandString);
	return FReply::Handled();
}

/** Click handler for the Cancel button. */
FReply SManualJoinMenuUI::OnCancel()
{
	MenuHUD->PopMenu();
	return FReply::Handled();
}
