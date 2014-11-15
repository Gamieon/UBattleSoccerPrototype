#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerWeapon.generated.h"

namespace EWeaponState
{
	enum Type
	{
		Idle,
		Firing,
		Reloading,
		Equipping,
	};
}

USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** time between two consecutive shots */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float TimeBetweenShots;

	/** The effective range of the weapon. Used in AI to determine
	whether the bot should fire at another soccer player. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float EffectiveRange;

	/** defaults */
	FWeaponData()
	{
		TimeBetweenShots = 0.2f;
		EffectiveRange = 200.0f;
	}
};

/**
* Actor is the base class for an Object that can be placed or spawned in a level.
* Actors may contain a collection of ActorComponents, which can be used to control how actors move, how they are rendered, etc.
* The other main function of an Actor is the replication of properties and function calls across the network during play.
*/
UCLASS(Abstract, Blueprintable)
class MAGICBATTLESOCCER_API AMagicBattleSoccerWeapon : public AActor
{
	GENERATED_UCLASS_BODY()

	/** is weapon currently equipped? */
	uint32 bIsEquipped : 1;

	/** is weapon fire active? */
	uint32 bWantsToFire : 1;

	/** weapon is refiring */
	uint32 bRefiring;

	/** current weapon state */
	EWeaponState::Type CurrentState;

	/** time of last successful weapon fire */
	float LastFireTime;

	//////////////////////////////////////////////////////////////////////////
	// Replication & effects

	UFUNCTION()
	void OnRep_MyPawn();

	//////////////////////////////////////////////////////////////////////////
	// Inventory

	/** weapon is being equipped by owner pawn */
	virtual void OnEquip();

	/** weapon is holstered by owner pawn */
	virtual void OnUnEquip();

	/** [server] weapon was added to pawn's inventory */
	virtual void OnEnterInventory(AMagicBattleSoccerPlayer* NewOwner);

	/** [server] weapon was removed from pawn's inventory */
	virtual void OnLeaveInventory();

	/** check if it's currently equipped */
	bool IsEquipped() const;

	/** check if mesh is already attached */
	bool IsAttachedToPawn() const;

	//////////////////////////////////////////////////////////////////////////
	// Input

	/** [local + server] start weapon fire */
	virtual void StartFire();

	/** [local + server] stop weapon fire */
	virtual void StopFire();

	//////////////////////////////////////////////////////////////////////////
	// Control

	/** check if weapon can fire */
	bool CanFire() const;

	//////////////////////////////////////////////////////////////////////////
	// Reading data

	/** get current weapon state */
	EWeaponState::Type GetCurrentState() const;

	/** set the weapon's owning pawn */
	void SetOwningPawn(AMagicBattleSoccerPlayer* AShooterCharacter);

protected:

	/** pawn owner */
	UPROPERTY(Transient, ReplicatedUsing = OnRep_MyPawn)
	class AMagicBattleSoccerPlayer* MyPawn;

	/** weapon data */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	FWeaponData WeaponConfig;

	//////////////////////////////////////////////////////////////////////////
	// Input - server side

	UFUNCTION(reliable, server, WithValidation)
	void ServerStartFire();

	UFUNCTION(reliable, server, WithValidation)
	void ServerStopFire();

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon specific fire implementation */
	virtual void FireWeapon() PURE_VIRTUAL(AMagicBattleSoccerWeapon::FireWeapon, );

	/** [server] fire & update ammo */
	UFUNCTION(reliable, server, WithValidation)
	void ServerHandleFiring();

	/** [local + server] handle weapon fire */
	void HandleFiring();

	/** [local + server] firing started */
	virtual void OnBurstStarted();

	/** [local + server] firing finished */
	virtual void OnBurstFinished();

	/** update weapon state */
	void SetWeaponState(EWeaponState::Type NewState);

	/** determine current weapon state */
	void DetermineWeaponState();

	//////////////////////////////////////////////////////////////////////////
	// Inventory

	/** attaches weapon mesh to pawn's mesh */
	void AttachMeshToPawn();

	/** detaches weapon mesh from pawn */
	void DetachMeshFromPawn();

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage helpers

	/** Get the aim of the weapon, allowing for adjustments to be made by the weapon */
	virtual FVector GetAdjustedAim() const;

	/** get the muzzle location of the weapon */
	FVector GetMuzzleLocation() const;

public:
	//////////////////////////////////////////////////////////////////////////
	// LEGACY

	/** True if the weapon is being fired */
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	//bool IsFiring;

	/** Activates the weapon's primary function */
	//UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	//void BeginFire();

	/** Deactivates the weapon's primary function */
	//UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	//void CeaseFire();
};
