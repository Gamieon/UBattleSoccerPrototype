#pragma once

#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerWeapon_Projectile.generated.h"

USTRUCT()
struct FProjectileWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** projectile class */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMagicBattleSoccerProjectile> ProjectileClass;

	/** life time */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	float ProjectileLife;

	/** damage at impact point */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	int32 ExplosionDamage;

	/** radius of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	float ExplosionRadius;

	/** type of damage */
	UPROPERTY(EditDefaultsOnly, Category = WeaponStat)
	TSubclassOf<UDamageType> DamageType;

	/** defaults */
	FProjectileWeaponData()
	{
		ProjectileClass = NULL;
		ProjectileLife = 10.0f;
		ExplosionDamage = 100;
		ExplosionRadius = 300.0f;
		DamageType = UDamageType::StaticClass();
	}
};

UCLASS(Abstract)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon_Projectile : public AMagicBattleSoccerWeapon
{
	GENERATED_UCLASS_BODY()

	/** apply config on projectile */
	void ApplyWeaponConfig(FProjectileWeaponData& Data);

protected:

	/** weapon config */
	UPROPERTY(EditDefaultsOnly, Category = Config)
	FProjectileWeaponData ProjectileConfig;

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() override;

	/** spawn projectile on server */
	UFUNCTION(reliable, server, WithValidation)
	void ServerFireProjectile(FVector Origin, FVector_NetQuantizeNormal ShootDir);

	//////////////////////////////////////////////////////////////////////////
	// LEGACY

	/** Gets the rotation the weapon should fire in */
	//UFUNCTION(BlueprintCallable, Category = Soccer)
	//FRotator GetWorldFiringRotation();
};
