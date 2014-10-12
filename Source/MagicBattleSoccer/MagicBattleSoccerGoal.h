#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerGoal.generated.h"

class AMagicBattleSoccerPlayer;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGoal : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Gets the ideal point for a player to run to when approaching the goal */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector GetIdealRunLocation(AMagicBattleSoccerPlayer* Player);

#pragma region Events

	/** This occurs when play begins */
	virtual void BeginPlay() override;

#pragma endregion
};
