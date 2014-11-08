/** MagicBattleSoccerUserSettings.h - Implements user options */

#pragma once

#include "MagicBattleSoccerUserSettings.generated.h"

UCLASS()
class UMagicBattleSoccerUserSettings : public UGameUserSettings
{
	GENERATED_UCLASS_BODY()

	/** Applies all current user settings to the game and saves to permanent storage (e.g. file), optionally checking for command line overrides. */
	virtual void ApplySettings(bool bCheckForCommandLineOverrides) override;

	/** Gets current fullscreen mode */
	EWindowMode::Type GetCurrentFullscreenMode() const;

	// interface UGameUserSettings
	virtual void SetToDefaults() override;

public:
	/** The player name */
	UPROPERTY(config)
	FString PlayerName;
};
