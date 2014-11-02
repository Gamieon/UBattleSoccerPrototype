#pragma once

#include "Online.h"

/**
* General session settings for a MagicBattleSoccer game
*/
class FMagicBattleSoccerOnlineSessionSettings : public FOnlineSessionSettings
{
public:

	FMagicBattleSoccerOnlineSessionSettings(bool bIsLAN = false, bool bIsPresence = false, int32 MaxNumPlayers = 4);
	virtual ~FMagicBattleSoccerOnlineSessionSettings() {}
};

/**
* General search setting for a MagicBattleSoccer game
*/
class FMagicBattleSoccerOnlineSearchSettings : public FOnlineSessionSearch
{
public:
	FMagicBattleSoccerOnlineSearchSettings(bool bSearchingLAN = false, bool bSearchingPresence = false);

	virtual ~FMagicBattleSoccerOnlineSearchSettings() {}
};

/**
* Search settings for an empty dedicated server to host a match
*/
class FMagicBattleSoccerOnlineSearchSettingsEmptyDedicated : public FMagicBattleSoccerOnlineSearchSettings
{
public:
	FMagicBattleSoccerOnlineSearchSettingsEmptyDedicated(bool bSearchingLAN = false, bool bSearchingPresence = false);

	virtual ~FMagicBattleSoccerOnlineSearchSettingsEmptyDedicated() {}
};
