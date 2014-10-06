

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerPlayer.h"

AMagicBattleSoccerGameMode::AMagicBattleSoccerGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = AMagicBattleSoccerPlayerController::StaticClass();
}

#pragma region Events

/** This occurs when play begins */
void AMagicBattleSoccerGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Cache the soccer players
	UWorld *world = GetWorld();
	for (TActorIterator<AMagicBattleSoccerPlayer> It(world); It; ++It)
	{
		this->SoccerPlayers.Add(*It);
	}

	// Cache the soccer ball
	for (TActorIterator<AMagicBattleSoccerBall> It(world); It; ++It)
	{
		this->SoccerBall = *It;
		break; // There should only ever be one. If there is more, we only cache the first one
	}

	// Cache our goals
	for (TActorIterator<AMagicBattleSoccerGoal> It(world); It; ++It)
	{
		FString name = *It->GetName();
		if (0 == name.Compare("Team1Goal"))
		{
			this->Team1Goal = *It;
		}
		else if (0 == name.Compare("Team2Goal"))
		{
			this->Team2Goal = *It;
		}
	}
	PenetratedGoal = NULL;
}

#pragma endregion
