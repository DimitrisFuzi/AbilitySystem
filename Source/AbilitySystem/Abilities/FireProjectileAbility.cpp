#include "FireProjectileAbility.h"
#include "AbilityProjectile.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"

bool UFireProjectileAbility::Activate_Implementation(AActor* InstigatorActor)
{
    if (!InstigatorActor || !ProjectileClass)
    {
        UE_LOG(LogTemp, Warning, TEXT("FireProjectileAbility — missing instigator or ProjectileClass"));
        return false;
    }

    ACharacter* Character = Cast<ACharacter>(InstigatorActor);
    if (!Character)
    {
        UE_LOG(LogTemp, Warning, TEXT("FireProjectileAbility — instigator is not a Character"));
        return false;
    }

    const FVector SpawnLocation = Character->GetActorLocation() + Character->GetActorForwardVector() * SpawnOffset;
    const FRotator SpawnRotation = Character->GetActorRotation();

    FActorSpawnParameters SpawnParams;
    SpawnParams.Instigator = Character;
    SpawnParams.Owner = Character;

    UWorld* World = InstigatorActor->GetWorld();
    if (!World)
    {
        return false;
    }

    AAbilityProjectile* Projectile = World->SpawnActor<AAbilityProjectile>(
        ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);

    if (Projectile)
    {
        Projectile->Damage = Damage;
    }
    return Projectile != nullptr;
}