#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityProjectile.generated.h"

class UProjectileMovementComponent;
class USphereComponent;

UCLASS()
class ABILITYSYSTEM_API AAbilityProjectile : public AActor
{
    GENERATED_BODY()

public:
    AAbilityProjectile();

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USphereComponent> CollisionSphere;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UProjectileMovementComponent> ProjectileMovement;

    float Damage = 10.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Projectile")
    float ProjectileLifeSpan = 3.0f;

protected:
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnSphereOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult);

    bool bHasHit = false;
};