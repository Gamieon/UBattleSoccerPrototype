

using UnrealBuildTool;

public class MagicBattleSoccer : ModuleRules
{
	public MagicBattleSoccer(TargetInfo Target)
	{
        PrivateIncludePaths.AddRange(
            new string[] { 
                "MagicBattleSoccer/Classes/Bots"
                ,"MagicBattleSoccer/Classes/Online"
				,"MagicBattleSoccer/Classes/Player"
                ,"MagicBattleSoccer/Classes/Soccer"
                ,"MagicBattleSoccer/Classes/Weapons"
                ,"MagicBattleSoccer/Classes/UI"
                ,"MagicBattleSoccer/Private/UI/Menu"
                ,"MagicBattleSoccer/Private/UI/Style"
                ,"MagicBattleSoccer/Private/UI/Widgets"
            }
        );

        PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine", 
			"OnlineSubsystem",
			"OnlineSubsystemUtils",
            "InputCore", 
            "AIModule" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { 
            "Slate", 
            "SlateCore" });
		
		// Uncomment if you are using online features
        if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64) || (Target.Platform == UnrealTargetPlatform.Linux) || (Target.Platform == UnrealTargetPlatform.Mac))
        {
            if (UEBuildConfiguration.bCompileSteamOSS == true)
            {
                DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
            }

            DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
        }
        else if (Target.Platform == UnrealTargetPlatform.PS4)
        {
            DynamicallyLoadedModuleNames.Add("OnlineSubsystemPS4");
        }
        else if (Target.Platform == UnrealTargetPlatform.XboxOne)
        {
            DynamicallyLoadedModuleNames.Add("OnlineSubsystemLive");
        }
	}
}
