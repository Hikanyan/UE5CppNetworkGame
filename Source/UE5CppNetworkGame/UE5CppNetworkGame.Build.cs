// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5CppNetworkGame : ModuleRules
{
	public UE5CppNetworkGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
