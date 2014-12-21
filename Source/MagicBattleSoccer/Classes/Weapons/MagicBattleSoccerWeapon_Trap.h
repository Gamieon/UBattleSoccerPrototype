#pragma once

#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerWeapon_Trap.generated.h"


UCLASS(Abstract)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon_Trap : public AMagicBattleSoccerWeapon
{
	GENERATED_UCLASS_BODY()

protected:

	/** trap class */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMagicBattleSoccerTrap> TrapClass;

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() override;

	/** spawn trap on server */
	UFUNCTION(reliable, server, WithValidation)
	void ServerSpawnTrap(FVector Origin);

	/** Called when the trap is spawned */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void OnTrapSpawned(AMagicBattleSoccerTrap *Trap);
};
