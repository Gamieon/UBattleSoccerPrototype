

#pragma once

#include "GameFramework/GameState.h"
#include "MagicBattleSoccerGameState.generated.h"

/**
 * GameState is replicated and is valid on servers and clients.
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGameState : public AGameState
{
	GENERATED_UCLASS_BODY()

	/** The cache of all soccer players in the scene. Cached locally for all sessions; including servers and clients */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	TArray<class AMagicBattleSoccerPlayer*> SoccerPlayers;

	/** The one and only soccer ball. Cached locally for all sessions; including servers and clients */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerBall *SoccerBall;

	/** Team 1 goal. Cached locally for all sessions; including servers and clients */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team1Goal;

	/** Team 2 goal. Cached locally for all sessions; including servers and clients */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team2Goal;
};
