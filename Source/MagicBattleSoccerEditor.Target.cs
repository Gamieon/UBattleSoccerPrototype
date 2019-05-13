

using UnrealBuildTool;
using System.Collections.Generic;

public class MagicBattleSoccerEditorTarget : TargetRules
{
	public MagicBattleSoccerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("MagicBattleSoccer");
	}
}
