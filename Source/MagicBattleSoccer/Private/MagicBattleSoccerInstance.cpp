/** MagicBattleSoccerInstance.cpp - The one and only game application instance */

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerInstance.h"
#include "MagicBattleSoccerHUD.h"
#include "MagicBattleSoccerGameSession.h"

UMagicBattleSoccerInstance::UMagicBattleSoccerInstance(const class FObjectInitializer& OI)
	: Super(OI)
{
}

/** Gets the game session */
AMagicBattleSoccerGameSession* UMagicBattleSoccerInstance::GetGameSession() const
{
	UWorld* const World = GetWorld();
	if (World)
	{
		AGameMode* const Game = World->GetAuthGameMode();
		if (Game)
		{
			return Cast<AMagicBattleSoccerGameSession>(Game->GameSession);
		}
	}

	return nullptr;
}

/** Called to show the loading screen */
void UMagicBattleSoccerInstance::ShowLoadingScreen()
{
	APlayerController *Controller = this->GetFirstLocalPlayerController();
	AMagicBattleSoccerHUD* HUD = CastChecked<AMagicBattleSoccerHUD>(Controller->GetHUD());
	HUD->ShowLoadingScreen();
}

/** Shows the most recently retained error message in the MagicBattleSoccerEngine object with a dismiss button */
void UMagicBattleSoccerInstance::ShowLastEngineErrorScreen()
{
	APlayerController *Controller = this->GetFirstLocalPlayerController();
	AMagicBattleSoccerHUD* HUD = CastChecked<AMagicBattleSoccerHUD>(Controller->GetHUD());
	HUD->ShowLastEngineErrorScreen();
}

/** Called by the MainMenuUI to host a game */
bool UMagicBattleSoccerInstance::HostGame(ULocalPlayer* LocalPlayer, const FString& GameType, const FString& InTravelURL)
{
	//
	// Always online game. No solo / practice modes right now.
	//

	AMagicBattleSoccerGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		// add callback delegate for completion
		GameSession->OnCreatePresenceSessionComplete().AddUObject(this, &UMagicBattleSoccerInstance::OnCreatePresenceSessionComplete);

		TravelURL = InTravelURL;
		bool const bIsLanMatch = false; // We don't support LAN play right now

		//determine the map name from the travelURL
		const FString & MapNameSubStr = "/Game/Maps/";
		const FString & ChoppedMapName = TravelURL.RightChop(MapNameSubStr.Len());
		const FString & MapName = ChoppedMapName.LeftChop(ChoppedMapName.Len() - ChoppedMapName.Find("?game"));

		if (GameSession->HostSession(LocalPlayer->GetPreferredUniqueNetId(), GameSessionName, GameType, MapName, bIsLanMatch, true, AMagicBattleSoccerGameSession::DEFAULT_NUM_PLAYERS))
		{
			// Go ahead and go into loading state now
			// If we fail, the delegate will handle showing the proper messaging
			ShowLoadingScreen();
			return true;
		}
	}

	return false;

}

/** Callback which is intended to be called upon session creation */
void UMagicBattleSoccerInstance::OnCreatePresenceSessionComplete(FName SessionName, bool bWasSuccessful)
{
	AMagicBattleSoccerGameSession* const GameSession = GetGameSession();
	if (GameSession)
	{
		GameSession->OnCreatePresenceSessionComplete().RemoveUObject(this, &UMagicBattleSoccerInstance::OnCreatePresenceSessionComplete);

		// Finish the session creation
		FinishSessionCreation(bWasSuccessful ? EOnJoinSessionCompleteResult::Success : EOnJoinSessionCompleteResult::UnknownError);
	}
}

/** Initiates the session searching */
bool UMagicBattleSoccerInstance::FindSessions(ULocalPlayer* PlayerOwner, bool bFindLAN)
{
	bool bResult = false;

	check(PlayerOwner != nullptr);
	if (PlayerOwner)
	{
		AMagicBattleSoccerGameSession* const GameSession = GetGameSession();
		if (GameSession)
		{
			GameSession->OnFindSessionsComplete().RemoveAll(this);
			GameSession->OnFindSessionsComplete().AddUObject(this, &UMagicBattleSoccerInstance::OnSearchSessionsComplete);

			GameSession->FindSessions(PlayerOwner->GetPreferredUniqueNetId(), GameSessionName, bFindLAN, true);

			bResult = true;
		}
	}

	return bResult;
}

/** Callback which is intended to be called upon finding sessions */
void UMagicBattleSoccerInstance::OnSearchSessionsComplete(bool bWasSuccessful)
{
	AMagicBattleSoccerGameSession* const Session = GetGameSession();
	if (Session)
	{
		Session->OnFindSessionsComplete().RemoveUObject(this, &UMagicBattleSoccerInstance::OnSearchSessionsComplete);
	}
}

void UMagicBattleSoccerInstance::FinishSessionCreation(EOnJoinSessionCompleteResult::Type Result)
{
	if (Result == EOnJoinSessionCompleteResult::Success)
	{
		// Travel to the specified match URL
		GetWorld()->ServerTravel(TravelURL);
	}
	else
	{
		// Failure
		
		// TODO

		//FString ReturnReason = NSLOCTEXT("NetworkErrors", "CreateSessionFailed", "Failed to create session.").ToString();
		//FString OKButton = NSLOCTEXT("DialogButtons", "OKAY", "OK").ToString();
		//ShowMessageThenGoMain(ReturnReason, OKButton, FString());
	}
}