
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerWeapon_Projectile.h"

AMagicBattleSoccerWeapon_Projectile::AMagicBattleSoccerWeapon_Projectile(const class FObjectInitializer& OI)
	: Super(OI)
{
}

//////////////////////////////////////////////////////////////////////////
// Input

/** [local + server] sets the firing target */
void AMagicBattleSoccerWeapon_Projectile::SetTargetLocationAdjustedForVelocity(FVector TargetLocation, FVector TargetVelocity)
{
	if (Role < ROLE_Authority)
	{
		ServerSetTargetLocationAdjustedForVelocity(TargetLocation, TargetVelocity);
	}

	// Adjust for projectile speed.
	// TODO: Why are we not designating the projectile's speed?? We're completely guessing here!
	float d = FVector::Dist(GetActorLocation(), TargetLocation);
	float t = d / 2500.f;
	this->TargetLocation = TargetLocation + TargetVelocity * t;
}

//////////////////////////////////////////////////////////////////////////
// AI

/** Returns how effective this weapon would be on scene actors in the world's current state */
TArray<FWeaponActorEffectiveness> AMagicBattleSoccerWeapon_Projectile::GetCurrentEffectiveness()
{
	TArray<FWeaponActorEffectiveness> effectivenessList;
	if (nullptr != Instigator && nullptr != Instigator->PlayerState)
	{
		UWorld *World = GetWorld();
		AMagicBattleSoccerGameState* GameState = Cast<AMagicBattleSoccerGameState>(World->GetGameState<AMagicBattleSoccerGameState>());
		AMagicBattleSoccerPlayerState *PlayerState = Cast<AMagicBattleSoccerPlayerState>(Instigator->PlayerState);
		if (nullptr != GameState)
		{
			const TArray<AMagicBattleSoccerCharacter*>& Opponents = GameState->GetOpponents(PlayerState);
			for (TArray<AMagicBattleSoccerCharacter*>::TConstIterator It(Opponents.CreateConstIterator()); It; ++It)
			{
				FVector v = (*It)->GetActorLocation() - Instigator->GetActorLocation();
				float dp = FVector::DotProduct(v, Instigator->GetActorForwardVector());
				if (dp > 0)
				{
					float d = Instigator->GetDistanceTo(*It);
					if (d < WeaponConfig.EffectiveRange)
					{
						FWeaponActorEffectiveness e;
						e.Actor = *It;
						e.HealthChange = (float)ProjectileConfig.ExplosionDamage / (*It)->Health;
						effectivenessList.Add(e);
					}
				}
			}
		}
	}
	return effectivenessList;
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Projectile::FireWeapon()
{
	if (nullptr != Instigator)
	{
		// If the instigator is running, then fire the projectile immediately
		if (Instigator->GetVelocity().Size() > 0.001f)
		{
			FireWeapon_Delayed();
		}
		else
		{
			// Set the timer for the delayed fire
			GetWorldTimerManager().SetTimer(this, &AMagicBattleSoccerWeapon_Projectile::FireWeapon_Delayed, ProjectileConfig.ReleaseDelay);
		}
	}
}

void AMagicBattleSoccerWeapon_Projectile::FireWeapon_Delayed()
{
	if (nullptr != Instigator)
	{
		FVector ShootDir = TargetLocation - Instigator->GetActorLocation();
		ShootDir.Z = 0;
		ShootDir.Normalize();
		// We should be factoring in the muzzle location, but this seems to work better
		FVector Origin = Instigator->GetActorLocation() + ShootDir * 80.0f;

		//DrawDebugSphere(GetWorld(), Origin + ShootDir * 400.0f, 50.0f, 16, FColor::Red, true);

		// If it's not a unit vector then it's invalid
		if (ShootDir.IsUnit())
		{
			ServerFireProjectile(Origin, ShootDir);
		}
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
