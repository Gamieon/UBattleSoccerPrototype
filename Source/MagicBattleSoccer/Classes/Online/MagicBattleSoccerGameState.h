#pragma once

#include "GameFramework/GameState.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerPlayerState.h"
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
	TArray<class AMagicBattleSoccerCharacter*> SoccerPlayers;

	/** The one and only soccer ball. Cached locally for all sessions */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerBall *SoccerBall;

	/** Team 1 goal. Cached locally for all sessions */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team1Goal;

	/** Team 2 goal. Cached locally for all sessions */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerGoal *Team2Goal;

	/** Team 1 soccer ball spawn point. Cached locally for all sessions */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerSpawnPoint *Team1SoccerBallSpawnPoint;

	/** Team 2 soccer ball spawn point. Cached locally for all sessions */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	class AMagicBattleSoccerSpawnPoint *Team2SoccerBallSpawnPoint;

	/** Team 1 score */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	int32 Team1Score;

	/** Team 2 score */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	int32 Team2Score;

	/** The penetrated goal */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal *PenetratedGoal;

	/** True if a round is in progress; false if we're in between rounds */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	bool RoundInProgress;

	/** Gets all the teammate controllers of a specified player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<class AController*> GetTeammateControllers(AMagicBattleSoccerPlayerState* PlayerState);

	/** Gets all the teammates of a specified player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerCharacter*> GetTeammates(AMagicBattleSoccerPlayerState* PlayerState);

	/** Gets all the opponents of a specified player */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	TArray<AMagicBattleSoccerCharacter*> GetOpponents(AMagicBattleSoccerPlayerState* PlayerState);

	/** Gets the closest opponent */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AMagicBattleSoccerCharacter* GetClosestOpponent(AMagicBattleSoccerCharacter* Player);

	/** Gets the closest enemy to a world location that can be pursued */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	AMagicBattleSoccerCharacter* GetClosestOpponentToLocation(AMagicBattleSoccerCharacter* Player, FVector Location);

	/** Called when the state transitions to WaitingToStart */
	virtual void HandleMatchIsWaitingToStart();

	/** Called when the state transitions to InProgress */
	virtual void HandleMatchHasStarted();

	/** Populates the goals and ball spawn point members with values */
	void EnsureGameStateActors();
};
