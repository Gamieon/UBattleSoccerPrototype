
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerWeapon_Projectile.h"

AMagicBattleSoccerWeapon_Projectile::AMagicBattleSoccerWeapon_Projectile(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Projectile::FireWeapon()
{
	FVector ShootDir = GetAdjustedAim();
	FVector Origin = GetMuzzleLocation();

	//DrawDebugSphere(GetWorld(), Origin + ShootDir * 400.0f, 50.0f, 16, FColor::Red, true);

	// If it's not a unit vector then it's invalid
	if (ShootDir.IsUnit())
	{
		ServerFireProjectile(Origin, ShootDir);
	}
}

bool AMagicBattleSoccerWeapon_Projectile::ServerFireProjectile_Validate(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	return true;
}

void AMagicBattleSoccerWeapon_Projectile::ServerFireProjectile_Implementation(FVector Origin, FVector_NetQuantizeNormal ShootDir)
{
	FTransform SpawnTM(ShootDir.Rotation(), Origin);
	AMagicBattleSoccerProjectile* Projectile = Cast<AMagicBattleSoccerProjectile>(UGameplayStatics::BeginSpawningActorFromClass(this, ProjectileConfig.ProjectileClass, SpawnTM));
	if (Projectile)
	{
		Projectile->Instigator = Instigator;
		Projectile->SetOwner(this);

		// The ShooterDemo has us assigning ShootDir. That is incorrect because the projectile is already facing that
		// direction. We should always assign a forward vector here.
		//Projectile->InitVelocity(ShootDir);
		Projectile->InitVelocity(FVector::ForwardVector);

		UGameplayStatics::FinishSpawningActor(Projectile, SpawnTM);
	}
}

void AMagicBattleSoccerWeapon_Projectile::ApplyWeaponConfig(FProjectileWeaponData& Data)
{
	Data = ProjectileConfig;
}

/** Gets the rotation the weapon should emit damage from */
/*FRotator AMagicBattleSoccerWeapon_Projectile::GetWorldFiringRotation()
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
}*/