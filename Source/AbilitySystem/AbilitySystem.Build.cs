// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AbilitySystem : ModuleRules
{
	public AbilitySystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"AbilitySystem",
			"AbilitySystem/Variant_Platforming",
			"AbilitySystem/Variant_Platforming/Animation",
			"AbilitySystem/Variant_Combat",
			"AbilitySystem/Variant_Combat/AI",
			"AbilitySystem/Variant_Combat/Animation",
			"AbilitySystem/Variant_Combat/Gameplay",
			"AbilitySystem/Variant_Combat/Interfaces",
			"AbilitySystem/Variant_Combat/UI",
			"AbilitySystem/Variant_SideScrolling",
			"AbilitySystem/Variant_SideScrolling/AI",
			"AbilitySystem/Variant_SideScrolling/Gameplay",
			"AbilitySystem/Variant_SideScrolling/Interfaces",
			"AbilitySystem/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
