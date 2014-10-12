
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
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}

/** True if the ball has no possessor and is not in a goal. */
bool AMagicBattleSoccerBall::IsFree()
{
	AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	return (NULL == Possessor && NULL == GameMode->PenetratedGoal);
}

void AMagicBattleSoccerBall::MoveWithPossessor()
{
	if (NULL != Possessor)
	{
		NegDistanceTravelled += Possessor->GetVelocity().Size() * -0.01f;
		SetActorLocationAndRotation( Possessor->GetActorLocation() + Possessor->GetActorForwardVector() * 90.0f + FVector(0.0f, 0.0f, -60.0f), 
			FRotator(NegDistanceTravelled, Possessor->GetActorRotation().Yaw, 0.0f));
	}
}

/** Kicks this ball with a given force */
void AMagicBattleSoccerBall::Kick(const FVector& Force)
{
	// Reset the possessor
	SetPossessor(NULL);

	// Now apply the force
	TArray<UPrimitiveComponent*> PrimitiveComponents;
	this->GetComponents<UPrimitiveComponent>(PrimitiveComponents);
	PrimitiveComponents[0]->AddForce(Force);
}

#pragma region Events

/** This occurs when play begins */
void AMagicBattleSoccerBall::BeginPlay()
{
	Super::BeginPlay();

	// Add ourselves to the game mode cache
	AMagicBattleSoccerGameMode* GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->SoccerBall = this;
}

void AMagicBattleSoccerBall::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (NULL != Possessor)
	{
		MoveWithPossessor();
	}
}

#pragma endregion

/** Sets the current ball possessor */
void AMagicBattleSoccerBall::SetPossessor(AMagicBattleSoccerPlayer* Player)
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
