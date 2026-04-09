#include "AbilityProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AAbilityProjectile::AAbilityProjectile()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
    RootComponent = CollisionSphere;
    CollisionSphere->SetSphereRadius(15.0f);
    CollisionSphere->SetCollisionProfileName(TEXT("Projectile"));

    ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
    ProjectileMovement->InitialSpeed = 2000.0f;
    ProjectileMovement->MaxSpeed = 2000.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;

    InitialLifeSpan = ProjectileLifeSpan;
}

void AAbilityProjectile::BeginPlay()
{
    Super::BeginPlay();

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AAbilityProjectile::OnSphereOverlap);

    // Ignore the instigator so the projectile doesn't hit the character that fired it
    if (AActor* MyInstigator = GetInstigator())
    {
        CollisionSphere->IgnoreActorWhenMoving(MyInstigator, true);
    }
}

void AAbilityProjectile::OnSphereOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherActor || OtherActor == GetInstigator())
    {
        return;
    }

    UE_LOG(LogTemp, Log, TEXT("AbilityProjectile — hit %s"), *OtherActor->GetName());

    // IDamageable check goes here in Phase 4 — for now just log and destroy
    Destroy();
}