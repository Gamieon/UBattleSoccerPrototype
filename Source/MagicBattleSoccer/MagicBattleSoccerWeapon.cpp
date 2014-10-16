
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerPlayer.h"
#include "MagicBattleSoccerPlayerController.h"

AMagicBattleSoccerWeapon::AMagicBattleSoccerWeapon(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	IsFiring = false;
}

/** Gets the rotation the weapon should emit damage from */
FRotator AMagicBattleSoccerWeapon::GetWorldFiringRotation()
{
	AActor *Owner = GetOwner();
	AMagicBattleSoccerPlayer *OwningPlayer = Cast<AMagicBattleSoccerPlayer>(Owner);
	AMagicBattleSoccerPlayerController *OwningPlayerController = (NULL == OwningPlayer) ? NULL : Cast<AMagicBattleSoccerPlayerController>(OwningPlayer->GetController());

	if (NULL == Owner)
	{
		// We appear to be a soverign object
		return GetActorRotation();
	}
	else if (NULL == OwningPlayer)
	{
		// No owning player; we must be firing from a turret or other automated device
		return Owner->GetActorRotation();
	}
	else if (NULL == OwningPlayerController)
	{
		// We're owned by a bot. Just fire in the bot's direction
		return Owner->GetActorRotation();
	}
	else
	{
		// We're owned by a player. Fire at the mouse cursor.
		FHitResult hitResult;
		OwningPlayerController->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECC_Visibility), false, hitResult);
		FVector hitLocation = FVector(hitResult.Location.X, hitResult.Location.Y, OwningPlayer->GetActorLocation().Z);
		FRotator lookAtRotation = (hitLocation - OwningPlayer->GetActorLocation()).Rotation();
		return lookAtRotation;
	}
}


/** Activates the weapon's primary function */
void AMagicBattleSoccerWeapon::BeginFire_Implementation()
{
	IsFiring = true;
}

/** Deactivates the weapon's primary function */
void AMagicBattleSoccerWeapon::CeaseFire_Implementation()
{
	IsFiring = false;
}