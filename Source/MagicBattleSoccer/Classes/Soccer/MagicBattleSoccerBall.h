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
	class AMagicBattleSoccerCharacter *Possessor;

	/** The player who last possessed this soccer ball */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerCharacter *LastPossessor;

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
	void ClientSimulateFreeMovingBall();

public:
	//Begin AActor interface

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	void Tick(float DeltaSeconds) override;

	//End AActor interface

	/** Called by the GameMode object when the next round has begun */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void RoundHasStarted();

	/** Called by a AMagicBattleSoccerCharacter object when it has been destroyed */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void CharacterHasDestroyed(AMagicBattleSoccerCharacter *Character);

	/** Gets the game state */
	class AMagicBattleSoccerGameState* GetGameState();

	/** True if the ball has no possessor and is not in a goal. Should only be called by the authority entity. */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool IsFree();

	/** True if the player can possess the ball */
	bool CanPossessBall(AMagicBattleSoccerCharacter* Player);

	/** When a possessor releases the ball, we don't want to allow them to repossess the ball until it has
	travelled a certain distance away. This variable lets the ball remember who possessed the ball last so
	it can do this calculation. Once the distance has been exceeded, this is set to null. */
	class AMagicBattleSoccerCharacter *PossessorToIgnore;

	/** Sets the current ball possessor */
	void SetPossessor(class AMagicBattleSoccerCharacter* Player);

	/** Move with the possessing player */
	void MoveWithPossessor();

	/** Kicks this ball with a given force */
	void Kick(const FVector& Force);

	/** Kicks this ball to a location */
	void KickToLocation(const FVector& Location, float AngleInDegrees);
};

