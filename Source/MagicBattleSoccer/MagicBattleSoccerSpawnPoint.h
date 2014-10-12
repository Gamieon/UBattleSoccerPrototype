#pragma once

#include "Engine/TargetPoint.h"
#include "MagicBattleSoccerSpawnPoint.generated.h"

class AMagicBattleSoccerGoal;
class AMagicBattleSoccerPlayer;

/**
*
*/
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerSpawnPoint : public ATargetPoint
{
	GENERATED_UCLASS_BODY()

	/** The enemy goal to assign to the spawned soccer player */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal* EnemyGoal;

	/** The zone that the spawned player is restricted to */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	ATriggerBox* ActionZone;

	/** The maximum number of players to spawn on the field */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 MaxPlayersOnField;

	/** The current number of players on the field */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 NumberOfPlayersOnField;

	/** Called by the GameMode object when a spawned player is about to be destroyed */
	UFUNCTION(BlueprintNativeEvent, Category = Soccer)
	void SpawnedPlayerBeingDestroyed(AMagicBattleSoccerPlayer* SoccerPlayer);
};
