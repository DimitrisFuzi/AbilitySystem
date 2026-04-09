#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Abilities/Ability.h"
#include "AbilityComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ABILITYSYSTEM_API UAbilityComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAbilityComponent();

    UFUNCTION(BlueprintCallable)
    void EquipAbility(int32 SlotIndex, TSubclassOf<UAbility> AbilityClass);

    UFUNCTION(BlueprintCallable)
    void TriggerSlot(int32 SlotIndex);

    UFUNCTION(BlueprintPure)
    UAbility* GetAbilityInSlot(int32 SlotIndex) const;

private:
    UPROPERTY()
    TArray<TObjectPtr<UAbility>> Slots;

    static constexpr int32 SlotCount = 4;
};