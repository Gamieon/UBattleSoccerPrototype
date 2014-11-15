
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayer.h"


AMagicBattleSoccerBall::AMagicBattleSoccerBall(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Possessor = NULL;
	LastReleaseTime = 0.0f;
	NegDistanceTravelled = 0.0f;
	proxyStateCount = 0;
	timeServerTimeRequestWasPlaced = 0;
	timeOffsetFromServer = 0;
	timeOffsetIsValid = false;
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

void AMagicBattleSoccerBall::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME(AMagicBattleSoccerBall, Possessor);
	DOREPLIFETIME(AMagicBattleSoccerBall, ServerPhysicsState);
}

void AMagicBattleSoccerBall::OnRep_ServerPhysicsState()
{
	// If we get here, we are always the client. Here we store the physics state
	// for physics state interpolation.

	// Shift the buffer sideways, deleting state 20
	for (int i = PROXY_STATE_ARRAY_SIZE - 1; i >= 1; i--)
	{
		proxyStates[i] = proxyStates[i - 1];
	}

	// Record current state in slot 0
	proxyStates[0] = ServerPhysicsState;

	// Update used slot count, however never exceed the buffer size
	// Slots aren't actually freed so this just makes sure the buffer is
	// filled up and that uninitalized slots aren't used.
	proxyStateCount = FMath::Min(proxyStateCount + 1, PROXY_STATE_ARRAY_SIZE);

	// Check if states are in order
	if (proxyStates[0].timestamp < proxyStates[1].timestamp)
	{ 
		UE_LOG(LogOnlineGame, Verbose, TEXT("Timestamp inconsistent: %d should be greater than %d"), proxyStates[0].timestamp, proxyStates[1].timestamp);
	}		
}

/** Gets the current system time in milliseconds */
uint64 AMagicBattleSoccerBall::GetLocalTime()
{
	FILETIME ft;
	GetSystemTimeAsFileTime(&ft);

	// Filetime in 100 nanosecond resolution
	uint64 fileTimeNano100;
	fileTimeNano100 = (((uint64)ft.dwHighDateTime) << 32) + ft.dwLowDateTime;

	// To milliseconds and unix windows epoche offset removed
	uint64 posixTime = fileTimeNano100 / 10000 - 11644473600000;
	return posixTime;
}

/** Gets the approximate current network time in milliseconds. */
uint64 AMagicBattleSoccerBall::GetNetworkTime()
{
	return GetLocalTime() + timeOffsetFromServer;
}

/** Simulates the free movement of the ball based on proxy states */
void AMagicBattleSoccerBall::ClientSimulatePhysicsMovement()
{
	if (!timeOffsetIsValid || 0 == proxyStateCount)
	{
		// We don't know yet know what the time is on the server yet so the timestamps
		// of the proxy states mean nothing; that or we simply don't have any proxy
		// states yet. Don't do any interpolation.
		SetActorLocationAndRotation(ServerPhysicsState.pos, ServerPhysicsState.rot);
	}
	else
	{
		uint64 interpolationBackTime = 200;
		uint64 extrapolationLimit = 500;

		// This is the target playback time of the rigid body
		uint64 interpolationTime = GetNetworkTime() - interpolationBackTime;

		// Use interpolation if the target playback time is present in the buffer
		if (proxyStates[0].timestamp > interpolationTime)
		{
			// Go through buffer and find correct state to play back
			for (int i=0;i<proxyStateCount;i++)
			{
				if (proxyStates[i].timestamp <= interpolationTime || i == proxyStateCount-1)
				{
					// The state one slot newer (<100ms) than the best playback state
					FSmoothPhysicsState rhs = proxyStates[FMath::Max(i - 1, 0)];
					// The best playback state (closest to 100 ms old (default time))
					FSmoothPhysicsState lhs = proxyStates[i];

					// Use the time between the two slots to determine if interpolation is necessary
					int64 length = (int64)(rhs.timestamp - lhs.timestamp);
					double t = 0.0F;
					// As the time difference gets closer to 100 ms t gets closer to 1 in
					// which case rhs is only used
					// Example:
					// Time is 10.000, so sampleTime is 9.900
					// lhs.time is 9.910 rhs.time is 9.980 length is 0.070
					// t is 9.900 - 9.910 / 0.070 = 0.14. So it uses 14% of rhs, 86% of lhs
					if (length > 1)
						t = (double)(interpolationTime - lhs.timestamp) / (double)length;

					// if t=0 => lhs is used directly					
					FVector pos = FMath::Lerp(lhs.pos, rhs.pos, t);
					FRotator rot = FMath::Lerp(lhs.rot, rhs.rot, t);
					SetActorLocationAndRotation(pos, rot);
					return;
				}
			}
		}
		// Use extrapolation
		else
		{
			FSmoothPhysicsState latest = proxyStates[0];

			uint64 extrapolationLength = interpolationTime - latest.timestamp;
			// Don't extrapolation for more than 500 ms, you would need to do that carefully
			if (extrapolationLength < extrapolationLimit)
			{
				FVector pos = latest.pos + latest.vel * ((float)extrapolationLength * 0.001f);
				FRotator rot = latest.rot;
				SetActorLocationAndRotation(pos, rot);
			}
		}
	}
}

/** Sent from a client to the server to get the server's system time */
void AMagicBattleSoccerBall::Server_GetServerTime_Implementation()
{
	Client_GetServerTime(GetLocalTime());
}

bool AMagicBattleSoccerBall::Server_GetServerTime_Validate()
{
	return true;
}

