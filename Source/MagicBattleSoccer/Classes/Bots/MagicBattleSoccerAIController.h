

#pragma once

#include "AIController.h"
#include "MagicBattleSoccerAIController.generated.h"

/**
 * 
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerAIController : public AAIController
{
	GENERATED_UCLASS_BODY()

private:
	/** Gets the game state */
	class AMagicBattleSoccerGameState* GetGameState();

public:
	/** The spawn point where the character should spawn. */
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	class AMagicBattleSoccerSpawnPoint* SpawnPoint;

	/** The zone that this player is restricted to. This is only used for AI
	so only the server should care about this value. */
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	class ATriggerBox* ActionZone;

	/** True if this player is running the attack action */
	UPROPERTY(Transient, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	bool IsAttacking;

	/** Called by the GameMode object when the next round has begun. The character has not yet spawned at this point */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void RoundHasStarted();

	/** Called by the GameMode object when the current round has ended */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void RoundHasEnded();

	/** Determines whether the character can be spawned at this time */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool CanSpawnCharacter();

	/** Spawns the character */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void SpawnCharacter();

	//Begin AController interface

	/** respawn after pawn dies */
	virtual void PawnPendingDestroy(APawn* inPawn) override;

	//End AController interface

public:
	//////////////////////////////////////////////////////////////////////////
	// AI

	/** True if the player can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool CanBePursued();

	/** The goal we want to kick the ball into */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	class AMagicBattleSoccerGoal* GetEnemyGoal();

	/** Clips the value n so that it will be within o+d and o-d */
	void ClipAxe(float& n, float o, float d);

	/** If this player is in their action zone, call this function to ensure the location will not leave the zone bounds */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector ClipToActionZone(const FVector& Location);

	/** Gets all the teammates of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<class AMagicBattleSoccerCharacter*> GetTeammates();

	/** Gets all the opponents of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<class AMagicBattleSoccerCharacter*> GetOpponents();

	/** Gets the closest actor between this player and a point */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore);

	/** Gets the closest enemy to this player that can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	class AMagicBattleSoccerCharacter* GetClosestOpponent();

	/** Gets the ideal teammate to pass the soccer ball to */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	class AMagicBattleSoccerCharacter* GetIdealPassMate();

	/** Gets the ideal object to run to if the player is idle */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetIdealPursuitTarget();

	/** Gets the ideal point to run to when not chasing another actor while following the ball possessor */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector GetIdealPossessorFollowLocation();

	/** Attacks a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void AttackPlayer(class AMagicBattleSoccerCharacter* Target);

	/** Stops attacking a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void StopAttackingPlayer();

	/** Tries to kick ball into the goal. Returns true if the ball was kicked. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool KickBallToGoal();

	/** Kicks the ball to the specified location */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallToLocation(const FVector& Location, float AngleInDegrees);
};
