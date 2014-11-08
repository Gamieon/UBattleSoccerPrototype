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

	/** The cache of all soccer players in the scene. */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	TArray<class AMagicBattleSoccerPlayer*> SoccerPlayers;

	/** The one and only soccer ball. Cached locally for all sessions */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerBall *SoccerBall;

	/** Team 1 goal. Cached locally for all sessions */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team1Goal;

	/** Team 2 goal. Cached locally for all sessions */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team2Goal;

	/** The penetrated goal */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal *PenetratedGoal;
};
