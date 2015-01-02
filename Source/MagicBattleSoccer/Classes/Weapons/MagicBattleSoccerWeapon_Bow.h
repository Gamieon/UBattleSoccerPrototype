#pragma once

#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerWeapon_Projectile.h"
#include "MagicBattleSoccerWeapon_Bow.generated.h"


UCLASS(Abstract)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon_Bow : public AMagicBattleSoccerWeapon_Projectile
{
	GENERATED_UCLASS_BODY()

	/** mesh for the arrow to be drawn when firing (I preferred to get this from the projectile data in the blueprint editor but couldn't figure out how */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Soccer)
	UStaticMesh *DrawnArrowMesh;

	/** when this bow is equipped, this component contains the drawn arrow mesh that the instigator pulls from their quiver */
	UPROPERTY(BlueprintReadWrite, Category = Soccer)
	UStaticMeshComponent *DrawnArrowComponent;

	//////////////////////////////////////////////////////////////////////////
	// Inventory

	/** weapon is being equipped by owner pawn */
	virtual void OnEquip(FName InSocketName);

	/** weapon is holstered by owner pawn */
	virtual void OnUnEquip();

	/** when equipping a bow, the instigator needs to have an arrow mesh in their hand so it looks like they're drawing an arrow from their
	quiver before firing. This should be called whenever the weapon is equipped or unequipped to update the state of the arrow mesh. */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void UpdateDrawnArrowComponent();

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() override;

	/** delayed function call to release the arrow */
	virtual void FireWeapon_Delayed();
};
