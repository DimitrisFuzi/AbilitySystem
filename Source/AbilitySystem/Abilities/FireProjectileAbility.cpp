#include "FireProjectileAbility.h"
#include "AbilityProjectile.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"

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

    // Get camera component for aim direction
    UCameraComponent* Camera = Character->FindComponentByClass<UCameraComponent>();
    if (!Camera)
    {
        UE_LOG(LogTemp, Warning, TEXT("FireProjectileAbility — no CameraComponent found on instigator"));
        return false;
    }

    const FVector SpawnLocation = Camera->GetComponentLocation() + Camera->GetForwardVector() * SpawnOffset;
    const FRotator SpawnRotation = Camera->GetComponentRotation();

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

    return Projectile != nullptr;
}