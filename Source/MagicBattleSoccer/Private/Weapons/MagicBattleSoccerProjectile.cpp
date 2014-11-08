
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerProjectile.h"

AMagicBattleSoccerProjectile::AMagicBattleSoccerProjectile(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

/** This occurs when play begins */
void AMagicBattleSoccerProjectile::BeginPlay()
{
	Super::BeginPlay();

	UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
	Root->OnComponentHit.AddDynamic(this, &AMagicBattleSoccerProjectile::Hit);

	// Limit our life span
	SetLifeSpan(1.5f);
}

/** This occurs when the projectile hits a static object */
void AMagicBattleSoccerProjectile::Hit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}
