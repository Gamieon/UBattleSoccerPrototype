#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerProjectile.generated.h"

class AMagicBattleSoccerPlayer;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerProjectile : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Gets the actor that spawned this projectile */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AActor *SpawnedByActor;

	/** Gets the amount of damage this projectile deals to a player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 Damage;

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	/** This occurs when the projectile hits a static object */
	UFUNCTION()
	virtual void Hit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
