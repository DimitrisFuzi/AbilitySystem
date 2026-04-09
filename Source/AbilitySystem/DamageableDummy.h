#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDamageable.h"
#include "DamageableDummy.generated.h"

UCLASS()
class ABILITYSYSTEM_API ADamageableDummy : public AActor, public IDamageable
{
    GENERATED_BODY()

public:
    ADamageableDummy();

    UPROPERTY(EditDefaultsOnly, Category = "Health")
    float MaxHealth = 100.0f;

    UPROPERTY(VisibleInstanceOnly, Category = "Health")
    float CurrentHealth = 100.0f;

    virtual void ReceiveDamage_Implementation(float Amount, AActor* InstigatorActor) override;
};