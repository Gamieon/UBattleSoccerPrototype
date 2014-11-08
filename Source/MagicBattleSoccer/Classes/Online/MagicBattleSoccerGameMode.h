#pragma once

#include "GameFramework/GameMode.h"
#include "MagicBattleSoccerGameMode.generated.h"

class AMagicBattleSoccerBall;
class AMagicBattleSoccerGoal;
class AMagicBattleSoccerPlayer;

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

	/** The cache of all soccer players in the scene */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	TArray<AMagicBattleSoccerPlayer*> SoccerPlayers;

	/** The one and only soccer ball */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	AMagicBattleSoccerBall *SoccerBall;

	/** Team 1 goal */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	AMagicBattleSoccerGoal *Team1Goal;

	/** Team 2 goal */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	AMagicBattleSoccerGoal *Team2Goal;

	/** The penetrated goal */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Soccer)
	AMagicBattleSoccerGoal *PenetratedGoal;

	//Begin AActor interface

	/** This occurs when play ends */
	virtual void ReceiveEndPlay(EEndPlayReason::Type EndPlayReason) override;

	//End AActor interface

	//Begin AGameMode interface

	/** Returns game session class to use */
	virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;

	//End AGameMode interface
};
