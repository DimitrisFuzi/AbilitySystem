#include "Abilities/Ability.h"

#include "Engine/World.h"
#include "Math/UnrealMathUtility.h"

// UAbility is a UObject, so it doesn't inherently know its UWorld.
// We forward world lookup to our owner (Outer), typically the UAbilityComponent / Actor.
UWorld* UAbility::GetWorld() const
{
	if (const UObject* OuterObj = GetOuter())
	{
		return OuterObj->GetWorld();
	}

	return nullptr;
}

float UAbility::GetRemainingCooldown() const
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		// No world context (e.g. editor/default object). Treat as ready to avoid crashes.
		return 0.0f;
	}

	const float Now = World->GetTimeSeconds();
	return FMath::Max(0.0f, NextReadyTime - Now);
}

bool UAbility::CanActivate() const
{
	return GetRemainingCooldown() <= 0.0f;
}

void UAbility::StartCooldown()
{
	const UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	const float Now = World->GetTimeSeconds();
	NextReadyTime = Now + CooldownSeconds;
}

bool UAbility::Activate_Implementation(AActor* InstigatorActor)
{
	// Base class does nothing by default.
	// Specific abilities override this in BP or derived C++ classes.
	return true;
}