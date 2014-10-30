/** OptionsMenuUI.cpp - This widget implements all of the option menu items. */

#include "MagicBattleSoccer.h"
#include "MainMenuHUD.h"
#include "OptionsMenuUI.h"
#include "MagicBattleSoccerStyles.h"
#include "MenuBackgroundWidgetStyle.h"
#include "MenuItemWidgetStyle.h"
#include "MagicBattleSoccerUserSettings.h"

void SOptionsMenuUI::Construct(const FArguments& args)
{
	MenuHUD = args._MenuHUD;

	BuildResolutionList();

	UserSettings = CastChecked<UMagicBattleSoccerUserSettings>(GEngine->GetGameUserSettings());
#if PLATFORM_DESKTOP
	ResolutionOpt = UserSettings->GetScreenResolution();
	FullScreenOpt = UserSettings->GetFullscreenMode();
#endif

	const FMenuBackgroundStyle* BackgroundStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuBackgroundStyle>("DefaultMenuBackgroundStyle");
	const FMenuItemStyle* ItemStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FMenuItemStyle>("DefaultMenuItemStyle");
	const FButtonStyle* ButtonStyle = &FMagicBattleSoccerStyles::Get().GetWidgetStyle<FButtonStyle>("DefaultMenuButtonStyle");

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
								.Text(FText::FromString("RESOLUTION"))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SBorder)
								.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
								.Padding(FMargin(0, 0, 3.0f, 0))
								.OnMouseButtonDown(this, &SOptionsMenuUI::OnPrevResolution)
								[
									SNew(SOverlay)
									+ SOverlay::Slot()
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									[
										SNew(SImage)
										.Image(&ItemStyle->LeftArrowImage)
									]
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(STextBlock)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
								.Text(this, &SOptionsMenuUI::GetResolutionText)
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SBorder)
								.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
								.Padding(FMargin(0, 0, 3.0f, 0))
								.OnMouseButtonDown(this, &SOptionsMenuUI::OnNextResolution)
								[
									SNew(SOverlay)
									+ SOverlay::Slot()
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									[
										SNew(SImage)
										.Image(&ItemStyle->RightArrowImage)
									]
								]
							]
						]
						// Full Screen widgets
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
								.Text(FText::FromString("FULL SCREEN"))
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SBorder)
								.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
								.Padding(FMargin(0, 0, 3.0f, 0))
								.OnMouseButtonDown(this, &SOptionsMenuUI::OnToggleFullScreen)
								[
									SNew(SOverlay)
									+ SOverlay::Slot()
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									[
										SNew(SImage)
										.Image(&ItemStyle->LeftArrowImage)
									]
								]
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							.Padding(10.0f)
							[
								SNew(STextBlock)
								.TextStyle(FMagicBattleSoccerStyles::Get(), "MagicBattleSoccer.ButtonTextStyle")
								.Text(this, &SOptionsMenuUI::GetFullScreenText)
							]
							+ SHorizontalBox::Slot()
							.AutoWidth()
							[
								SNew(SBorder)
								.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
								.Padding(FMargin(0, 0, 3.0f, 0))
								.OnMouseButtonDown(this, &SOptionsMenuUI::OnToggleFullScreen)
								[
									SNew(SOverlay)
									+ SOverlay::Slot()
									.HAlign(HAlign_Center)
									.VAlign(VAlign_Center)
									[
										SNew(SImage)
										.Image(&ItemStyle->RightArrowImage)
									]
								]
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
								.OnClicked(this, &SOptionsMenuUI::OnSave)
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
								.OnClicked(this, &SOptionsMenuUI::OnCancel)
							]
						]
					]
				]
			]
		]
	];
}

void SOptionsMenuUI::BuildResolutionList()
{
	FDisplayMetrics DisplayMetrics;
	FSlateApplication::Get().GetInitialDisplayMetrics(DisplayMetrics);

	bool bAddedNativeResolution = false;
	const FIntPoint NativeResolution(DisplayMetrics.PrimaryDisplayWidth, DisplayMetrics.PrimaryDisplayHeight);

	for (int32 i = 0; i < DefaultResolutionCount; i++)
	{
		if (DefaultResolutions[i].X <= DisplayMetrics.PrimaryDisplayWidth && DefaultResolutions[i].Y <= DisplayMetrics.PrimaryDisplayHeight)
		{
			ResolutionList.Add(FText::Format(FText::FromString("{0}x{1}"), FText::FromString(FString::FromInt(DefaultResolutions[i].X)), FText::FromString(FString::FromInt(DefaultResolutions[i].Y))));
			Resolutions.Add(DefaultResolutions[i]);

			bAddedNativeResolution = bAddedNativeResolution || (DefaultResolutions[i] == NativeResolution);
		}
	}

	// Always make sure that the native resolution is available
	if (!bAddedNativeResolution)
	{
		ResolutionList.Add(FText::Format(FText::FromString("{0}x{1}"), FText::FromString(FString::FromInt(NativeResolution.X)), FText::FromString(FString::FromInt(NativeResolution.Y))));
		Resolutions.Add(NativeResolution);
	}
}

int32 SOptionsMenuUI::GetCurrentResolutionIndex() const
{
	int32 Result = 0; // return first valid resolution if match not found
	for (int32 i = 0; i < Resolutions.Num(); i++)
	{
		if (Resolutions[i] == ResolutionOpt)
		{
			Result = i;
			break;
		}
	}
	return Result;
}

FString SOptionsMenuUI::GetResolutionText() const
{
	return ResolutionList[GetCurrentResolutionIndex()].ToString();
}

FString SOptionsMenuUI::GetFullScreenText() const
{
	return (FullScreenOpt == EWindowMode::Windowed) ? FString("NO") : FString("YES");
}

#pragma region Button Handlers

/** Click handlers for the Resolution button. */
FReply SOptionsMenuUI::OnPrevResolution(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	int32 index = GetCurrentResolutionIndex();
	if (--index < 0)
	{
		index = Resolutions.Num() - 1;
	}
	ResolutionOpt = Resolutions[index];
	return FReply::Handled();
}

/** Click handlers for the Resolution button. */
FReply SOptionsMenuUI::OnNextResolution(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	int32 index = GetCurrentResolutionIndex();
	index = (index + 1) % Resolutions.Num();
	ResolutionOpt = Resolutions[index];
	return FReply::Handled();
}

/** Click handler for the Full Screen button. */
FReply SOptionsMenuUI::OnToggleFullScreen(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	FullScreenOpt = (FullScreenOpt == EWindowMode::Windowed) ? EWindowMode::Fullscreen : EWindowMode::Windowed;
	return FReply::Handled();
}

/** Click handler for the Save button. */
FReply SOptionsMenuUI::OnSave()
{
#if PLATFORM_DESKTOP
	UserSettings->SetScreenResolution(ResolutionOpt);
	UserSettings->SetFullscreenMode(FullScreenOpt);
#endif
	// ApplySettings also updates the resolution and full screen mode real-time
	UserSettings->ApplySettings(false);
	MenuHUD->PopMenu();
	return FReply::Handled();
}

/** Click handler for the Cancel button. */
FReply SOptionsMenuUI::OnCancel()
{
	MenuHUD->PopMenu();
	return FReply::Handled();
}

#pragma endregion