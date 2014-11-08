#pragma once

#include "GameFramework/Character.h"
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

	/** The last time that this player possessed the ball */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	float LastBallPossessionTime;

	/** The goal we want to kick the ball into */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal* EnemyGoal;

	/** The zone that this player is restricted to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	ATriggerBox* ActionZone;

	/** The point where this player was spawned */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerSpawnPoint* SpawnPoint;

	/** The max number of hitpoints this player has */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 MaxHitpoints;

	/** The number of hitpoints this player has */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	int32 Hitpoints;

	/** True if this player is running the attack action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	bool IsAttacking;

	/** True if this player is stunned */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	bool IsStunned;

	/** The player's default weapon template */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	UBlueprint* DefaultWeaponBlueprint;

	/** The player's current weapon */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerWeapon* CurrentWeapon;

	/** Gets the game mode (only the authority instance should be interested in this) */
	AMagicBattleSoccerGameMode* GetGameMode();

	/** Gets the game state (all instances should be interested in this) */
	AMagicBattleSoccerGameState* GetGameState();

	/** Gets the soccer ball */
	AMagicBattleSoccerBall* GetSoccerBall();

	/** Updates the movement speed based on conditions (ball possessor, stunned, etc) */
	void UpdateMovementSpeed();

	/** Gets all the teammates of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerPlayer*> GetTeammates();

	/** Gets all the opponents of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerPlayer*> GetOpponents();

	/** True if this player possesses the ball */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool PossessesBall();

	/** True if the player can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool CanBePursued();

	/** Kicks the ball in the forward direction */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallForward();

	/** Kicks the ball to the specified location */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallToLocation(const FVector& Location);

	/** Tries to kick ball into the goal. Returns true if the ball was kicked. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool KickBallToGoal();

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

	/** Stops attacking */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void CeaseFire();

	/** Gives a weapon to the player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void GiveWeapon(AMagicBattleSoccerWeapon* Weapon);

	/** Stuns this player */
	void Stun(float Duration);

	/** The default movement speed for this player. Initially assigned the max walking speed. */
	float DefaultMovementSpeed;

	/** The time to unstun this player */
	float StunReleaseTime;

	/** The soccer ball that overlaps this player */
	AMagicBattleSoccerBall* OverlappingBall;

	UFUNCTION()
	void OnBeginOverlap(AActor* OtherActor);

	UFUNCTION()
	void OnEndOverlap(AActor* OtherActor);

	//Begin AActor interface

	void Tick(float DeltaSeconds) override;

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	/** This occurs when play ends */
	virtual void ReceiveEndPlay(EEndPlayReason::Type EndPlayReason) override;

	/** This occurs when the player is destroyed */
	virtual void Destroyed() override;

	//End AActor interface
};

