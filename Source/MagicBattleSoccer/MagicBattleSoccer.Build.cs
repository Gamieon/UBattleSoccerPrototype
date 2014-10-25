

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
            }
        );

        PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", 
            "CoreUObject", 
            "Engine", 
            "InputCore", 
            "AIModule" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { 
            "Slate", 
            "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
