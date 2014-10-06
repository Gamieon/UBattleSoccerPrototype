#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerBall.generated.h"

class AMagicBattleSoccerPlayer;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerBall : public AActor
{
	GENERATED_UCLASS_BODY()

	/** The player that possesses this soccer ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	AMagicBattleSoccerPlayer *Possessor;

	/** True if the ball has no possessor and is not in a goal. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool IsFree();

	/** The time this soccer ball was last released from a player */
	float LastReleaseTime;

	/** The negative distance travelled since creation */
	float NegDistanceTravelled;

	/** Sets the current ball possessor */
	void SetPossessor(AMagicBattleSoccerPlayer* Player);

	/** Kicks this ball with a given force */
	void Kick(const FVector& Force);

private:
	/** Move with the possessing player */
	void MoveWithPossessor();

	void Tick(float DeltaSeconds) override;
};

