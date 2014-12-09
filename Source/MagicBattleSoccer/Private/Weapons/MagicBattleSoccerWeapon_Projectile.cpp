
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerWeapon_Projectile.h"

AMagicBattleSoccerWeapon_Projectile::AMagicBattleSoccerWeapon_Projectile(const class FObjectInitializer& OI)
	: Super(OI)
{
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Projectile::FireWeapon()
{
	FVector ShootDir = GetAdjustedAim();
	FVector Origin = GetMuzzleLocation() + ShootDir * 50.0f;

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
