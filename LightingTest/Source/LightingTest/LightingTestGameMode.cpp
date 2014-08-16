

#include "LightingTest.h"
#include "LightingTestGameMode.h"
#include "LightingTestPlayerController.h"

ALightingTestGameMode::ALightingTestGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = ALightingTestPlayerController::StaticClass();
}


