
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerTrap.h"
#include "MagicBattleSoccerWeapon_Trap.h"
#include "MagicBattleSoccerPlayerController.h"

AMagicBattleSoccerWeapon_Trap::AMagicBattleSoccerWeapon_Trap(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Trap::FireWeapon()
{
	FVector WorldLocation;
	FVector WorldDirection;

	AMagicBattleSoccerPlayerController* const PlayerController = Instigator ? Cast<AMagicBattleSoccerPlayerController>(Instigator->Controller) : nullptr;
	if (nullptr != PlayerController)
	{
		if (!PlayerController->DeprojectMousePositionToWorld(WorldLocation, WorldDirection))
		{
			// Failed. Return a zero vector which will result in no fire action taking place.
		}
		else
		{
			// Calculate the point on the plane Z=0 that the mouse is pointing at
			float d = FVector::DotProduct((FVector::ZeroVector - WorldLocation), FVector::UpVector)
				/ FVector::DotProduct(WorldDirection, FVector::UpVector);
			FVector GroundPoint = WorldLocation + WorldDirection * d;

			//DrawDebugSphere(GetWorld(), GroundPoint, 50.0f, 16, FColor::Red, true);
			ServerSpawnTrap(GroundPoint);
		}
	}
}

bool AMagicBattleSoccerWeapon_Trap::ServerSpawnTrap_Validate(FVector Origin)
{
	return true;
}

void AMagicBattleSoccerWeapon_Trap::ServerSpawnTrap_Implementation(FVector Origin)
{
	FTransform SpawnTM(FQuat::Identity, Origin);
	AMagicBattleSoccerTrap* Trap = Cast<AMagicBattleSoccerTrap>(UGameplayStatics::BeginSpawningActorFromClass(this, TrapClass, SpawnTM));
	if (nullptr != Trap)
	{
		Trap->Instigator = Instigator;
		Trap->SetOwner(this);

		UGameplayStatics::FinishSpawningActor(Trap, SpawnTM);
	}
}
