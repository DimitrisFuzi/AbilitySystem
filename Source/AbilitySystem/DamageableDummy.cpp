#include "DamageableDummy.h"

ADamageableDummy::ADamageableDummy()
{
    PrimaryActorTick.bCanEverTick = false;
    CurrentHealth = MaxHealth;
}

void ADamageableDummy::ReceiveDamage_Implementation(float Amount, AActor* InstigatorActor)
{
    CurrentHealth -= Amount;

    if (CurrentHealth <= 0.0f)
    {
        Destroy();
    }
}