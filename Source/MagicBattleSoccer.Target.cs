

using UnrealBuildTool;
using System.Collections.Generic;

public class MagicBattleSoccerTarget : TargetRules
{
	public MagicBattleSoccerTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		
		ExtraModuleNames.Add("MagicBattleSoccer");
	}
}
