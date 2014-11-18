#pragma once

#include "GameFramework/Character.h"
#include "MagicBattleSoccerTypes.h"
#include "MagicBattleSoccerPlayer.generated.h"

class AMagicBattleSoccerGoal;
class AMagicBattleSoccerBall;
class AMagicBattleSoccerGameMode;
class AMagicBattleSoccerWeapon;
class AMagicBattleSoccerSpawnPoint;
class AMagicBattleSoccerGameState;
class ATriggerBox;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerPlayer : public ACharacter
{
	GENERATED_UCLASS_BODY()

	//////////////////////////////////////////////////////////////////////////
	// Player attributes

	/** The goal we want to kick the ball into. This should be replicated
	so that clients can detect who their enemies are based on their goal. */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal* EnemyGoal;

	/** The point where this player was spawned. This applies to all players
	(TODO: It doesn't apply to human players yet) */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerSpawnPoint* SpawnPoint;

	/** The max health this player has */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	float MaxHealth;

	/** The health this player has */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	float Health;

	/** current firing state */
	uint8 bWantsToFire : 1;

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

	/** The soccer ball that overlaps this player. Only relevant to the server
	because only the server does soccer ball collision detections. */
	AMagicBattleSoccerBall* OverlappingBall;

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

	/** The player's current weapon */
	UPROPERTY(Transient, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentWeapon, Category = Soccer)
	class AMagicBattleSoccerWeapon* CurrentWeapon;
	UFUNCTION()
	void OnRep_CurrentWeapon(class AMagicBattleSoccerWeapon* LastWeapon);

	//////////////////////////////////////////////////////////////////////////
	// AI

	/** The zone that this player is restricted to. This is only used for AI 
	so only the server should care about this value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	ATriggerBox* ActionZone;

	/** True if this player is running the attack action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	bool IsAttacking;

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

	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);

	UFUNCTION()
	void OnEndOverlap(AActor* OtherActor);

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

	/** updates current weapon */
	void SetCurrentWeapon(class AMagicBattleSoccerWeapon* NewWeapon, class AMagicBattleSoccerWeapon* LastWeapon = NULL);

	/** [server] spawns default inventory */
	void SpawnDefaultInventory();

	/** [server] remove all weapons from inventory and destroy them */
	void DestroyInventory();

	/** equip weapon */
	UFUNCTION(reliable, server, WithValidation)
	void ServerEquipWeapon(class AMagicBattleSoccerWeapon* NewWeapon);

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
	void EquipWeapon(class AMagicBattleSoccerWeapon* Weapon);

	//////////////////////////////////////////////////////////////////////////
	// Actions

	/** [local] starts weapon fire */
	void StartWeaponFire();

	/** [local] stops weapon fire */
	void StopWeaponFire();

	/** check if pawn can fire weapon */
	bool CanFire() const;

	/** [server] Updates the movement speed based on conditions (ball possessor, etc) */
	void UpdateMovementSpeed();

	/** [local] Kicks the ball in the forward direction */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallForward();

	/** [local] Kicks the ball to the specified location */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallToLocation(const FVector& Location);

	/** [local] Tries to kick ball into the goal. Returns true if the ball was kicked. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool KickBallToGoal();

	/** [local] Critical path for all kick functions */
	void KickBall(const FVector& Force);

	//////////////////////////////////////////////////////////////////////////
	// Actions - server side

	UFUNCTION(reliable, server, WithValidation)
	void ServerKickBall(FVector Force);

	//////////////////////////////////////////////////////////////////////////
	// Player attributes

	/** Gets the game mode (only the server should be interested in this) */
	AMagicBattleSoccerGameMode* GetGameMode();

	/** Gets the game state (all instances should be interested in this) */
	AMagicBattleSoccerGameState* GetGameState();

	/** Gets the soccer ball */
	AMagicBattleSoccerBall* GetSoccerBall();

	/** Gets all the teammates of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerPlayer*> GetTeammates();

	/** Gets all the opponents of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerPlayer*> GetOpponents();

	/** check if pawn is still alive */
	bool IsAlive() const;

	/** True if this player possesses the ball */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool PossessesBall();

	//////////////////////////////////////////////////////////////////////////
	// AI

	/** True if the player can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool CanBePursued();

	/** Clips the value n so that it will be within o+d and o-d */
	void ClipAxe(float& n, float o, float d);

	/** If this player is in their action zone, call this function to ensure the location will not leave the zone bounds */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector ClipToActionZone(const FVector& Location);

	/** Gets the closest actor between this player and a point */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore);

	/** Gets the closest enemy to this player that can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AMagicBattleSoccerPlayer* GetClosestOpponent();

	/** Gets the ideal teammate to pass the soccer ball to */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AMagicBattleSoccerPlayer* GetIdealPassMate();

	/** Gets the ideal object to run to if the player is idle */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetIdealPursuitTarget();

	/** Gets the ideal point to run to when not chasing another actor while following the ball possessor */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector GetIdealPossessorFollowLocation();

	/** Attacks a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void AttackPlayer(AMagicBattleSoccerPlayer* Target);

	/** Stops attacking a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void StopAttackingPlayer();
};

