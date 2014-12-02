#pragma once

#include "Engine/TargetPoint.h"
#include "MagicBattleSoccerSpawnPoint.generated.h"

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerSpawnPoint : public ATargetPoint
{
	GENERATED_UCLASS_BODY()

	/** The enemy goal to assign to the spawned soccer player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 BotTeamNumber;

	/** The zone that the spawned player is restricted to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	class ATriggerBox* ActionZone;

	/** The maximum number of players to spawn on the field */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 MaxPlayersOnField;

	/** Called by the GameMode object when a spawned player is about to be destroyed */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void SpawnedPlayerBeingDestroyed(class AMagicBattleSoccerAIController* Controller);
};
