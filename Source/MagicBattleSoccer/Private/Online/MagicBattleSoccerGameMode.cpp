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

#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccerGameSession.h"
#include "MagicBattleSoccerHUD.h"

AMagicBattleSoccerGameMode::AMagicBattleSoccerGameMode(const class FObjectInitializer& OI)
	: Super(OI)
{
	// Assign the in-game player controller class
	PlayerControllerClass = AMagicBattleSoccerPlayerController::StaticClass();

	// Assign the player state class. Player-specific variables will persist during the game even if levels change
	PlayerStateClass = AMagicBattleSoccerPlayerState::StaticClass();

	// Assign the HUD class
	HUDClass = AMagicBattleSoccerHUD::StaticClass();

	// Used by AMagicBattleSoccerPlayerState for naming bots
	NextBotNameID = 1;
}

/** Gets the game state */
AMagicBattleSoccerGameState* AMagicBattleSoccerGameMode::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
}

/** Returns game session class to use */
TSubclassOf<AGameSession> AMagicBattleSoccerGameMode::GetGameSessionClass() const
{
	return AMagicBattleSoccerGameSession::StaticClass();
}

/** called before startmatch */
void AMagicBattleSoccerGameMode::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();
}

/** called to see if we should start the match */
bool AMagicBattleSoccerGameMode::ReadyToStartMatch()
{
	return Super::ReadyToStartMatch();
}

/** starts new match */
void AMagicBattleSoccerGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();

	// Now that the match has started, start the round
	HandleRoundHasStarted();
}

void AMagicBattleSoccerGameMode::PostLogin(APlayerController* NewPlayer)
{
	// Place player on a team before Super (VoIP team based init, findplayerstart, etc).
	// This is never called for bots.
	// TODO: Let the player choose their team
	AMagicBattleSoccerPlayerState* NewPlayerState = CastChecked<AMagicBattleSoccerPlayerState>(NewPlayer->PlayerState);
	NewPlayerState->TeamNumber = 1;

	Super::PostLogin(NewPlayer);
}

//////////////////////////////////////////////////////////////////////////
// Round management

/** Called internally to begin the next round. This is NOT a standard Unreal function. */
void AMagicBattleSoccerGameMode::HandleRoundHasStarted()
{
	AMagicBattleSoccerGameState *GameState = GetGameState();
	// Ensure the round is flagged as not in progress until everyone has spawned
	GameState->RoundInProgress = false;

	// Wipe all soccer characters off the field
	for (TObjectIterator<AMagicBattleSoccerCharacter> Itr; Itr; ++Itr)
	{
		Itr->Destroy();
	}

	// Now we're officially in progress
	GameState->RoundInProgress = true;

	// Notify all AI controllers that the round has started
	for (TObjectIterator<AMagicBattleSoccerAIController> Itr; Itr; ++Itr)
	{
		Itr->RoundHasStarted();
	}

	// Notify all spawn points that the round has started
	for (TObjectIterator<AMagicBattleSoccerSpawnPoint> Itr; Itr; ++Itr)
	{
		Itr->RoundHasStarted();
	}

	// Spawn all the human players
	for (TObjectIterator<AMagicBattleSoccerPlayerController> Itr; Itr; ++Itr)
	{
		Itr->SpawnCharacter();
	}

	// Reset the ball position
	if (nullptr == GameState->PenetratedGoal)
	{
		GameState->SoccerBall->SetActorLocation(FVector(0.f, 0.f, 40.f));
	}
	else if (GameState->PenetratedGoal->TeamNumber == 1)
	{
		GameState->SoccerBall->SetActorLocation(GameState->Team1SoccerBallSpawnPoint->GetActorLocation());
	}
	else if (GameState->PenetratedGoal->TeamNumber == 2)
	{
		GameState->SoccerBall->SetActorLocation(GameState->Team2SoccerBallSpawnPoint->GetActorLocation());
	}
	else
	{
		// Unexpected case; just center the ball
		GameState->SoccerBall->SetActorLocation(FVector(0.f, 0.f, 40.f));
	}

	// Ensure the ball has no possessor and move it to the center of the map
	GameState->SoccerBall->RoundHasStarted();

	// Ensure there is no penetrated goal
	GameState->PenetratedGoal = nullptr;
}

