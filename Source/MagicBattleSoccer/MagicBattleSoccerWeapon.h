#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerWeapon.generated.h"

class AMagicBattleSoccerPlayerController;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Gets the amount of damage this projectile deals to a player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	float EffectiveRange;

	/** True if the weapon is being fired */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	bool IsFiring;

	/** Gets the rotation the weapon should emit damage from */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FRotator GetWorldFiringRotation();

	/** Activates the weapon's primary function */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void BeginFire();

	/** Deactivates the weapon's primary function */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void CeaseFire();
};
