/** MagicBattleSoccerEngine.cpp - The one and only game application engine */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerEngine.h"
#include "MagicBattleSoccerInstance.h"

UMagicBattleSoccerEngine::UMagicBattleSoccerEngine(const class FObjectInitializer& OI)
	: Super(OI)
{
}

void UMagicBattleSoccerEngine::Init(IEngineLoop* InEngineLoop)
{
	// Note: Lots of important things happen in Super::Init(), including spawning the player pawn in-game and
	// creating the renderer.
	Super::Init(InEngineLoop);
}

/** Goes to the main menu */
void UMagicBattleSoccerEngine::GoToMainMenu()
{
	UMagicBattleSoccerInstance *GI = Cast<UMagicBattleSoccerInstance>(GEngine->GameViewport->GetGameInstance());
	APlayerController *Controller = GI->GetFirstLocalPlayerController();
	Controller->ConsoleCommand(TEXT("disconnect"));

	/*
	UMagicBattleSoccerInstance* const GI = Cast<UMagicBattleSoccerInstance>(GameInstance);
	FString Error;
	EBrowseReturnVal::Type BrowseRet = Browse(*GI->GetWorldContext(), TEXT("/Game/Maps/MainMenu"), Error);

	// Handle failure.
	if (BrowseRet != EBrowseReturnVal::Success)
	{
		UE_LOG(LogLoad, Fatal, TEXT("%s"), *FString::Printf(TEXT("Failed to enter %s: %s. Please check the log for errors."), TEXT("MainMenu"), *Error));
	}*/
}

/**
* Notification of network error messages, allows the engine to handle the failure
*
* @param	World associated with failure
* @param	FailureType	the type of error
* @param	NetDriverName name of the network driver generating the error
* @param	ErrorString	additional string detailing the error
*/
void UMagicBattleSoccerEngine::HandleNetworkFailure(UWorld *World, UNetDriver *NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString)
{
	Super::HandleNetworkFailure(World, NetDriver, FailureType, ErrorString);

	// Assign the error string
	LastErrorString = ErrorString;

	// We don't need to back go to the main menu; the super class will handle that
}

/**
* Notification of server travel error messages, generally network connection related (package verification, client server handshaking, etc)
* allows the engine to handle the failure
*
* @param   InWorld     the world we were in when the travel failure occurred
* @param	FailureType	the type of error
* @param	ErrorString	additional string detailing the error
*/
void UMagicBattleSoccerEngine::HandleTravelFailure(UWorld* InWorld, ETravelFailure::Type FailureType, const FString& ErrorString)
{
	Super::HandleTravelFailure(InWorld, FailureType, ErrorString);

	// Assign the error string
	LastErrorString = ErrorString;

	// We don't need to back go to the main menu; the super class will handle that
}