
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerPlayerController.h"


AMagicBattleSoccerBall::AMagicBattleSoccerBall(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Possessor = NULL;
	LastReleaseTime = 0.0f;
	NegDistanceTravelled = 0.0f;
	proxyStateCount = 0;
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

/** Simulates the free movement of the ball based on proxy states */
void AMagicBattleSoccerBall::ClientSimulatePhysicsMovement()
{
	AMagicBattleSoccerPlayerController* MyPC = Cast<AMagicBattleSoccerPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (!MyPC->IsNetworkTimeValid() || 0 == proxyStateCount || nullptr == MyPC)
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
		uint64 interpolationTime = MyPC->GetNetworkTime() - interpolationBackTime;

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
			// Don't extrapolate for more than [extrapolationLimit] milliseconds, you would need to do that carefully
			if (extrapolationLength < extrapolationLimit)
			{
				FVector pos = latest.pos + latest.vel * ((float)extrapolationLength * 0.001f);
				FRotator rot = latest.rot;
				SetActorLocationAndRotation(pos, rot);
			}
		}
	}
}

/** This occurs when play begins */
void AMagicBattleSoccerBall::BeginPlay()
{
	Super::BeginPlay();

	if (Role < ROLE_Authority)
	{
		// The server manages the game state; the soccer ball will be replicated to us.

		// Physics however are not replicated. We will need to have the ball orientation
		// replicated to us. We need to turn off physics simulation.
		UPrimitiveComponent *Root = Cast<UPrimitiveComponent>(GetRootComponent());
		Root->PutRigidBodyToSleep();
		Root->SetSimulatePhysics(false);
		Root->SetEnableGravity(false);
		SetActorEnableCollision(false);
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
		if (Role < ROLE_Authority)
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
			ServerPhysicsState.timestamp = AMagicBattleSoccerPlayerController::GetLocalTime();
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
	if (Role < ROLE_Authority)
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
	if (Role < ROLE_Authority)
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
		ServerPhysicsState.timestamp = AMagicBattleSoccerPlayerController::GetLocalTime();
	}
}
