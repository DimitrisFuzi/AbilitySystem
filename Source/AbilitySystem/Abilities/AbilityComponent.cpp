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
    OnSlotChanged.Broadcast(SlotIndex);

}

void UAbilityComponent::TriggerSlot(int32 SlotIndex)
{

    if (!Slots.IsValidIndex(SlotIndex))
    {
        return;
    }

    UAbility* Ability = Slots[SlotIndex];

    if (!Ability)
    {
        return;
    }

    if (!Ability->CanActivate())
    {
        return;
    }
    
    if (Ability->Activate(GetOwner()))
    {
        Ability->StartCooldown();
        OnSlotChanged.Broadcast(SlotIndex);
    }
}

UAbility* UAbilityComponent::GetAbilityInSlot(int32 SlotIndex) const
{
    if (!Slots.IsValidIndex(SlotIndex)) return nullptr;
    return Slots[SlotIndex];
}