#include "DamageableDummy.h"

ADamageableDummy::ADamageableDummy()
{
    PrimaryActorTick.bCanEverTick = false;
    CurrentHealth = MaxHealth;
}

void ADamageableDummy::ReceiveDamage_Implementation(float Amount, AActor* InstigatorActor)
{
    CurrentHealth -= Amount;

    UE_LOG(LogTemp, Log, TEXT("DamageableDummy — took %.1f damage from %s, health: %.1f / %.1f"),
        Amount,
        InstigatorActor ? *InstigatorActor->GetName() : TEXT("Unknown"),
        CurrentHealth,
        MaxHealth);

    if (CurrentHealth <= 0.0f)
    {
        UE_LOG(LogTemp, Log, TEXT("DamageableDummy — destroyed"));
        Destroy();
    }
}