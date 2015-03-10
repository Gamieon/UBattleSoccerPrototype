
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerWeapon_Melee.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerPlayerController.h"

AMagicBattleSoccerWeapon_Melee::AMagicBattleSoccerWeapon_Melee(const class FObjectInitializer& OI)
	: Super(OI)
{
}

//////////////////////////////////////////////////////////////////////////
// AI

/** Returns how effective this weapon would be on scene actors in the world's current state */
TArray<FWeaponActorEffectiveness> AMagicBattleSoccerWeapon_Melee::GetCurrentEffectiveness()
{
	TArray<FWeaponActorEffectiveness> effectivenessList;
	if (nullptr != Instigator && nullptr != Instigator->PlayerState)
	{
		UWorld *World = GetWorld();
		AMagicBattleSoccerGameState* GameState = Cast<AMagicBattleSoccerGameState>(World->GetGameState<AMagicBattleSoccerGameState>());
		AMagicBattleSoccerPlayerState *PlayerState = Cast<AMagicBattleSoccerPlayerState>(Instigator->PlayerState);
		if (nullptr != GameState)
		{
			const TArray<AMagicBattleSoccerCharacter*>& Opponents = GameState->GetOpponents(PlayerState);
			for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
			{
				float d = Instigator->GetDistanceTo(*It);
				if (d < WeaponConfig.EffectiveRange)
				{
					FWeaponActorEffectiveness e;
					e.Actor = *It;
					e.HealthChange = (float)MeleeConfig.Damage / (*It)->Health;
					effectivenessList.Add(e);
				}
			}
		}
	}
	return effectivenessList;
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Melee::FireWeapon()
{
	Super::FireWeapon();

	FVector WorldLocation;
	FVector WorldDirection;

	AController* const Controller = Instigator ? Instigator->Controller : nullptr;
	if (nullptr != Controller)
	{
		// Deal damage half way through the swing
		GetWorldTimerManager().SetTimer(TimerHandle_ApplySweepDamageTimer, this, &AMagicBattleSoccerWeapon_Melee::ApplySweepDamage, WeaponConfig.TimeBetweenShots * 0.5f, false);
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