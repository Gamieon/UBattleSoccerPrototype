#pragma once

#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerWeapon_Melee.generated.h"

USTRUCT()
struct FMeleeWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** damage at impact point */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	int32 Damage;

	/** radius of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	float DamageRadius;

	/** type of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	TSubclassOf<UDamageType> DamageType;

	/** defaults */
	FMeleeWeaponData()
	{
		Damage = 70;
		DamageRadius = 250.f;
		DamageType = UDamageType::StaticClass();
	}
};

UCLASS(Abstract)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon_Melee : public AMagicBattleSoccerWeapon
{
	GENERATED_UCLASS_BODY()

public:
	//////////////////////////////////////////////////////////////////////////
	// AI

	/** Returns how effective this weapon would be on scene actors in the world's current state */
	virtual TArray<FWeaponActorEffectiveness> GetCurrentEffectiveness();

protected:

	/** weapon config */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	FMeleeWeaponData MeleeConfig;

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() override;

private:
	/** Applies damage to actors in the path of this weapon's swing */
	virtual void ApplySweepDamage();
};
