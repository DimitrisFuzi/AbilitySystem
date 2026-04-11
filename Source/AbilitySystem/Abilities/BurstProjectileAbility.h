#pragma once

#include "CoreMinimal.h"
#include "Abilities/Ability.h"
#include "BurstProjectileAbility.generated.h"

class AAbilityProjectile;

UCLASS(Blueprintable)
class ABILITYSYSTEM_API UBurstProjectileAbility : public UAbility
{
    GENERATED_BODY()

public:
    virtual bool Activate_Implementation(AActor* InstigatorActor) override;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    TSubclassOf<AAbilityProjectile> ProjectileClass;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    int32 ProjectileCount = 3;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    float SpreadAngleDegrees = 20.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    float Damage = 15.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Ability|Projectile")
    float SpawnOffset = 100.0f;
};