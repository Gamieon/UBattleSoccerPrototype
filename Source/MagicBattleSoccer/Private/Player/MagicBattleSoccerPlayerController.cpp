#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerGameMode.h"
#include <chrono>

using namespace std::chrono;

AMagicBattleSoccerPlayerController::AMagicBattleSoccerPlayerController(const class FObjectInitializer& OI)
	: Super(OI)
{
	timeServerTimeRequestWasPlaced = 0;
	timeOffsetFromServer = 0;
	timeOffsetIsValid = false;
}

/** Gets the game state */
AMagicBattleSoccerGameState* AMagicBattleSoccerPlayerController::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
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
	InputComponent->BindAction("SecondaryAction", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnStartSecondaryAction);
	InputComponent->BindAction("SecondaryAction", IE_Released, this, &AMagicBattleSoccerPlayerController::OnStopSecondaryAction);
	InputComponent->BindAction("Suicide", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnSuicide);
	InputComponent->BindAction("Respawn", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnRespawn);
	InputComponent->BindAction("NextRound", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnNextRound);
	InputComponent->BindAction("QuitToMainMenu", IE_Pressed, this, &AMagicBattleSoccerPlayerController::OnQuitToMainMenu);
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

/** Determines whether the character can be spawned at this time */
bool AMagicBattleSoccerPlayerController::CanSpawnCharacter()
{
	AMagicBattleSoccerGameState *GameState = GetGameState();
	return (Role == ROLE_Authority && nullptr != GameState && GameState->RoundInProgress);
}

/** Spawns the character */
void AMagicBattleSoccerPlayerController::SpawnCharacter_Implementation()
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}

//////////////////////////////////////////////////////////////////////////
// Input handlers

/** Player move forward event */
void AMagicBattleSoccerPlayerController::OnMoveForward(float axisValue)
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(1, 0, 0), axisValue);
	}
}

/** Player move right event */
void AMagicBattleSoccerPlayerController::OnMoveRight(float axisValue)
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->AddMovementInput(FVector(0, 1, 0), axisValue);
	}
}

/** Player primary action event */
void AMagicBattleSoccerPlayerController::OnStartPrimaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		if (PlayerPawn->PossessesBall())
		{
			// Aim where the mouse is pointing
			FVector WorldLocation;
			FVector WorldDirection;
			if (!DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
			{
				// Failed. Do not kick.
				WorldDirection = PlayerPawn->GetActorForwardVector();
			}
			else
			{
				// Calculate the point on the plane Z = BallZ that the mouse is pointing at. Remember we're not projecting onto the ground,
				// we're projecting onto the plane that contains the ball origin for a much more accurate reading.
				FVector Origin = GetGameState()->SoccerBall->GetActorLocation();
				float d = FVector::DotProduct((FVector(0, 0, Origin.Z) - WorldLocation), FVector::UpVector)
					/ FVector::DotProduct(WorldDirection, FVector::UpVector);
				FVector GroundPoint = WorldLocation + WorldDirection * d;

				// Kick to the ground location
				PlayerPawn->KickBallToLocation(GroundPoint, 35.f);
			}
		}
		else if (nullptr != PlayerPawn->PrimaryWeapon)
		{
			PlayerPawn->StartPrimaryWeaponFire();
		}
	}
}

/** Player primary action event */
void AMagicBattleSoccerPlayerController::OnStopPrimaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->StopPrimaryWeaponFire();
	}
}

/** Player secondary action event */
void AMagicBattleSoccerPlayerController::OnStartSecondaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		if (!PlayerPawn->PossessesBall())
		{
			PlayerPawn->StartSecondaryWeaponFire();
		}
	}
}

/** Player secondary action event */
void AMagicBattleSoccerPlayerController::OnStopSecondaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->StopSecondaryWeaponFire();
	}
}

/** Player suicide event */
void AMagicBattleSoccerPlayerController::OnSuicide()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	PlayerPawn->Destroy();
}

/** Player respawn event */
void AMagicBattleSoccerPlayerController::OnRespawn()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr == PlayerPawn)
	{
		SpawnCharacter();
	}
}

/** Next round event (for debugging only) */
void AMagicBattleSoccerPlayerController::OnNextRound()
{
	if (Role == ROLE_Authority)
	{
		AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(GetWorld()->GetAuthGameMode());
		GameMode->HandleMatchHasStarted();
	}
}

void AMagicBattleSoccerPlayerController::OnQuitToMainMenu()
{
	/** Quit to the main menu */
	((UMagicBattleSoccerEngine*)GEngine)->GoToMainMenu();
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
	serverTime -= roundTripTime / 2;

	// Now calculate the difference between the two values
	timeOffsetFromServer = serverTime - timeServerTimeRequestWasPlaced;

	// Now we can safely say that the following is true
	//
	// serverTime = timeServerTimeRequestWasPlaced + timeOffsetFromServer
	//
	// which is another way of saying
	//
	// NetworkTime = LocalTime + timeOffsetFromServer

	timeOffsetIsValid = true;
}
