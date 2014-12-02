#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerGoal.generated.h"

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGoal : public AActor
{
	GENERATED_UCLASS_BODY()

	/** Gets the game state (all instances should be interested in this) */
	class AMagicBattleSoccerGameState* GetGameState();

	/** Gets the ideal point for a player to run to when approaching the goal */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	FVector GetIdealRunLocation(class AMagicBattleSoccerCharacter* Player);

	/** The goal's owning team number */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 TeamNumber;
	
	//Begin AActor interface

	/** This occurs when play begins */
	virtual void BeginPlay() override;

	//End AActor interface
};