/** Called by the AMagicBattleSoccerGoal object when a goal was scored */
void AMagicBattleSoccerGameMode::HandleGoalScored(AMagicBattleSoccerGoal *GoalContainingBall)
{	
	AMagicBattleSoccerGameState *GameState = GetGameState();

	// Assign the penetrated goal
	if (nullptr != GameState->PenetratedGoal)
	{
		// We should never get here because we already handled a goal score in this round!
	}
	else
	{
		GameState->PenetratedGoal = GoalContainingBall;

		// Change the scores
		if (1 == GoalContainingBall->TeamNumber)
		{
			GameState->Team2Score++;
		}
		else
		{
			GameState->Team1Score++;
		}

		// The round is now over
		HandleRoundHasEnded();
	}
}

/** Called internally to end the current round. This is NOT a standard Unreal function. */
void AMagicBattleSoccerGameMode::HandleRoundHasEnded()
{
	AMagicBattleSoccerGameState *GameState = GetGameState();

	// Flag the round as over
	GameState->RoundInProgress = false;

	// Notify all AI controllers that the round has ended
	for (TObjectIterator<AMagicBattleSoccerAIController> Itr; Itr; ++Itr)
	{
		Itr->RoundHasEnded();
	}

	// Start a timer to begin the next round
	GetWorldTimerManager().SetTimer(TimerHandle_StartNextRoundTimer, this, &AMagicBattleSoccerGameMode::StartNextRound, 3.f);
}

void AMagicBattleSoccerGameMode::StartNextRound()
{
	if (GetMatchState() != MatchState::InProgress)
	{
		// Although a round is currently not in progress, the match itself should still be in progress.
	}
	else
	{
		HandleRoundHasStarted();
	}
}

//////////////////////////////////////////////////////////////////////////
// Damage & death

float AMagicBattleSoccerGameMode::ModifyDamage(float Damage, AActor* DamagedActor, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const
{
	float ActualDamage = Damage;

	AMagicBattleSoccerCharacter* DamagedPawn = Cast<AMagicBattleSoccerCharacter>(DamagedActor);
	if (DamagedPawn && EventInstigator)
	{
		AMagicBattleSoccerPlayerState* DamagedPlayerState = Cast<AMagicBattleSoccerPlayerState>(DamagedPawn->PlayerState);
		AMagicBattleSoccerPlayerState* InstigatorPlayerState = Cast<AMagicBattleSoccerPlayerState>(EventInstigator->PlayerState);

		// disable friendly fire
		if (!CanDealDamage(InstigatorPlayerState, DamagedPlayerState))
		{
			ActualDamage = 0.0f;
		}
	}

	return ActualDamage;
}

bool AMagicBattleSoccerGameMode::CanDealDamage(AMagicBattleSoccerPlayerState* DamageInstigator, AMagicBattleSoccerPlayerState* DamagedPlayer) const
{
	// Prevent friendly damage and self damage
	if (nullptr == DamageInstigator)
	{
		// Environmental damge
		return true;
	}
	else
	{
		return DamageInstigator && DamagedPlayer && (DamagedPlayer->TeamNumber != DamageInstigator->TeamNumber);
	}
}

void AMagicBattleSoccerGameMode::Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType)
{
	/*
	AMagicBattleSoccerPlayerState* KillerPlayerState = Killer ? Cast<AMagicBattleSoccerPlayerState>(Killer->PlayerState) : NULL;
	AMagicBattleSoccerPlayerState* VictimPlayerState = KilledPlayer ? Cast<AMagicBattleSoccerPlayerState>(KilledPlayer->PlayerState) : NULL;

	if (KillerPlayerState && KillerPlayerState != VictimPlayerState)
	{
		KillerPlayerState->ScoreKill(VictimPlayerState, KillScore);
		KillerPlayerState->InformAboutKill(KillerPlayerState, DamageType, VictimPlayerState);
	}

	if (VictimPlayerState)
	{
		VictimPlayerState->ScoreDeath(KillerPlayerState, DeathScore);
		VictimPlayerState->BroadcastDeath(KillerPlayerState, DamageType, VictimPlayerState);
	}*/
}

/** Determines whether a soccer player can be pursued by a bot */
bool AMagicBattleSoccerGameMode::CanBePursued(AMagicBattleSoccerCharacter* Player)
{
	return true;
}
