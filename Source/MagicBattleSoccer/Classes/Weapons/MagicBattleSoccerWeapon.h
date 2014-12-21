#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerWeapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	Idle,
	Firing,
	//Reloading,
	//Equipping,
};

USTRUCT(BlueprintType)
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	/** time between two consecutive shots */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float TimeBetweenShots;

	/** the duration of the animation when attacking */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float AnimationTime;

	/** The effective range of the weapon. Used in AI to determine
	whether the bot should fire at another soccer player. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	float EffectiveRange;

	/** True if the weapon continues to fire in TimeBetweenShot intervals.
	False if the weapon only fires once, in which case when TimeBetweenShots
	has expired, the pawn owner will be sent a notification and firing will cease. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	bool RepeatingFire;

	/** True if the character can walk while firing. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = WeaponStat)
	bool CharacterCanWalkWhileFiring;

	/** defaults */
	FWeaponData()
	{
		TimeBetweenShots = 0.5f;
		AnimationTime = 0.5f;
		EffectiveRange = 120.0f;
		RepeatingFire = false;
		CharacterCanWalkWhileFiring = false;
	}
};

USTRUCT(BlueprintType)
struct FWeaponActorEffectiveness
{
	GENERATED_USTRUCT_BODY()

	/** The actor affected by this weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponEffectiveness)
	class AActor *Actor;

	/** The health change factor [-1,1]. A value of 1 means the actor would be destroyed.
	A value of -1 means the actor would be restored to full health. A value of zero means
	this weapon would have no effect on the actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = WeaponEffectiveness)
	float HealthChange;
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

	/** time of last successful weapon fire */
	UPROPERTY(BlueprintReadOnly, Category = Soccer)
	float LastFireTime;

	/** The weapon's icon to appear at the bottom of the screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Soccer)
	UTexture2D *DashboardIcon;

	//////////////////////////////////////////////////////////////////////////
	// Replication & effects

	UFUNCTION()
	void OnRep_MyPawn();

	//////////////////////////////////////////////////////////////////////////
	// Inventory

	/** weapon is being equipped by owner pawn */
	virtual void OnEquip(FName InSocketName);

	/** weapon is holstered by owner pawn */
	virtual void OnUnEquip();

	/** [server] weapon was added to pawn's inventory */
	virtual void OnEnterInventory(AMagicBattleSoccerCharacter* NewOwner);

	/** [server] weapon was removed from pawn's inventory */
	virtual void OnLeaveInventory();

	/** check if it's currently equipped */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool IsEquipped() const;

	/** check if mesh is already attached */
	bool IsAttachedToPawn() const;

	//////////////////////////////////////////////////////////////////////////
	// Input

	/** [local + server] sets the firing target */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	virtual void SetTargetLocation(FVector TargetLocation);

	/** [local + server] sets the firing target */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	virtual void SetTargetLocationAdjustedForVelocity(FVector TargetLocation, FVector TargetVelocity);

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

	/** get primary weapon state */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	EWeaponState GetCurrentState() const;

	/** set the weapon's owning pawn */
	void SetOwningPawn(AMagicBattleSoccerCharacter* AShooterCharacter);

protected:

	/** pawn owner */
	UPROPERTY(Transient, ReplicatedUsing = OnRep_MyPawn)
	class AMagicBattleSoccerCharacter* MyPawn;

	/** weapon data */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Config)
	FWeaponData WeaponConfig;

public:
	inline const FWeaponData& GetWeaponConfig() { return WeaponConfig; }

public:
	//////////////////////////////////////////////////////////////////////////
	// AI

	/** Returns how effective this weapon would be on scene actors in the world's current state */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	virtual TArray<FWeaponActorEffectiveness> GetCurrentEffectiveness();

protected:
	/** the world coordinate that the player wants to attack */
	FVector TargetLocation;

	//////////////////////////////////////////////////////////////////////////
	// Input - server side

	UFUNCTION(reliable, server, WithValidation)
	void ServerSetTargetLocation(FVector TargetLocation);

	UFUNCTION(reliable, server, WithValidation)
	void ServerSetTargetLocationAdjustedForVelocity(FVector TargetLocation, FVector TargetVelocity);

	UFUNCTION(reliable, server, WithValidation)
	void ServerStartFire();

	UFUNCTION(reliable, server, WithValidation)
	void ServerStopFire();

	//////////////////////////////////////////////////////////////////////////
	// Weapon usage

	/** [local] weapon state. this is first changed on the local player's instance, and then changed
	on the server's instance once the server gets the ServerStartFire RPC. */
	UPROPERTY(Transient)
	EWeaponState LocalState;

	/** the weapon state as it is on the server.  */
	UPROPERTY(Replicated, Transient, Replicated)
	EWeaponState ServerState;

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
	void SetWeaponState(EWeaponState NewState);

	/** determine primary weapon state */
	void DetermineWeaponState();

	//////////////////////////////////////////////////////////////////////////
	// Inventory

	/** attaches weapon mesh to pawn's mesh */
	void AttachMeshToPawn(FName InSocketName);

	/** detaches weapon mesh from pawn */
	void DetachMeshFromPawn();
};
