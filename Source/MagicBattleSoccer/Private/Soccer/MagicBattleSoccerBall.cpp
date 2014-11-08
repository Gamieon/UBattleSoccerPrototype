
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
	if (ROLE_Authority == Role)
	{
		this->SetActorTickEnabled(true);
		PrimaryActorTick.bCanEverTick = true;
	}
	else
	{
		this->SetActorTickEnabled(false);
		PrimaryActorTick.bCanEverTick = false;
	}
}

/** True if the ball has no possessor and is not in a goal. Should only be called by the authority entity. */
bool AMagicBattleSoccerBall::IsFree()
{
	AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	return (NULL == Possessor && NULL == GameMode->PenetratedGoal);
}

void AMagicBattleSoccerBall::MoveWithPossessor()
{
	if (ROLE_Authority == Role)
	{
		if (NULL != Possessor)
		{
			NegDistanceTravelled += Possessor->GetVelocity().Size() * -0.01f;
			SetActorLocationAndRotation(Possessor->GetActorLocation() + Possessor->GetActorForwardVector() * 90.0f + FVector(0.0f, 0.0f, -60.0f),
				FRotator(NegDistanceTravelled, Possessor->GetActorRotation().Yaw, 0.0f));
		}
	}
	else
	{
		// Safety check. Only authority entities should drive the ball.
	}
}

/** Kicks this ball with a given force */
void AMagicBattleSoccerBall::Kick(const FVector& Force)
{
	if (ROLE_Authority == Role)
	{
		// Reset the possessor
		SetPossessor(NULL);

		// Now apply the force
		TArray<UPrimitiveComponent*> PrimitiveComponents;
		this->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
		PrimitiveComponents[0]->AddForce(Force);
	}
	else
	{
		// Safety check. Only authority entities should drive the ball.
	}
}

/** This occurs when play begins */
void AMagicBattleSoccerBall::BeginPlay()
{
	Super::BeginPlay();

	if (ROLE_Authority == Role)
	{
		// Servers should add this soccer ball to the game mode cache
		AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->SoccerBall = this;
	}
	else
	{
		// Clients don't apply to this as they are not managing the game and therefore have no game mode.
		// See https://forums.unrealengine.com/showthread.php?7870-Does-GameMode-only-run-on-server for details.
	}
}

void AMagicBattleSoccerBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (ROLE_Authority == Role)
	{
		if (NULL != Possessor)
		{
			MoveWithPossessor();
		}
	}
	else
	{
		// Safety check. Only authority entities should drive the ball.
	}
}

/** Sets the current ball possessor */
void AMagicBattleSoccerBall::SetPossessor(AMagicBattleSoccerPlayer* Player)
{
	if (ROLE_Authority == Role)
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
			TArray<UPrimitiveComponent*> PrimitiveComponents;
			this->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
			if (NULL != Possessor)
			{
				Possessor->CeaseFire();
				PrimitiveComponents[0]->PutRigidBodyToSleep();
				PrimitiveComponents[0]->SetSimulatePhysics(false);
				SetActorEnableCollision(false);
				MoveWithPossessor();
				// Slow the possessor down for game balancing
				Possessor->UpdateMovementSpeed();
			}
			else
			{
				PrimitiveComponents[0]->SetSimulatePhysics(true);
				SetActorEnableCollision(true);
				PrimitiveComponents[0]->PutRigidBodyToSleep();
			}
		}
	}
	else
	{
		// Safety check. Only authority entities should drive the ball.
	}
}
