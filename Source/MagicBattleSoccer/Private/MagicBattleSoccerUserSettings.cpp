#include "MagicBattleSoccerUserSettings.h"
#include "MagicBattleSoccer.h"

UMagicBattleSoccerUserSettings::UMagicBattleSoccerUserSettings(const class FObjectInitializer& OI)
	: Super(OI)
{
	SetToDefaults();
}

void UMagicBattleSoccerUserSettings::SetToDefaults()
{
	Super::SetToDefaults();
}

void UMagicBattleSoccerUserSettings::ApplySettings(bool bCheckForCommandLineOverrides)
{
	Super::ApplySettings(bCheckForCommandLineOverrides);

	if (!GEngine)
	{
		return;
	}
}

int32 ShooterGameGetBoundFullScreenModeCVar()
{
	static const auto CVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.FullScreenMode"));

	if (FPlatformProperties::SupportsWindowedMode())
	{
		int32 Value = CVar->GetValueOnGameThread();

		if (Value >= 0 && Value <= 2)
		{
			return Value;
		}
	}

	// every other value behaves like 0
	return 0;
}

// depending on bFullscreen and the console variable r.FullScreenMode
EWindowMode::Type ShooterGameGetWindowModeType(bool bFullscreen)
{
	int32 FullScreenMode = ShooterGameGetBoundFullScreenModeCVar();

	if (FPlatformProperties::SupportsWindowedMode())
	{
		if (!bFullscreen)
		{
			return EWindowMode::Windowed;
		}

		if (FullScreenMode == 1 || FullScreenMode == 2)
		{
			return EWindowMode::WindowedFullscreen;
		}
	}

	return EWindowMode::Fullscreen;
}

EWindowMode::Type UMagicBattleSoccerUserSettings::GetCurrentFullscreenMode() const
{
	EWindowMode::Type CurrentFullscreenMode = EWindowMode::Windowed;
	if (GEngine && GEngine->GameViewport && GEngine->GameViewport->ViewportFrame)
	{
		bool bIsCurrentlyFullscreen = GEngine->GameViewport->IsFullScreenViewport();
		CurrentFullscreenMode = ShooterGameGetWindowModeType(bIsCurrentlyFullscreen);
	}
	return CurrentFullscreenMode;
}
