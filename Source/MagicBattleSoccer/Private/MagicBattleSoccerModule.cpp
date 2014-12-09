
#include "MagicBattleSoccer.h"
#include "SlateBasics.h"
#include "MagicBattleSoccerStyles.h"

/**
* Custom implementation of the Default Game Module.
**/
class FSlateTutorialsGameModule : public FDefaultGameModuleImpl
{
	/**
	* Called whenever the module is starting up. In here, we unregister any style sets (which may have been added by other modules) sharing our
	* style set's name, then initialize our style set.
	**/
	virtual void StartupModule() override
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(FMagicBattleSoccerStyles::GetStyleSetName());
		FMagicBattleSoccerStyles::Initialize();
	}

	/**
	* Called whenever the module is shutting down. Here, we simply tell our MenuStyles to shut down.
	**/
	virtual void ShutdownModule() override
	{
		FMagicBattleSoccerStyles::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, MagicBattleSoccer, "MagicBattleSoccer" );
