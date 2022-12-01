// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP12MoteurJeu : ModuleRules
{
	public TP12MoteurJeu(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara" });
    }
}
