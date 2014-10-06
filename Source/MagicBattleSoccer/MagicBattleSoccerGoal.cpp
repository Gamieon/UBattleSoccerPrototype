
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerPlayer.h"

AMagicBattleSoccerGoal::AMagicBattleSoccerGoal(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

/** Gets the ideal point for a player to run to when approaching the goal */
FVector AMagicBattleSoccerGoal::GetIdealRunLocation(AMagicBattleSoccerPlayer* Player)
{
	FVector GoalLocation = GetActorLocation();
	FVector FrontOfGoal = GoalLocation + GetActorRightVector() * 570.0f;
	return FVector(FrontOfGoal.X, FrontOfGoal.Y, Player->GetActorLocation().Z);
}

