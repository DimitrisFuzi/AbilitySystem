#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Ability.generated.h"

class AActor;

UCLASS(Abstract, BlueprintType, Blueprintable)
class ABILITYSYSTEM_API UAbility : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ability|Cooldown", meta = (ClampMin = "0.0"))
	float CooldownSeconds = 1.0f;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Ability|Cooldown")
	float NextReadyTime = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,  Category = "Ability|Display")
	TObjectPtr<UTexture2D> Icon;

	

	UFUNCTION(BlueprintCallable, Category = "Ability|Cooldown")
	float GetRemainingCooldown() const;

	bool CanActivate() const;

	//Called when the ability is triggered. Override in BP or derived C++. Return true if activation succeeded.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
	bool Activate(AActor* InstigatorActor);
	virtual bool Activate_Implementation(AActor* InstigatorActor);

	void StartCooldown();

protected:
	virtual UWorld* GetWorld() const override;
};