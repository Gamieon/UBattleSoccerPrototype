/**
MainMenuHUD.cpp - The HUD class for the Main Menu map. This class contains all the SCompoundWidget objects that make up the
complete collection of menus for the Main Menu; including HOST, OPTIONS, QUIT, etc. and all of their children.
**/

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerEngine.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"
#include "JoinMenuUI.h"
#include "ManualJoinMenuUI.h"
#include "ProfileMenuUI.h"
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

		// Create the collection of top level menu items; including HOST, OPTIONS and QUIT
		SAssignNew(MainMenuUI, SMainMenuUI)
			.MenuHUD(TWeakObjectPtr<AMainMenuHUD>(this));

		// Create the JOIN menu
		SAssignNew(JoinMenuUI, SJoinMenuUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Create the manual JOIN menu
		SAssignNew(ManualJoinMenuUI, SManualJoinMenuUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Create the collection of profile menu items including NAME
		SAssignNew(ProfileMenuUI, SProfileMenuUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Create the collection of option menu items including RESOLUTION and FULL SCREEN
		SAssignNew(OptionsMenuUI, SOptionsMenuUI)
			.MenuHUD(TWeakObjectPtr<AMagicBattleSoccerHUD>(this));

		// Show the main menu on the screen
		PushMenu(MainMenuUI);

		// See if the engine has an error string. If it does, it means we just came from an arbitrary scene
		// to the main menu due to an error condition. We need to present this error condition to the user.
		UMagicBattleSoccerEngine* Engine = Cast<UMagicBattleSoccerEngine>(GEngine);
		if (nullptr == Engine)
		{
			// We're probably running from the Editor
		}
		else
		{
			const FString& LastErrorString = Engine->GetLastErrorString();
			if (!LastErrorString.IsEmpty())
			{
				ShowLastEngineErrorScreen();
			}
		}
	}
}
