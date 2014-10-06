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

	/** Activates the weapon's primary function */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void FirePrimary();
};
