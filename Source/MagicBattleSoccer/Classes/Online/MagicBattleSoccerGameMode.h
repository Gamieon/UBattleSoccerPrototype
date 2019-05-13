#pragma once

#include "GameFramework/GameMode.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerGameMode.generated.h"

class AMagicBattleSoccerBall;
class AMagicBattleSoccerGoal;

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 * A GameMode actor is instantiated when the level is initialized for gameplay in
 * C++ UGameEngine::LoadMap().  The class of this GameMode actor is determined by
 * (in order) either the URL ?game=xxx, or the
 * DefaultGameMode entry in the game's .ini file (in the /Script/Engine.Engine section).
 * The GameMode used can be overridden in the GameMode function GetGameModeClass(), called
 * on the game class picked by the above process.
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	/** Used by AMagicBattleSoccerPlayerState for naming bots */
	int NextBotNameID;

private:
	FTimerHandle TimerHandle_StartNextRoundTimer;

private:
	/** Gets the game state */
	class AMagicBattleSoccerGameState* GetGameState();

public:
	//Begin AGameMode interface

	/** Returns game session class to use */
	virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;

	/** called before startmatch */
	virtual void HandleMatchIsWaitingToStart() override;

	/** called to see if we should start the match */
	virtual bool ReadyToStartMatch();

	/** starts new match */
	virtual void HandleMatchHasStarted() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	//End AGameMode interface

	//////////////////////////////////////////////////////////////////////////
	// Round management

	/** Called internally to begin the next round. This is NOT a standard Unreal function. */
	void HandleRoundHasStarted();

	/** Called by the AMagicBattleSoccerGoal object when a goal was scored */
	void HandleGoalScored(AMagicBattleSoccerGoal *GoalContainingBall);

	/** Called internally to end the current round. This is NOT a standard Unreal function. */
	void HandleRoundHasEnded();

	/** Called internally to start the next round */
	void StartNextRound();

	//////////////////////////////////////////////////////////////////////////
	// Damage & death

	/** prevents friendly fire */
	virtual float ModifyDamage(float Damage, AActor* DamagedActor, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const;

	/** can players damage each other? */
	virtual bool CanDealDamage(AMagicBattleSoccerPlayerState* DamageInstigator, AMagicBattleSoccerPlayerState* DamagedPlayer) const;

	/** notify about kills */
	virtual void Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType);

	//////////////////////////////////////////////////////////////////////////
	// AI

	/** Determines whether a soccer player can be pursued by a bot */
	UFUNCTION(BlueprintCallable, Category = Soccer)
	bool CanBePursued(AMagicBattleSoccerCharacter* Player);
};
