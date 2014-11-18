#pragma once

#include "GameFramework/Actor.h"
#include "SmoothPhysicsState.h"
#include "MagicBattleSoccerBall.generated.h"

#define PROXY_STATE_ARRAY_SIZE 20
/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerBall : public AActor
{
	GENERATED_UCLASS_BODY()

	/** The player that possesses this soccer ball */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerPlayer *Possessor;

	/** The soccer ball orientation on the server */
	UPROPERTY(ReplicatedUsing = OnRep_ServerPhysicsState)
	FSmoothPhysicsState ServerPhysicsState;
	UFUNCTION()
	void OnRep_ServerPhysicsState();

	/** The negative distance travelled since creation. Maintained locally. */
	float NegDistanceTravelled;

private:
	/** Clients store twenty states with "playback" information from the server. This
	array contains the official state of this object at different times according to
	the server. */
	FSmoothPhysicsState proxyStates[PROXY_STATE_ARRAY_SIZE];

	/** Keep track of what slots are used */
	int proxyStateCount;

private:
	/** Simulates the free movement of the ball based on proxy states */
	void ClientSimulatePhysicsMovement();

public:
	//Begin AActor interface

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds) override;

	//End AActor interface

	/** Gets the game state (all instances should be interested in this) */
	class AMagicBattleSoccerGameState* GetGameState();

	/** True if the ball has no possessor and is not in a goal. Should only be called by the authority entity. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool IsFree();

	/** The time this soccer ball was last released from a player */
	float LastReleaseTime;

	/** Sets the current ball possessor */
	void SetPossessor(class AMagicBattleSoccerPlayer* Player);

	/** Move with the possessing player */
	void MoveWithPossessor();

	/** Kicks this ball with a given force */
	void Kick(const FVector& Force);
};

