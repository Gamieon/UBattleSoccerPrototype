#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameSession.h"
#include "MagicBattleSoccerOnlineGameSettings.h"

namespace
{
	const FString CustomMatchKeyword("Custom");
}

AMagicBattleSoccerGameSession::AMagicBattleSoccerGameSession(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &AMagicBattleSoccerGameSession::OnCreateSessionComplete);
		OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &AMagicBattleSoccerGameSession::OnDestroySessionComplete);
	}
}

/**
* Delegate fired when a session create request has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMagicBattleSoccerGameSession::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	UE_LOG(LogOnlineGame, Verbose, TEXT("OnCreateSessionComplete %s bSuccess: %d"), *SessionName.ToString(), bWasSuccessful);

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		Sessions->ClearOnCreateSessionCompleteDelegate(OnCreateSessionCompleteDelegate);
	}

	OnCreatePresenceSessionComplete().Broadcast(SessionName, bWasSuccessful);

	if (!bWasSuccessful)
	{
		DelayedSessionDelete();
	}
}

/**
* Delegate fired when a destroying an online session has completed
*
* @param SessionName the name of the session this callback is for
* @param bWasSuccessful true if the async action completed without error, false if there was an error
*/
void AMagicBattleSoccerGameSession::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	UE_LOG(LogOnlineGame, Verbose, TEXT("OnDestroySessionComplete %s bSuccess: %d"), *SessionName.ToString(), bWasSuccessful);

	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		Sessions->ClearOnDestroySessionCompleteDelegate(OnDestroySessionCompleteDelegate);
		HostSettings = NULL;
	}
}

/** Safe delete mechanism to make sure we aren't deleting a session too soon after its creation */
void AMagicBattleSoccerGameSession::DelayedSessionDelete()
{
	IOnlineSubsystem* OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		EOnlineSessionState::Type SessionState = Sessions->GetSessionState(CurrentSessionParams.SessionName);
		if (SessionState != EOnlineSessionState::Creating)
		{
			Sessions->AddOnDestroySessionCompleteDelegate(OnDestroySessionCompleteDelegate);
			if (!Sessions->DestroySession(CurrentSessionParams.SessionName))
			{
				Sessions->ClearOnDestroySessionCompleteDelegate(OnDestroySessionCompleteDelegate);
			}
		}
		else
		{
			// Retry shortly
			GetWorldTimerManager().SetTimer(this, &AMagicBattleSoccerGameSession::DelayedSessionDelete, 1.f);
		}
	}
}

/** Host a new online session */
bool AMagicBattleSoccerGameSession::HostSession(TSharedPtr<FUniqueNetId> UserId, FName SessionName, const FString & GameType, const FString & MapName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers)
{
	IOnlineSubsystem* const OnlineSub = IOnlineSubsystem::Get();
	if (OnlineSub)
	{
		CurrentSessionParams.SessionName = SessionName;
		CurrentSessionParams.bIsLAN = bIsLAN;
		CurrentSessionParams.bIsPresence = bIsPresence;
		CurrentSessionParams.UserId = UserId;
		MaxPlayers = MaxNumPlayers;

		IOnlineSessionPtr Sessions = OnlineSub->GetSessionInterface();
		if (Sessions.IsValid() && CurrentSessionParams.UserId.IsValid())
		{
			HostSettings = MakeShareable(new FMagicBattleSoccerOnlineSessionSettings(bIsLAN, bIsPresence, MaxPlayers));
			HostSettings->Set(SETTING_GAMEMODE, GameType, EOnlineDataAdvertisementType::ViaOnlineService);
			HostSettings->Set(SETTING_MAPNAME, MapName, EOnlineDataAdvertisementType::ViaOnlineService);
			HostSettings->Set(SETTING_MATCHING_HOPPER, FString("TeamDeathmatch"), EOnlineDataAdvertisementType::DontAdvertise);
			HostSettings->Set(SETTING_MATCHING_TIMEOUT, 120.0f, EOnlineDataAdvertisementType::ViaOnlineService);
			HostSettings->Set(SETTING_SESSION_TEMPLATE_NAME, FString("GameSession"), EOnlineDataAdvertisementType::DontAdvertise);
			HostSettings->Set(SEARCH_KEYWORDS, CustomMatchKeyword, EOnlineDataAdvertisementType::ViaOnlineService);

			Sessions->AddOnCreateSessionCompleteDelegate(OnCreateSessionCompleteDelegate);
			return Sessions->CreateSession(*CurrentSessionParams.UserId, CurrentSessionParams.SessionName, *HostSettings);
		}
	}
#if !UE_BUILD_SHIPPING
	else
	{
		// Hack workflow in development
		OnCreatePresenceSessionComplete().Broadcast(GameSessionName, true);
		return true;
	}
#endif

	return false;
}