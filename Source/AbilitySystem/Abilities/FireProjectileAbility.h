#pragma once

#include "CoreMinimal.h"
#include "Abilities/Ability.h"
#include "FireProjectileAbility.generated.h"

class AAbilityProjectile;

UCLASS(Blueprintable)
class ABILITYSYSTEM_API UFireProjectileAbility : public UAbility
{
    GENERATED_BODY()

public:
    virtual bool Activate_Implementation(AActor* InstigatorActor) override;

    // The projectile class to spawn — set in BP subclass
    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    TSubclassOf<AAbilityProjectile> ProjectileClass;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    float SpawnOffset = 100.0f;
};