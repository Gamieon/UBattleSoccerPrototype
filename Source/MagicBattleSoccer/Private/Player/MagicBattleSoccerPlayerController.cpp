

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerGameMode.h"
#include <chrono>

using namespace std::chrono;

AMagicBattleSoccerPlayerController::AMagicBattleSoccerPlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	timeServerTimeRequestWasPlaced = 0;
	timeOffsetFromServer = 0;
	timeOffsetIsValid = false;
}

/** Gets the current system time in milliseconds */
/* static */ int64 AMagicBattleSoccerPlayerController::GetLocalTime()
{
	milliseconds ms = duration_cast< milliseconds >(
		high_resolution_clock::now().time_since_epoch()
		);
	return (int64)ms.count();
}

/** True if the network time is valid. */
bool AMagicBattleSoccerPlayerController::IsNetworkTimeValid()
{
	return timeOffsetIsValid;
}

/** Gets the approximate current network time in milliseconds. */
int64 AMagicBattleSoccerPlayerController::GetNetworkTime()
{
	return GetLocalTime() + timeOffsetFromServer;
}

void AMagicBattleSoccerPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// UI input
	InputComponent->BindAxis("MoveForward", this, &AMagicBattleSoccerPlayerController::OnMoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMagicBattleSoccerPlayerController::OnMoveRight);
	InputComponent->BindAction("PrimaryAction", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnStartPrimaryAction);
	InputComponent->BindAction("PrimaryAction", IE_Released, this, &AMagicBattleSoccerPlayerController::OnStopPrimaryAction);
	InputComponent->BindAction("Suicide", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnSuicide);
	InputComponent->BindAction("Respawn", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnRespawn);
}

void AMagicBattleSoccerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Ask the server for its current time
	if (Role < ROLE_Authority)
	{
		timeServerTimeRequestWasPlaced = GetLocalTime();
		ServerGetServerTime();
	}
}

void AMagicBattleSoccerPlayerController::SetPawn(APawn* inPawn)
{
	Super::SetPawn(inPawn);

	if (nullptr != inPawn)
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

//////////////////////////////////////////////////////////////////////////
// Input handlers

/** Player move forward event */
void AMagicBattleSoccerPlayerController::OnMoveForward(float axisValue)
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(1, 0, 0), axisValue);
	}
}

/** Player move right event */
void AMagicBattleSoccerPlayerController::OnMoveRight(float axisValue)
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(0, 1, 0), axisValue);
	}
}

/** Player primary action event */
void AMagicBattleSoccerPlayerController::OnStartPrimaryAction()
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		if (PlayerPawn->PossessesBall())
		{
			PlayerPawn->KickBallForward();
		}
		else if (nullptr != PlayerPawn->CurrentWeapon)
		{
			PlayerPawn->StartWeaponFire();
		}
	}
}

/** Player primary action event */
void AMagicBattleSoccerPlayerController::OnStopPrimaryAction()
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->StopWeaponFire();
	}
}


/** Player suicide event */
void AMagicBattleSoccerPlayerController::OnSuicide()
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	PlayerPawn->Destroy();
}

/** Player respawn event */
void AMagicBattleSoccerPlayerController::OnRespawn()
{
	AMagicBattleSoccerPlayer* PlayerPawn = Cast<AMagicBattleSoccerPlayer>(GetPawn());
	if (nullptr == PlayerPawn)
	{
		ServerRestartPlayer();
	}
}

/** Sent from a client to the server to get the server's system time */
void AMagicBattleSoccerPlayerController::ServerGetServerTime_Implementation()
{
	ClientGetServerTime(GetLocalTime());
}

bool AMagicBattleSoccerPlayerController::ServerGetServerTime_Validate()
{
	return true;
}

/** Sent from the server to a client to give them the server's system time */
void AMagicBattleSoccerPlayerController::ClientGetServerTime_Implementation(int64 serverTime)
{
	int64 localTime = GetLocalTime();

	// Calculate the server's system time at the moment we actually sent the request for it.
	int64 roundTripTime = localTime - timeServerTimeRequestWasPlaced;
	serverTime -= roundTripTime;

	// Now calculate the difference between the two values
	if (timeServerTimeRequestWasPlaced > serverTime)
	{
		// We are in the "future," so the offset should be negative
		timeOffsetFromServer = -(int64)(timeServerTimeRequestWasPlaced - serverTime);
	}
	else
	{
		// We are in the "past" (or "present"), so the offset should be non-negative
		timeOffsetFromServer = (serverTime - timeServerTimeRequestWasPlaced);
	}

	// Now we can safely say that the following is true
	//
	// time = timeServerTimeRequestWasPlaced + timeOffsetFromServer
	//
	// which is another way of saying
	//
	// NetworkTime = LocalTime + timeOffsetFromServer

	timeOffsetIsValid = true;
}
