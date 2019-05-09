#include "MagicBattleSoccerPlayerController.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerUserSettings.h"
#include "MagicBattleSoccerEngine.h"
#include <chrono>

using namespace std::chrono;

AMagicBattleSoccerPlayerController::AMagicBattleSoccerPlayerController(const class FObjectInitializer& OI)
	: Super(OI)
{
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
	timeServerTimeRequestWasPlaced = 0;
	timeOffsetFromServer = 0;
	timeOffsetIsValid = false;
	bFaceMouseCursorInTick = false;
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

	// Set the player name
	UMagicBattleSoccerUserSettings *UserSettings = CastChecked<UMagicBattleSoccerUserSettings>(GEngine->GetGameUserSettings());
	ServerSetPlayerName(UserSettings->PlayerName);

	// Ask the server for its current time
	if (Role < ROLE_Authority)
	{
		timeServerTimeRequestWasPlaced = GetLocalTime();
		ServerGetServerTime();
	}
}

void AMagicBattleSoccerPlayerController::Tick(float DeltaSeconds)
{
	// Characters should face the direction they're attacking if they're using a repeating weapon like a machine gun or flamethrower
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn && IsLocalController())
	{
		if (nullptr != PlayerPawn->PrimaryWeapon
			&& PlayerPawn->PrimaryWeapon->GetCurrentState() == EWeaponState::Firing
			&& PlayerPawn->PrimaryWeapon->GetWeaponConfig().RepeatingFire)
		{
			PlayerPawn->PrimaryWeapon->SetTargetLocation(FindMouseWorldLocation());
			bFaceMouseCursorInTick = true;
		}
		else if (nullptr != PlayerPawn->SecondaryWeapon
			&& PlayerPawn->SecondaryWeapon->GetCurrentState() == EWeaponState::Firing
			&& PlayerPawn->SecondaryWeapon->GetWeaponConfig().RepeatingFire)
		{
			PlayerPawn->SecondaryWeapon->SetTargetLocation(FindMouseWorldLocation());
			bFaceMouseCursorInTick = true;
		}

		// Can also be true if set from elsewhere
		if (bFaceMouseCursorInTick)
		{
			FVector AttackDir = FindMouseAim();
			GetPawn()->SetActorRotation(AttackDir.Rotation());
			if (Role < ROLE_Authority)
			{
				ServerForceActorRotation(AttackDir.Rotation());
			}
			bFaceMouseCursorInTick = false;
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

	ClientSetSpectatorCamera(CameraLocation, CameraRotation);
}

/** Gets the position of the mouse cursor in world coordinates */
FVector AMagicBattleSoccerPlayerController::FindMouseWorldLocation()
{
	FVector WorldLocation;
	FVector WorldDirection;
	APawn *Pawn = GetPawn();
	if (nullptr == Pawn)
	{
		// Nothing we can do
		return FVector::ZeroVector;
	}
	else if (!DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		// Failed. Return the actor's location
		return Pawn->GetActorLocation();
	}
	else
	{
		// Calculate the point on the plane Z = ActorLocationZ that the mouse is pointing at. Remember we're not projecting onto the ground,
		// we're projecting onto the plane that contains the player.
		FVector Origin = Pawn->GetActorLocation();
		float d = FVector::DotProduct((FVector(0, 0, Origin.Z) - WorldLocation), FVector::UpVector)
			/ FVector::DotProduct(WorldDirection, FVector::UpVector);
		FVector GroundPoint = WorldLocation + WorldDirection * d;
		return GroundPoint;
	}
}

/** Gets the direction the character must aim to cast a ray that intersects the mouse cursor position */
FVector AMagicBattleSoccerPlayerController::FindMouseAim()
{
	// Aim where the mouse is pointing
	FVector WorldLocation;
	FVector WorldDirection;
	APawn *Pawn = GetPawn();
	if (nullptr == Pawn)
	{
		// Nothing we can do
		return FVector::ZeroVector;
	}
	else if (!DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
	{
		// Failed. Return a zero vector which will result in no fire action taking place.
		return Pawn->GetActorForwardVector();
	}
	else
	{
		// Calculate the point on the plane Z = ActorLocationZ that the mouse is pointing at. Remember we're not projecting onto the ground,
		// we're projecting onto the plane that contains the player.
		FVector Origin = Pawn->GetActorLocation();
		float d = FVector::DotProduct((FVector(0, 0, Origin.Z) - WorldLocation), FVector::UpVector)
			/ FVector::DotProduct(WorldDirection, FVector::UpVector);
		FVector GroundPoint = WorldLocation + WorldDirection * d;
		FVector FinalAim = GroundPoint - Origin;
		FinalAim.Z = 0.f;
		FinalAim.Normalize();
		return FinalAim;
	}
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
		const bool bBlocked = GetWorld()->LineTraceTestByChannel(PawnLocation, TestLocation, ECC_Camera, TraceParams);

		if (!bBlocked)
		{
			CameraLocation = TestLocation;
			CameraRotation = CameraDir;
			return true;
		}
	}

	return false;
}

void AMagicBattleSoccerPlayerController::ClientSetSpectatorCamera_Implementation(FVector CameraLocation, FRotator CameraRotation)
{
	SetInitialLocationAndRotation(CameraLocation, CameraRotation);
	SetViewTarget(this);
}

/** Determines whether the character can be spawned at this time */
bool AMagicBattleSoccerPlayerController::CanSpawnCharacter()
{
	AMagicBattleSoccerGameState *GameState = GetGameState();
	return (Role == ROLE_Authority && nullptr == GetPawn() && nullptr != GameState && GameState->RoundInProgress);
}

/** Spawns the character */
void AMagicBattleSoccerPlayerController::SpawnCharacter_Implementation()
{
	// Nothing to do here -- the blueprint should do all the work and it should only be done on the server
}

bool AMagicBattleSoccerPlayerController::ServerSpawnCharacter_Validate()
{
	return CanSpawnCharacter();
}

void AMagicBattleSoccerPlayerController::ServerSpawnCharacter_Implementation()
{
	SpawnCharacter();
}

bool AMagicBattleSoccerPlayerController::ServerForceActorRotation_Validate(FRotator rotation)
{
	return true;
}

void AMagicBattleSoccerPlayerController::ServerForceActorRotation_Implementation(FRotator rotation)
{
	if (nullptr != GetPawn())
	{
		GetPawn()->SetActorRotation(rotation);
	}
}

bool AMagicBattleSoccerPlayerController::ServerBeginChargingBall_Validate()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	return (nullptr != PlayerPawn && PlayerPawn->PossessesBall());
}

