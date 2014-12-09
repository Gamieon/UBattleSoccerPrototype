#pragma once

#include "GameFramework/Character.h"
#include "MagicBattleSoccerTypes.h"
#include "MagicBattleSoccerCharacter.generated.h"

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	//////////////////////////////////////////////////////////////////////////
	// Player attributes

	/** The max health this player has */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	float MaxHealth;

	/** The health this player has */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	float Health;

	/** current firing state */
	uint8 bWantsPrimaryFire : 1;
	/** secondary attack state */
	uint8 bWantsSecondaryFire : 1;

	/** The current movement speed for this player. This changes if the player
	possesses the ball */
	UPROPERTY(ReplicatedUsing = OnRep_CurrentMovementSpeed)
	float CurrentMovementSpeed;
	UFUNCTION()
	void OnRep_CurrentMovementSpeed();

	/** The last time that this player possessed the ball. Only the server
	should care about this value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	float LastBallPossessionTime;

	/** The default movement speed for this player. Initially assigned the
	max walking speed. */
	float DefaultMovementSpeed;

	/** [server] perform PlayerState related setup */
	virtual void PossessedBy(class AController* C) override;

	/** [client] perform PlayerState related setup */
	virtual void OnRep_PlayerState() override;

	//////////////////////////////////////////////////////////////////////////
	// Damage & death

	/** Replicate where this pawn was last hit and damaged */
	UPROPERTY(Transient, ReplicatedUsing = OnRep_LastTakeHitInfo)
	FTakeHitInfo LastTakeHitInfo;
	/** play hit or death on client */
	UFUNCTION()
	void OnRep_LastTakeHitInfo();

	/** Time at which point the last take hit info for the actor times out and won't be replicated; Used to stop join-in-progress effects all over the screen */
	float LastTakeHitTimeTimeout;

	//////////////////////////////////////////////////////////////////////////
	// Inventory and weapons

	/** default inventory list */
	UPROPERTY(EditDefaultsOnly, Category = Inventory)
	TArray<TSubclassOf<class AMagicBattleSoccerWeapon> > DefaultInventoryClasses;

	/** weapons in inventory */
	UPROPERTY(Transient, Replicated)
	TArray<class AMagicBattleSoccerWeapon*> Inventory;

	/** The player's primary weapon */
	UPROPERTY(Transient, BlueprintReadOnly, ReplicatedUsing = OnRep_PrimaryWeapon, Category = Soccer)
	class AMagicBattleSoccerWeapon* PrimaryWeapon;
	UFUNCTION()
	void OnRep_PrimaryWeapon(class AMagicBattleSoccerWeapon* LastWeapon);

	/** The player's secondary weapon */
	UPROPERTY(Transient, BlueprintReadOnly, ReplicatedUsing = OnRep_SecondaryWeapon, Category = Soccer)
	class AMagicBattleSoccerWeapon* SecondaryWeapon;
	UFUNCTION()
	void OnRep_SecondaryWeapon(class AMagicBattleSoccerWeapon* LastWeapon);

	//Begin AActor interface

	/** spawn inventory, setup initial variables */
	virtual void PostInitializeComponents() override;

	/** Called on the actor right before replication occurs */
	virtual void PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker) override;

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds) override;

	/** This occurs when play ends */
	virtual void ReceiveEndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** This occurs when the player is destroyed */
	virtual void Destroyed() override;

	//End AActor interface

	//////////////////////////////////////////////////////////////////////////
	// Damage & death

	/** Take damage, handle death */
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;

	/** Returns True if the pawn can die in the current state */
	virtual bool CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const;

	/**
	* Kills pawn.  Server/authority only.
	* @param KillingDamage - Damage amount of the killing blow
	* @param DamageEvent - Damage event of the killing blow
	* @param Killer - Who killed this pawn
	* @param DamageCauser - the Actor that directly caused the damage (i.e. the Projectile that exploded, the Weapon that fired, etc)
	* @returns true if allowed
	*/
	virtual bool Die(float KillingDamage, struct FDamageEvent const& DamageEvent, class AController* Killer, class AActor* DamageCauser);

	/** notification when killed, for both the server and client. */
	virtual void OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* InstigatingPawn, class AActor* DamageCauser);

	/** play effects on hit */
	virtual void PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser);

	/** sets up the replication for taking a hit */
	void ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* InstigatingPawn, class AActor* DamageCauser, bool bKilled);

	//////////////////////////////////////////////////////////////////////////
	// Inventory and weapons

	/** updates primary weapon */
	void SetPrimaryWeapon(class AMagicBattleSoccerWeapon* NewWeapon, class AMagicBattleSoccerWeapon* LastWeapon = NULL);

	/** updates secondary weapon */
	void SetSecondaryWeapon(class AMagicBattleSoccerWeapon* NewWeapon, class AMagicBattleSoccerWeapon* LastWeapon = NULL);

	/** [server] spawns default inventory */
	void SpawnDefaultInventory();

	/** [server] remove all weapons from inventory and destroy them */
	void DestroyInventory();

	/** equip weapon */
	UFUNCTION(reliable, server, WithValidation)
	void ServerEquipPrimaryWeapon(class AMagicBattleSoccerWeapon* NewWeapon);

	/** equip weapon */
	UFUNCTION(reliable, server, WithValidation)
	void ServerEquipSecondaryWeapon(class AMagicBattleSoccerWeapon* NewWeapon);

	/**
	* [server] add weapon to inventory
	*
	* @param Weapon	Weapon to add.
	*/
	void AddWeapon(class AMagicBattleSoccerWeapon* Weapon);

	/**
	* [server] remove weapon from inventory
	*
	* @param Weapon	Weapon to remove.
	*/
	void RemoveWeapon(class AMagicBattleSoccerWeapon* Weapon);

	/**
	* [server + local] equips weapon from inventory
	*
	* @param Weapon	Weapon to equip
	*/
	void EquipPrimaryWeapon(class AMagicBattleSoccerWeapon* Weapon);

	/**
	* [server + local] equips weapon from inventory
	*
	* @param Weapon	Weapon to equip
	*/
	void EquipSecondaryWeapon(class AMagicBattleSoccerWeapon* Weapon);

	/** Called to change a player's outfit based on team */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void AssignUniform();

	//////////////////////////////////////////////////////////////////////////
	// Actions

	/** [local] starts weapon fire */
	void StartPrimaryWeaponFire();

	/** [local] stops weapon fire */
	void StopPrimaryWeaponFire();

	/** [local] starts weapon fire */
	void StartSecondaryWeaponFire();

	/** [local] stops weapon fire */
	void StopSecondaryWeaponFire();

	/** check if pawn can fire weapon */
	bool CanFire();

	/** [server] Updates the movement speed based on conditions (ball possessor, etc) */
	void UpdateMovementSpeed();

	/** [local] Kicks the ball with a force */
	void KickBall(const FVector& Force);

	/** [local] Kicks the ball to a location */
	void KickBallToLocation(const FVector& Location, float AngleInDegrees);

	//////////////////////////////////////////////////////////////////////////
	// Actions - server side

	UFUNCTION(reliable, server, WithValidation)
	void ServerKickBall(FVector Force);

	UFUNCTION(reliable, server, WithValidation)
	void ServerKickBallToLocation(FVector Force, float AngleInDegrees);

	//////////////////////////////////////////////////////////////////////////
	// Player attributes

	/** Gets the game mode (only the server should be interested in this) */
	class AMagicBattleSoccerGameMode* GetGameMode();

	/** Gets the game state (all instances should be interested in this) */
	class AMagicBattleSoccerGameState* GetGameState();

	/** Gets the soccer ball */
	class AMagicBattleSoccerBall* GetSoccerBall();

	/** check if pawn is still alive */
	bool IsAlive() const;

	/** True if this player possesses the ball */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool PossessesBall();
};

