// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MagicBattleSoccer : ModuleRules
{
	public MagicBattleSoccer(ReadOnlyTargetRules Target) : base(Target)
	{
        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;

		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PrivateIncludePaths.AddRange(
            new string[] { 
                "MagicBattleSoccer/Classes/Bots"
                ,"MagicBattleSoccer/Classes/Online"
				,"MagicBattleSoccer/Classes/Player"
                ,"MagicBattleSoccer/Classes/Soccer"
                ,"MagicBattleSoccer/Classes/Weapons"
                ,"MagicBattleSoccer/Classes/UI"
                ,"MagicBattleSoccer/Classes/Traps"
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

		// Uncomment if you are using Slate UI
		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
