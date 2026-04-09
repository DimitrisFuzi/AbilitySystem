#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDamageable.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UDamageable : public UInterface
{
    GENERATED_BODY()
};

class ABILITYSYSTEM_API IDamageable
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, Category = "Damage")
    void ReceiveDamage(float Amount, AActor* InstigatorActor);
};