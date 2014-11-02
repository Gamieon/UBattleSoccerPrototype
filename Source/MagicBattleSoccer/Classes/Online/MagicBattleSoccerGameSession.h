#pragma once

#include "GameFramework/GameSession.h"
#include "Online.h"
#include "MagicBattleSoccerGameSession.generated.h"

struct FMagicBattleSoccerSessionParams
{
	/** Name of session settings are stored with */
	FName SessionName;
	/** LAN Match */
	bool bIsLAN;
	/** Presence enabled session */
	bool bIsPresence;
	/** Id of player initiating lobby */
	TSharedPtr<FUniqueNetId> UserId;
	/** Current search result choice to join */
	int32 BestSessionIdx;

	FMagicBattleSoccerSessionParams()
		: SessionName(NAME_None)
		, bIsLAN(false)
		, bIsPresence(false)
		, BestSessionIdx(0)
	{
	}
};

UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGameSession : public AGameSession
{
	GENERATED_UCLASS_BODY()

protected:
	/** Delegate for creating a new session */
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/** Delegate for destroying a session */
	FOnDestroySessionCompleteDelegate OnDestroySessionCompleteDelegate;

	/** Transient properties of a session during game creation/matchmaking */
	FMagicBattleSoccerSessionParams CurrentSessionParams;
	/** Current host settings */
	TSharedPtr<class FMagicBattleSoccerOnlineSessionSettings> HostSettings;

	/**
	* Delegate fired when a session create request has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	/**
	* Delegate fired when a destroying an online session has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	/**
	* Safe delete mechanism to make sure we aren't deleting a session too soon after its creation
	*/
	void DelayedSessionDelete();

	/*
	* Event triggered when a presence session is created
	*
	* @param SessionName name of session that was created
	* @param bWasSuccessful was the create successful
	*/
	DECLARE_EVENT_TwoParams(AMagicBattleSoccerGameSession, FOnCreatePresenceSessionComplete, FName /*SessionName*/, bool /*bWasSuccessful*/);
	FOnCreatePresenceSessionComplete CreatePresenceSessionCompleteEvent;

public:
	/** Default number of players allowed in a game */
	static const int32 DEFAULT_NUM_PLAYERS = 8;

	/**
	* Host a new online session
	*
	* @param UserId user that initiated the request
	* @param SessionName name of session
	* @param bIsLAN is this going to hosted over LAN
	* @param bIsPresence is the session to create a presence session
	* @param MaxNumPlayers Maximum number of players to allow in the session
	*
	* @return bool true if successful, false otherwise
	*/
	bool HostSession(TSharedPtr<FUniqueNetId> UserId, FName SessionName, const FString & GameType, const FString & MapName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);

	/** @return the delegate fired when creating a presence session */
	FOnCreatePresenceSessionComplete& OnCreatePresenceSessionComplete() { return CreatePresenceSessionCompleteEvent; }
};