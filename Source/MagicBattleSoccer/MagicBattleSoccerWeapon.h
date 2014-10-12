#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerWeapon.generated.h"

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

	/** Activates the weapon's primary function */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void PrimaryActionPressed();

	/** Deactivates the weapon's primary function */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void PrimaryActionReleased();
};
