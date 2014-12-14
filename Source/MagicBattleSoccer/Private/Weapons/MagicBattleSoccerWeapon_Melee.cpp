
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerWeapon_Melee.h"
#include "MagicBattleSoccerPlayerController.h"

AMagicBattleSoccerWeapon_Melee::AMagicBattleSoccerWeapon_Melee(const class FObjectInitializer& OI)
	: Super(OI)
{
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Melee::FireWeapon()
{
	FVector WorldLocation;
	FVector WorldDirection;

	AController* const Controller = Instigator ? Instigator->Controller : nullptr;
	if (nullptr != Controller)
	{
		// Deal damage half way through the swing
		GetWorldTimerManager().SetTimer(this, &AMagicBattleSoccerWeapon_Melee::ApplySweepDamage, WeaponConfig.TimeBetweenShots * 0.5f, false);		
	}
}

/** Applies damage to actors in the path of this weapon's swing */
void AMagicBattleSoccerWeapon_Melee::ApplySweepDamage()
{
	// This is inaccurate and hacky, but it gets the job done
	if (MeleeConfig.Damage > 0 && MeleeConfig.DamageRadius > 0 && MeleeConfig.DamageType)
	{
		AController* const Controller = Instigator ? Instigator->Controller : nullptr;
		UGameplayStatics::ApplyRadialDamage(this, MeleeConfig.Damage, GetActorLocation(), MeleeConfig.DamageRadius, MeleeConfig.DamageType, TArray<AActor*>(), this, Controller, true);
	}
}