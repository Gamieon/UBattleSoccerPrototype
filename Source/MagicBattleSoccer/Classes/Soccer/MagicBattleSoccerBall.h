#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerBall.generated.h"

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerBall : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Gets the game state (all instances should be interested in this) */
	class AMagicBattleSoccerGameState* GetGameState();

	/** The player that possesses this soccer ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerPlayer *Possessor;

	/** True if the ball has no possessor and is not in a goal. Should only be called by the authority entity. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool IsFree();

	/** The time this soccer ball was last released from a player */
	float LastReleaseTime;

	/** The negative distance travelled since creation */
	float NegDistanceTravelled;

	/** Sets the current ball possessor */
	void SetPossessor(class AMagicBattleSoccerPlayer* Player);

	/** Kicks this ball with a given force */
	void Kick(const FVector& Force);

	/** Move with the possessing player */
	void MoveWithPossessor();

	//Begin AActor interface

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds) override;

	//End AActor interface
};

