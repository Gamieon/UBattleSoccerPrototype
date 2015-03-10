/** MagicBattleSoccerInstance.h - The one and only game application instance */

#pragma once

#include "Engine/GameInstance.h"
#include "Online.h"
#include "MagicBattleSoccerInstance.generated.h"

UCLASS()
class UMagicBattleSoccerInstance : public UGameInstance
{
	GENERATED_UCLASS_BODY()

private:
	/** URL to travel to after pending network operations */
	FString TravelURL;

private:
	/** Handle to various registered delegates */
	FDelegateHandle OnSearchSessionsCompleteDelegateHandle;
	FDelegateHandle OnCreatePresenceSessionCompleteDelegateHandle;

private:
	/** Called to show the loading screen */
	void ShowLoadingScreen();

	/** Shows the most recently retained error message in the MagicBattleSoccerEngine object with a dismiss button */
	void ShowLastEngineErrorScreen();

public:
	/** Callback which is intended to be called upon session creation */
	void OnCreatePresenceSessionComplete(FName SessionName, bool bWasSuccessful);

	/** Initiates the session searching */
	bool FindSessions(ULocalPlayer* PlayerOwner, bool bFindLAN);

	/** Called after all the local players are registered */
	void FinishSessionCreation(EOnJoinSessionCompleteResult::Type Result);

	/** Callback which is intended to be called upon finding sessions */
	void OnSearchSessionsComplete(bool bWasSuccessful);

public:
	/** Gets the game session */
	class AMagicBattleSoccerGameSession* GetGameSession() const;

	/** Called by the MainMenuUI to host a game */
	bool HostGame(ULocalPlayer* LocalPlayer, const FString& GameType, const FString& InTravelURL);
};
