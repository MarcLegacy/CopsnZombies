// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CopsnZombies : ModuleRules
{
	public CopsnZombies(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "Slate", "SlateCore" });
	}
}
