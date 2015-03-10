#pragma once

#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerWeapon_Projectile.generated.h"

USTRUCT(BlueprintType)
struct FProjectileWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** projectile class */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	TSubclassOf<class AMagicBattleSoccerProjectile> ProjectileClass;

	/** life time */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float ProjectileLife;

	/** damage at impact point */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	int32 ExplosionDamage;

	/** radius of damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float ExplosionRadius;

	/** type of damage */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	TSubclassOf<UDamageType> DamageType;

	/** how long to wait between the time the player fires and the time the projectile is released */
	UPROPERTY(EditDefaultsOnly, Category = Soccer)
	float ReleaseDelay;

	/** defaults */
	FProjectileWeaponData()
	{
		ProjectileClass = NULL;
		ProjectileLife = 10.0f;
		ExplosionDamage = 100;
		ExplosionRadius = 300.0f;
		ReleaseDelay = 0.f;
		DamageType = UDamageType::StaticClass();
	}
};

UCLASS(Abstract)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon_Projectile : public AMagicBattleSoccerWeapon
{
	GENERATED_UCLASS_BODY()

private:
	FTimerHandle TimerHandle_FireWeapon_DelayedTimer;

public:
	/** apply config on projectile */
	void ApplyWeaponConfig(FProjectileWeaponData& Data);

	//////////////////////////////////////////////////////////////////////////
	// Input

	/** [local + server] sets the firing target */
	virtual void SetTargetLocationAdjustedForVelocity(FVector TargetLocation, FVector TargetVelocity);

protected:

	/** weapon config */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Soccer)
	FProjectileWeaponData ProjectileConfig;

	//////////////////////////////////////////////////////////////////////////
	// AI

	/** Returns how effective this weapon would be on scene actors in the world's current state */
	TArray<FWeaponActorEffectiveness> GetCurrentEffectiveness();

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() override;

	/** delayed function call to fire the weapon. This is always called even if the fire delay is zero. */
	virtual void FireWeapon_Delayed();

	/** spawn projectile on server */
	UFUNCTION(reliable, server, WithValidation)
	void ServerFireProjectile(FVector Origin, FVector_NetQuantizeNormal ShootDir);
};
