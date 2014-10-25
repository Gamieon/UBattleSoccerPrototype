/**
MagicBattleSoccerPlayerController_Menu.h - The player controller class for the main menu
**/

#pragma once

#include "GameFramework/PlayerController.h"
#include "MagicBattleSoccerPlayerController_Menu.generated.h"

/**
 * 
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerPlayerController_Menu : public APlayerController
{
	GENERATED_UCLASS_BODY()

	/** After game is initialized */
	virtual void PostInitializeComponents() override;
};
