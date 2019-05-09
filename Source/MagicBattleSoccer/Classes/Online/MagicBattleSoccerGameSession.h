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
	/** Delegate for searching for sessions */
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;

	/** Handles to various registered delegates */
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnDestroySessionCompleteDelegateHandle;
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;

	/** Transient properties of a session during game creation/matchmaking */
	FMagicBattleSoccerSessionParams CurrentSessionParams;
	/** Current host settings */
	TSharedPtr<class FMagicBattleSoccerOnlineSessionSettings> HostSettings;
	/** Current search settings */
	TSharedPtr<class FMagicBattleSoccerOnlineSearchSettings> SearchSettings;

	/**
	* Delegate fired when a session create request has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);

	/**
	* Delegate fired when a session search query has completed
	*
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	void OnFindSessionsComplete(bool bWasSuccessful);

	/**
	* Delegate fired when a destroying an online session has completed
	*
	* @param SessionName the name of the session this callback is for
	* @param bWasSuccessful true if the async action completed without error, false if there was an error
	*/
	virtual void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);

	/*
	* Event triggered when a presence session is created
	*
	* @param SessionName name of session that was created
	* @param bWasSuccessful was the create successful
	*/
	DECLARE_EVENT_TwoParams(AMagicBattleSoccerGameSession, FOnCreatePresenceSessionComplete, FName /*SessionName*/, bool /*bWasSuccessful*/);
	FOnCreatePresenceSessionComplete CreatePresenceSessionCompleteEvent;

	/*
	* Event triggered after session search completes
	*/
	DECLARE_EVENT_OneParam(AMagicBattleSoccerGameSession, FOnFindSessionsComplete, bool /*bWasSuccessful*/);
	FOnFindSessionsComplete FindSessionsCompleteEvent;

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
	bool HostSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FString & GameType, const FString & MapName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);

	/**
	* Find an online session
	*
	* @param UserId user that initiated the request
	* @param SessionName name of session this search will generate
	* @param bIsLAN are we searching LAN matches
	* @param bIsPresence are we searching presence sessions
	*/
	void FindSessions(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence);

	/**
	* Get the search results found and the current search result being probed
	*
	* @param SearchResultIdx idx of current search result accessed
	* @param NumSearchResults number of total search results found in FindGame()
	*
	* @return State of search result query
	*/
	EOnlineAsyncTaskState::Type GetSearchResultStatus(int32& SearchResultIdx, int32& NumSearchResults);

	/**
	* Get the search results.
	*
	* @return Search results
	*/
	const TArray<FOnlineSessionSearchResult> & GetSearchResults() const;

	/** @return the delegate fired when creating a presence session */
	FOnCreatePresenceSessionComplete& OnCreatePresenceSessionComplete() { return CreatePresenceSessionCompleteEvent; }

	/** @return the delegate fired when search of session completes */
	FOnFindSessionsComplete& OnFindSessionsComplete() { return FindSessionsCompleteEvent; }
};