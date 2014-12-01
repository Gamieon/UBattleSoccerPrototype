/**
MagicBattleSoccerHUD.cpp - The base class for all shooter-specific HUD's. This has the capability to display a loading screen
or the most recent error message from the shooter engine class.
**/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerHUD.h"
#include "LoadingUI.h"
#include "ErrorUI.h"
#include "MagicBattleSoccerStyles.h"

AMagicBattleSoccerHUD::AMagicBattleSoccerHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bIsLoadingUIVisible = false;
	bIsErrorUIVisible = false;
}

void AMagicBattleSoccerHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// We need to do this if we're in the editor.
		FMagicBattleSoccerStyles::Initialize();

		// Create the loading UI
		SAssignNew(LoadingUI, SLoadingUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Create the error UI
		SAssignNew(ErrorUI, SErrorUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));
	}
}

//////////////////////////////////////////////////////////////////////////
// Drawing helpers

void AMagicBattleSoccerHUD::DrawFrame(FLinearColor FrameColor, float X, float Y, float Width, float Height, float Thickness)
{
	FCanvasLineItem NewLine;
	NewLine.SetColor(FrameColor);
	NewLine.LineThickness = Thickness;
	NewLine.BlendMode = SE_BLEND_Translucent;

	NewLine.Origin = FVector(X, Y, 0.f);
	NewLine.EndPos = FVector(X + Width, Y, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.EndPos = FVector(X, Y + Height, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.Origin = FVector(X + Width, Y + Height, 0.f);
	NewLine.EndPos = FVector(X, Y + Height, 0.f);
	Canvas->DrawItem(NewLine);

	NewLine.EndPos = FVector(X + Width, Y, 0.f);
	Canvas->DrawItem(NewLine);
}

//////////////////////////////////////////////////////////////////////////
// Menu helpers

/** Drills down from the current menu into the specified menu. */
void AMagicBattleSoccerHUD::PushMenu(TSharedPtr<class SCompoundWidget> Menu)
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
	{
		Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
	
	MenuStack.Add(SNew(SWeakWidget).PossiblyNullContent(Menu));

	if (!IsSystemPromptVisible())
	{
		Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
}

/** Returns to the previous menu. */
void AMagicBattleSoccerHUD::PopMenu()
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0)
	{
		if (!IsSystemPromptVisible())
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
		MenuStack.Pop();
	}

	if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
	{
		Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
}

//////////////////////////////////////////////////////////////////////////
// System widget helpers

/** True if a loading or error prompt are visible */
bool AMagicBattleSoccerHUD::IsSystemPromptVisible()
{
	return bIsLoadingUIVisible || bIsErrorUIVisible;
}

/** Shows the loading screen */
void AMagicBattleSoccerHUD::ShowLoadingScreen()
{
	if (IsSystemPromptVisible())
	{
		// We should not get here; but if we do, don't do anything
	}
	else
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// Hide the existing menu
		if (MenuStack.Num() > 0)
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}

		// Show the loading widget
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(LoadingUI));
		bIsLoadingUIVisible = true;
	}
}

/** Hides the loading screen */
void AMagicBattleSoccerHUD::HideLoadingScreen()
{
	if (bIsLoadingUIVisible)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;
		Viewport->RemoveAllViewportWidgets();
		bIsLoadingUIVisible = false;

		if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
		{
			Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
	}
}

/** Shows the most recently retained error message in the MagicBattleSoccerEngine object with a dismiss button */
void AMagicBattleSoccerHUD::ShowLastEngineErrorScreen()
{
	// Hide the loading screen if it's up
	HideLoadingScreen();

	if (IsSystemPromptVisible())
	{
		// We should not get here; but if we do, don't do anything
	}
	else
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// Hide the existing menu
		if (MenuStack.Num() > 0)
		{
			Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}

		// Show the error widget
		Viewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(ErrorUI));
		bIsErrorUIVisible = true;
	}
}

/** Hides the error screen */
void AMagicBattleSoccerHUD::HideErrorScreen()
{
	if (bIsErrorUIVisible)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;
		Viewport->RemoveAllViewportWidgets();
		bIsErrorUIVisible = false;

		if (MenuStack.Num() > 0 && !IsSystemPromptVisible())
		{
			Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		}
	}
}