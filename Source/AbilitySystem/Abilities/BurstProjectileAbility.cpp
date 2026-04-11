#include "Abilities/BurstProjectileAbility.h"
#include "AbilityProjectile.h"
#include "GameFramework/Character.h"

bool UBurstProjectileAbility::Activate_Implementation(AActor* InstigatorActor)
{
    if (!InstigatorActor || !ProjectileClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("BurstProjectileAbility — missing instigator or ProjectileClass"));
        return false;
    }

    ACharacter* Character = Cast<ACharacter>(InstigatorActor);
    if (!Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("BurstProjectileAbility — instigator is not a Character"));
        return false;
    }

    UWorld* World = InstigatorActor->GetWorld();
    if (!World)
    {
        return false;
    }

    const FVector SpawnLocation = Character->GetActorLocation() +
        Character->GetActorForwardVector() * SpawnOffset;

    FActorSpawnParameters SpawnParams;
    SpawnParams.Instigator = Character;
    SpawnParams.Owner = Character;

    int32 SpawnedCount = 0;

    for (int32 i = 0; i < ProjectileCount; i++)
    {
        // Calculate spread angle for this projectile
        // Distributes projectiles evenly across the spread range
        float AngleOffset = 0.0f;
        if (ProjectileCount > 1)
        {
            AngleOffset = SpreadAngleDegrees * (i / (float)(ProjectileCount - 1) - 0.5f);
        }

        const FRotator BaseRotation = Character->GetActorRotation();
        const FRotator SpawnRotation = FRotator(
            BaseRotation.Pitch,
            BaseRotation.Yaw + AngleOffset,
            BaseRotation.Roll);

        AAbilityProjectile* Projectile = World->SpawnActor<AAbilityProjectile>(
            ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

        if (Projectile)
        {
            Projectile->Damage = Damage;
            SpawnedCount++;
        }
    }

    return SpawnedCount > 0;
}