/**
MainMenuHUD.cpp - The HUD class for the Main Menu map. This class contains all the SCompoundWidget objects that make up the
complete collection of menus for the Main Menu; including HOST, OPTIONS, QUIT, etc. and all of their children.
**/

#include "MagicBattleSoccer.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "OptionsMenuUI.h"
#include "MagicBattleSoccerStyles.h"

AMainMenuHUD::AMainMenuHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

void AMainMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		// We need to do this if we're in the editor.
		FMagicBattleSoccerStyles::Initialize();

		// Create the collection of top level menu items; including HOST, OPTIONS and QUIT.
		SAssignNew(MainMenuUI, SMainMenuUI)
			.MenuHUD(TWeakObjectPtr<AMainMenuHUD>(this));

		// Create the collection of option menu items including RESOLUTION and FULL SCREEN
		SAssignNew(OptionsMenuUI, SOptionsMenuUI)
			.MenuHUD(TWeakObjectPtr<AMainMenuHUD>(this));

		// Show the main menu on the screen
		PushMenu(MainMenuUI);
	}
}

/** Drills down from the current menu into the specified menu. */
void AMainMenuHUD::PushMenu(TSharedPtr<class SCompoundWidget> Menu)
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0)
	{
		Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
	
	MenuStack.Add(SNew(SWeakWidget).PossiblyNullContent(Menu));

	Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
}

/** Returns to the previous menu. */
void AMainMenuHUD::PopMenu()
{
	UGameViewportClient* Viewport = GEngine->GameViewport;

	if (MenuStack.Num() > 0)
	{
		Viewport->RemoveViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
		MenuStack.Pop();
	}

	if (MenuStack.Num() > 0)
	{
		Viewport->AddViewportWidgetContent(MenuStack[MenuStack.Num() - 1]);
	}
}
