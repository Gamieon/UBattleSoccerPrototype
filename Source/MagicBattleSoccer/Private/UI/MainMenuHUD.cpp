/**
MainMenuHUD.cpp - The HUD class for the Main Menu map. This class contains all the SCompoundWidget objects that make up the
complete collection of menus for the Main Menu; including HOST, OPTIONS, QUIT, etc. and all of their children.
**/

#include "MagicBattleSoccer.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
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

		// Bring the top level menu items to the screen
		Viewport->AddViewportWidgetContent(
			SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef())
			);
	}
}

/** Called by SMainMenu whenever the Host button has been clicked. */
void AMainMenuHUD::HostClicked()
{

}

/** Called by SMainMenu whenever the Options button has been clicked. */
void AMainMenuHUD::OptionsClicked()
{

}

/** Called by SMainMenu whenever the Quit button has been clicked. */
void AMainMenuHUD::QuitClicked()
{

}