void AMagicBattleSoccerPlayerController::ServerBeginChargingBall_Implementation()
{
	GetGameState()->SoccerBall->BeginCharging();
}

bool AMagicBattleSoccerPlayerController::ServerSuicide_Validate()
{
	return true;
}

void AMagicBattleSoccerPlayerController::ServerSuicide_Implementation()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn && PlayerPawn->Health > 0)
	{
		UGameplayStatics::ApplyDamage(PlayerPawn, PlayerPawn->Health * 2.f, nullptr, nullptr, UDamageType::StaticClass());
	}
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
			ServerBeginChargingBall();
		}
		else if (nullptr != PlayerPawn->PrimaryWeapon)
		{
			PlayerPawn->PrimaryWeapon->SetTargetLocation(FindMouseWorldLocation());
			PlayerPawn->StartWeaponFire(PlayerPawn->PrimaryWeapon);
			if (!PlayerPawn->PrimaryWeapon->GetWeaponConfig().CharacterCanWalkWhileFiring)
			{
				bFaceMouseCursorInTick = true;
			}
		}

	} // if (nullptr != PlayerPawn)
}

/** Player primary action event */
void AMagicBattleSoccerPlayerController::OnStopPrimaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		// Ensure in all cases that weapon fire is ceased
		PlayerPawn->StopWeaponFire(PlayerPawn->PrimaryWeapon);

		// Kick the ball
		if (PlayerPawn->PossessesBall())
		{
			// Aim where the mouse is pointing
			FVector WorldLocation;
			FVector WorldDirection;
			if (!DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
			{
				// Failed. I don't see how this can ever happen; just tap the ball forward if it does.
				UE_LOG(LogTemp, Verbose, TEXT("AMagicBattleSoccerPlayerController::OnStopPrimaryAction failed at DeprojectMousePositionToWorld! Tapping ball forward."));
				FVector Origin = GetGameState()->SoccerBall->GetActorLocation();
				PlayerPawn->KickBallToLocation(Origin + PlayerPawn->GetActorForwardVector() * 100.f, 10.f);
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
				FVector v(GroundPoint.X - Origin.X, GroundPoint.Y - Origin.Y, 0.f);
				//PlayerPawn->KickBallToLocation(GroundPoint, 15.f);
				float powerUpDuration = GetWorld()->TimeSeconds - GetGameState()->SoccerBall->serverChargeBeginTime;
				powerUpDuration = FMath::Min(powerUpDuration, 4.f);
				PlayerPawn->KickBallToLocation(Origin + v * (1.f + powerUpDuration), 10.f - powerUpDuration * 1.5f);
			}
		}
	}
}

/** Player secondary action event */
void AMagicBattleSoccerPlayerController::OnStartSecondaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		if (!PlayerPawn->PossessesBall() && nullptr != PlayerPawn->SecondaryWeapon)
		{
			PlayerPawn->SecondaryWeapon->SetTargetLocation(FindMouseWorldLocation());
			PlayerPawn->StartWeaponFire(PlayerPawn->SecondaryWeapon);
			if (!PlayerPawn->SecondaryWeapon->GetWeaponConfig().CharacterCanWalkWhileFiring)
			{
				bFaceMouseCursorInTick = true;
			}
		}
	}
}

/** Player secondary action event */
void AMagicBattleSoccerPlayerController::OnStopSecondaryAction()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr != PlayerPawn)
	{
		PlayerPawn->StopWeaponFire(PlayerPawn->SecondaryWeapon);
	}
}

/** Player suicide event */
void AMagicBattleSoccerPlayerController::OnSuicide()
{
	ServerSuicide();
}

/** Player respawn event */
void AMagicBattleSoccerPlayerController::OnRespawn()
{
	AMagicBattleSoccerCharacter* PlayerPawn = Cast<AMagicBattleSoccerCharacter>(GetPawn());
	if (nullptr == PlayerPawn)
	{
		if (Role < ROLE_Authority)
		{
			ServerSpawnCharacter();
		}
		else
		{
			SpawnCharacter();
		}
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

bool AMagicBattleSoccerPlayerController::ServerGetServerTime_Validate()
{
	return true;
}

/** Sent from a client to the server to get the server's system time */
void AMagicBattleSoccerPlayerController::ServerGetServerTime_Implementation()
{
	ClientGetServerTime(GetLocalTime());
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

bool AMagicBattleSoccerPlayerController::ServerSetPlayerName_Validate(const FString& PlayerName)
{
	return true;
}

/** Sent from a client to the server to set the client's player name. We don't use
any sort of known online subsystem so we do it this way */
void AMagicBattleSoccerPlayerController::ServerSetPlayerName_Implementation(const FString& PlayerName)
{
	PlayerState->SetPlayerName(PlayerName);
}

