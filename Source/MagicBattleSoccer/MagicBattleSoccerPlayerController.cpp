

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerGoal.h"

AMagicBattleSoccerPlayerController::AMagicBattleSoccerPlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

bool AMagicBattleSoccerPlayerController::FindDeathCameraSpot(FVector& CameraLocation, FRotator& CameraRotation)
{
	const FVector PawnLocation = GetPawn()->GetActorLocation();
	FRotator ViewDir = GetControlRotation();
	ViewDir.Pitch = -45.0f;

	const float YawOffsets[] = { 0.0f, -180.0f, 90.0f, -90.0f, 45.0f, -45.0f, 135.0f, -135.0f };
	const float CameraOffset = 600.0f;
	FCollisionQueryParams TraceParams(TEXT("DeathCamera"), true, GetPawn());

	for (int32 i = 0; i < ARRAY_COUNT(YawOffsets); i++)
	{
		FRotator CameraDir = ViewDir;
		CameraDir.Yaw += YawOffsets[i];
		CameraDir.Normalize();

		const FVector TestLocation = PawnLocation - CameraDir.Vector() * CameraOffset;
		const bool bBlocked = GetWorld()->LineTraceTest(PawnLocation, TestLocation, ECC_Camera, TraceParams);

		if (!bBlocked)
		{
			CameraLocation = TestLocation;
			CameraRotation = CameraDir;
			return true;
		}
	}

	return false;
}

void AMagicBattleSoccerPlayerController::SetPawn(APawn* inPawn)
{
	Super::SetPawn(inPawn);

	if (NULL != inPawn)
	{
		AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(inPawn);

		// For now default to team 1
		for (TObjectIterator<AMagicBattleSoccerGoal> It; It; ++It)
		{
			if (2 == It->TeamNumber)
			{
				PlayerPawn->EnemyGoal = *It;
				break;
			}
		}
	}
}

void AMagicBattleSoccerPlayerController::PawnPendingDestroy(APawn* inPawn)
{
	LastDeathLocation = inPawn->GetActorLocation();
	FVector CameraLocation = LastDeathLocation + FVector(0, 0, 600.0f);
	FRotator CameraRotation(-90.0f, 0.0f, 0.0f);
	FindDeathCameraSpot(CameraLocation, CameraRotation);

	Super::PawnPendingDestroy(inPawn);

	SetInitialLocationAndRotation(CameraLocation, CameraRotation);
	SetViewTarget(this);
}