/** Sent from the server to a client to give them the server's system time */
void AMagicBattleSoccerBall::Client_GetServerTime_Implementation(uint64 time)
{
	APlayerState* MyState = GetGameState()->PlayerArray[0];
	float ping = MyState->ExactPing;

	// Calculate the server's system time at the moment we actually sent the
	// request for it.
	time -= (int64)(ping * 1000.0f);

	// Now calculate the difference between the two values
	if (timeServerTimeRequestWasPlaced > time)
	{
		// We are in the "future," so the offset should be negative
		timeOffsetFromServer = -(int64)(timeServerTimeRequestWasPlaced - time);
	}
	else
	{
		// We are in the "past" (or "present"), so the offset should be non-negative
		timeOffsetFromServer = (time - timeServerTimeRequestWasPlaced);
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

/** This occurs when play begins */
void AMagicBattleSoccerBall::BeginPlay()
{
	Super::BeginPlay();

	if (ROLE_Authority != Role)
	{
		// The server manages the game state; the soccer ball will be replicated to us.

		// Physics however are not replicated. We will need to have the ball orientation
		// replicated to us. We need to turn off physics simulation.
		UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
		Root->PutRigidBodyToSleep();
		Root->SetSimulatePhysics(false);
		Root->SetEnableGravity(false);
		SetActorEnableCollision(false);

		// Ask the server for its current time
		if (ROLE_AutonomousProxy == Role)
		{
			// Autonomous proxies need to use RPC calls
			timeServerTimeRequestWasPlaced = GetLocalTime();
			Server_GetServerTime();
		}
		else
		{
			// Simulated proxies are treated as the server (we're probably in the editor). 
			// Make sure the time offset is zero.
			timeOffsetFromServer = 0;
			timeOffsetIsValid = true;
		}
	}
	else
	{
		// Servers should add this soccer ball to the game mode cache.
		// It will get replicated to clients.
		AMagicBattleSoccerGameState* GameState = GetGameState();
		GameState->SoccerBall = this;
	}
}

void AMagicBattleSoccerBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (NULL != Possessor)
	{
		// If the ball is possessed by a player, then the ball should move as a function
		// of the possessor
		MoveWithPossessor();
	}
	else
	{
		// No possessor. The ball is freely moving.
		if (ROLE_Authority != Role)
		{
			// Clients should update its local position based on where it is on the server
			ClientSimulatePhysicsMovement();
		}
		else
		{
			// Servers should simulate the ball physics freely and replicate the orientation
			UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
			ServerPhysicsState.pos = GetActorLocation();
			ServerPhysicsState.rot = GetActorRotation();
			ServerPhysicsState.vel = Root->GetComponentVelocity();
			ServerPhysicsState.timestamp = GetLocalTime();
		}
	}
}

/** Gets the game state (all instances should be interested in this) */
AMagicBattleSoccerGameState* AMagicBattleSoccerBall::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
}

/** True if the ball has no possessor and is not in a goal. Should only be called by the authority entity. */
bool AMagicBattleSoccerBall::IsFree()
{
	return (NULL == Possessor && NULL == GetGameState()->PenetratedGoal);
}

void AMagicBattleSoccerBall::MoveWithPossessor()
{
	// This is used to roll the ball while a possessor owns it. The angle is a function of how far the ball has travelled.
	NegDistanceTravelled += Possessor->GetVelocity().Size() * -0.01f;

	// All platforms should move the same way if there is a possessor.
	SetActorLocationAndRotation(Possessor->GetActorLocation() + Possessor->GetActorForwardVector() * 90.0f + FVector(0.0f, 0.0f, -60.0f),
		FRotator(NegDistanceTravelled, Possessor->GetActorRotation().Yaw, 0.0f));
}

/** Kicks this ball with a given force */
void AMagicBattleSoccerBall::Kick(const FVector& Force)
{
	if (ROLE_Authority != Role)
	{
		// Safety check. Only authority entities should drive the ball.
	}
	else
	{
		// Reset the possessor
		SetPossessor(NULL);

		// Now apply the force
		UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
		Root->AddForce(Force);
	}
}

/** Sets the current ball possessor */
void AMagicBattleSoccerBall::SetPossessor(AMagicBattleSoccerPlayer* Player)
{
	if (ROLE_Authority != Role)
	{
		// Safety check. Only authority entities should drive the ball.
	}
	else
	{
		float GameTimeInSeconds = GetWorld()->TimeSeconds;

		// We only allow a possession change if there is no new possessor or if we just didn't recently unassign possession
		if (NULL == Player || GameTimeInSeconds > LastReleaseTime + 0.2f)
		{
			AMagicBattleSoccerPlayer *OldPossessor = Possessor;

			// Assign the new possessor
			if (NULL == Player)
			{
				LastReleaseTime = GameTimeInSeconds;
			}
			Possessor = Player;

			// Update the old possessor's walking speed
			if (NULL != OldPossessor)
			{
				OldPossessor->UpdateMovementSpeed();
			}

			// Toggle physics
			UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
			if (NULL != Possessor)
			{
				Possessor->CeaseFire();
				Root->PutRigidBodyToSleep();
				Root->SetSimulatePhysics(false);
				Root->SetEnableGravity(false);
				SetActorEnableCollision(false);
				MoveWithPossessor();
				// Slow the possessor down for game balancing
				Possessor->UpdateMovementSpeed();
			}
			else
			{
				Root->SetSimulatePhysics(true);
				Root->SetEnableGravity(true);
				SetActorEnableCollision(true);
				Root->PutRigidBodyToSleep();
			}
		}

		// Force the orientation to be replicated at the same time the possessor is replicated
		UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
		ServerPhysicsState.pos = GetActorLocation();
		ServerPhysicsState.rot = GetActorRotation();
		ServerPhysicsState.vel = Root->GetComponentVelocity();
		ServerPhysicsState.timestamp = GetLocalTime();
	}
}
