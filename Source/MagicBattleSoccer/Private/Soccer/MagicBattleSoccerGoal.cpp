
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerCharacter.h"

AMagicBattleSoccerGoal::AMagicBattleSoccerGoal(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

/** Gets the game state */
AMagicBattleSoccerGameState* AMagicBattleSoccerGoal::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
}

/** Called from the blueprint when the ball enters the goal */
void AMagicBattleSoccerGoal::HandleBallEnteredGoal()
{
	if (ROLE_Authority > Role)
	{
		// We should never get here since only the server should detect the soccer ball entering the goal!
	}
	else
	{
		AMagicBattleSoccerGameState* GameState = GetGameState();
		if (nullptr != GameState->PenetratedGoal)
		{
			// The ball already penetrated the goal; don't forward the call.
		}
		else
		{
			// Forward the call to the game mode object
			AMagicBattleSoccerGameMode *GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
			GameMode->HandleGoalScored(this);
		}
	}
}

/** Gets the ideal point for a player to run to when approaching the goal */
FVector AMagicBattleSoccerGoal::GetIdealRunLocation(AMagicBattleSoccerCharacter* Player)
{
	FVector GoalLocation = GetActorLocation();
	FVector FrontOfGoal = GoalLocation + GetActorRightVector() * 570.0f;
	if (nullptr == Player)
	{
		return FVector(FrontOfGoal.X, FrontOfGoal.Y, 0.f);
	}
	else
	{
		return FVector(FrontOfGoal.X, FrontOfGoal.Y, Player->GetActorLocation().Z);
	}
}

/** This occurs when play begins */
void AMagicBattleSoccerGoal::BeginPlay()
{
	Super::BeginPlay();

	if (ROLE_Authority == Role)
	{
		// Servers should add this goal to the game mode cache
		AMagicBattleSoccerGameState* GameState = GetGameState();
		if (1 == TeamNumber)
		{
			GameState->Team1Goal = this;
		}
		else if (2 == TeamNumber)
		{
			GameState->Team2Goal = this;
		}
	}
	else
	{
		// The server manages the game state; the goals will be replicated to us.
	}
}