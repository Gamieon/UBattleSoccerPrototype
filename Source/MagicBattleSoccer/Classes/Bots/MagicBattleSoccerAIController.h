

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

	/** The zone that this player is restricted to. This is only used for AI
	so only the server should care about this value. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	class ATriggerBox* ActionZone;

	/** True if this player is running the attack action */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	bool IsAttacking;

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
	TArray<class AMagicBattleSoccerPlayer*> GetTeammates();

	/** Gets all the opponents of this player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<class AMagicBattleSoccerPlayer*> GetOpponents();

	/** Gets the closest actor between this player and a point */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetClosestActorObstructingPoint(const FVector& Point, const TArray<AActor*>& ActorsToIgnore);

	/** Gets the closest enemy to this player that can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	class AMagicBattleSoccerPlayer* GetClosestOpponent();

	/** Gets the ideal teammate to pass the soccer ball to */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	class AMagicBattleSoccerPlayer* GetIdealPassMate();

	/** Gets the ideal object to run to if the player is idle */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AActor* GetIdealPursuitTarget();

	/** Gets the ideal point to run to when not chasing another actor while following the ball possessor */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector GetIdealPossessorFollowLocation();

	/** Attacks a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void AttackPlayer(class AMagicBattleSoccerPlayer* Target);

	/** Stops attacking a soccer player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void StopAttackingPlayer();

	/** Tries to kick ball into the goal. Returns true if the ball was kicked. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool KickBallToGoal();

	/** Kicks the ball to the specified location */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void KickBallToLocation(const FVector& Location);
};
