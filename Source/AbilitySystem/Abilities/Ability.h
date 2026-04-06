#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Ability.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable)
class ABILITYSYSTEM_API UAbility : public UObject
{
	GENERATED_BODY()

public:
	/** Cooldown duration in seconds after a successful activation. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Cooldown", meta = (ClampMin = "0.0"))
	float CooldownSeconds = 1.0f;

	/** Absolute world time (seconds) when this ability becomes usable again. */
	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Ability|Cooldown")
	float NextReadyTime = 0.0f;

	/** Remaining cooldown in seconds. Returns 0 when ready. */
	UFUNCTION(BlueprintCallable, Category = "Ability|Cooldown")
	float GetRemainingCooldown() const;

	/** True if the ability is currently off cooldown. */
	bool CanActivate() const;

	/** Starts cooldown from "now". Call after a successful activation. */
	void StartCooldown();

protected:
	/** Enables time queries from a UObject by forwarding to the owning (Outer) object. */
	virtual UWorld* GetWorld() const override;
};