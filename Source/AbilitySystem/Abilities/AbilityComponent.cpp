#include "Abilities/AbilityComponent.h"

UAbilityComponent::UAbilityComponent()
{
	// no need to tick, so disable ticking and save some performance
    PrimaryComponentTick.bCanEverTick = false;
    Slots.SetNum(SlotCount);
}

void UAbilityComponent::EquipAbility(int32 SlotIndex, TSubclassOf<UAbility> AbilityClass)
{
    if (!Slots.IsValidIndex(SlotIndex))
    {
        UE_LOG(LogTemp, Warning, TEXT("EquipAbility — invalid slot index %d"), SlotIndex);
        return;
    }

    if (!AbilityClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("EquipAbility — null AbilityClass for slot %d"), SlotIndex);
        return;
    }

    UAbility* NewAbility = NewObject<UAbility>(this, AbilityClass);
    Slots[SlotIndex] = NewAbility;

    UE_LOG(LogTemp, Log, TEXT("EquipAbility — equipped %s in slot %d"),
        *AbilityClass->GetName(), SlotIndex);
}

void UAbilityComponent::TriggerSlot(int32 SlotIndex)
{

    if (!Slots.IsValidIndex(SlotIndex))
    {
        UE_LOG(LogTemp, Warning, TEXT("TriggerSlot — invalid slot %d"), SlotIndex);
        return;
    }

    UAbility* Ability = Slots[SlotIndex];

    if (!Ability)
    {
        UE_LOG(LogTemp, Log, TEXT("TriggerSlot — slot %d is empty"), SlotIndex);
        return;
    }

    if (!Ability->CanActivate())
    {
        UE_LOG(LogTemp, Log, TEXT("TriggerSlot — slot %d on cooldown, %.1fs remaining"),
            SlotIndex, Ability->GetRemainingCooldown());
        return;
    }
    
    if (Ability->Activate(GetOwner()))
    {
        Ability->StartCooldown();
    }
}

UAbility* UAbilityComponent::GetAbilityInSlot(int32 SlotIndex) const
{
    if (!Slots.IsValidIndex(SlotIndex)) return nullptr;
    return Slots[SlotIndex];
}