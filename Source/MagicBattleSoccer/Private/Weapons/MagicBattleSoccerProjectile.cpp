
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerPlayer.h"

AMagicBattleSoccerProjectile::AMagicBattleSoccerProjectile(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	CollisionComp = PCIP.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->AlwaysLoadOnClient = true;
	CollisionComp->AlwaysLoadOnServer = true;
	CollisionComp->bTraceComplexOnMove = true;
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComp->SetCollisionObjectType(COLLISION_PROJECTILE);
	CollisionComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	CollisionComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	RootComponent = CollisionComp;

	MovementComp = PCIP.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("ProjectileComp"));
	MovementComp->UpdatedComponent = CollisionComp;
	MovementComp->InitialSpeed = 800.0f;
	MovementComp->MaxSpeed = 800.0f;
	MovementComp->bRotationFollowsVelocity = true;
	MovementComp->ProjectileGravityScale = 0.f;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickGroup = TG_PrePhysics;
	SetRemoteRoleForBackwardsCompat(ROLE_SimulatedProxy);
	bReplicates = true;
	bReplicateInstigator = true;
	bReplicateMovement = true;
}

void AMagicBattleSoccerProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	MovementComp->OnProjectileStop.AddDynamic(this, &AMagicBattleSoccerProjectile::OnImpact);
	CollisionComp->IgnoreActorWhenMoving(Instigator, true);

	AMagicBattleSoccerPlayer *InstigatorPlayer = Cast<AMagicBattleSoccerPlayer>(Instigator);
	if (nullptr != InstigatorPlayer)
	{
		// Ignore instigator teammates
		AMagicBattleSoccerGameState* GameState = GetWorld()->GetGameState<AMagicBattleSoccerGameState>();
		const TArray<AMagicBattleSoccerPlayer*>& Teammates = GameState->GetTeammates(Cast<AMagicBattleSoccerPlayerState>(InstigatorPlayer->PlayerState));
		for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Teammates.CreateConstIterator()); It; ++It)
		{
			CollisionComp->IgnoreActorWhenMoving(*It, true);
			(*It)->CapsuleComponent->IgnoreActorWhenMoving(this, true);
			if (nullptr != (*It)->CurrentWeapon)
			{
				CollisionComp->IgnoreActorWhenMoving((*It)->CurrentWeapon, true);
			}
		}
	}

	AMagicBattleSoccerWeapon_Projectile* OwnerWeapon = Cast<AMagicBattleSoccerWeapon_Projectile>(GetOwner());
	if (OwnerWeapon)
	{
		OwnerWeapon->ApplyWeaponConfig(WeaponConfig);
	}

	SetLifeSpan(WeaponConfig.ProjectileLife);
	MyController = GetInstigatorController();
}

void AMagicBattleSoccerProjectile::InitVelocity(const FVector& ShootDirection)
{
	if (MovementComp)
	{
		MovementComp->Velocity = ShootDirection * MovementComp->InitialSpeed;
	}
}

void AMagicBattleSoccerProjectile::OnImpact(const FHitResult& HitResult)
{
	if (Role == ROLE_Authority && !bExploded)
	{
		Explode(HitResult);
		DisableAndDestroy();
	}
}

/** This occurs when the object is destroyed */
void AMagicBattleSoccerProjectile::Destroyed()
{
	// Don't leave ourselves lingering in the ignore lists of any soccer players
	UWorld *World = GetWorld();
	if (nullptr != World)
	{
		AMagicBattleSoccerGameState* Game = World->GetGameState<AMagicBattleSoccerGameState>();
		if (nullptr != Game)
		{
			for (TArray<AMagicBattleSoccerPlayer*>::TConstIterator It(Game->SoccerPlayers.CreateConstIterator()); It; ++It)
			{
				(*It)->CapsuleComponent->IgnoreActorWhenMoving(this, false);
				if (nullptr != (*It)->CurrentWeapon)
				{
					CollisionComp->IgnoreActorWhenMoving((*It)->CurrentWeapon, false);
				}
			}
		}
	}
}

void AMagicBattleSoccerProjectile::Explode(const FHitResult& Impact)
{
	// effects and damage origin shouldn't be placed inside mesh at impact point
	const FVector NudgedImpactLocation = Impact.ImpactPoint + Impact.ImpactNormal * 10.0f;

	if (WeaponConfig.ExplosionDamage > 0 && WeaponConfig.ExplosionRadius > 0 && WeaponConfig.DamageType)
	{
		UGameplayStatics::ApplyRadialDamage(this, WeaponConfig.ExplosionDamage, NudgedImpactLocation, WeaponConfig.ExplosionRadius, WeaponConfig.DamageType, TArray<AActor*>(), this, MyController.Get());
	}

	bExploded = true;
}

void AMagicBattleSoccerProjectile::DisableAndDestroy()
{
	UAudioComponent* ProjAudioComp = FindComponentByClass<UAudioComponent>();
	if (ProjAudioComp && ProjAudioComp->IsPlaying())
	{
		ProjAudioComp->FadeOut(0.1f, 0.f);
	}

	//MovementComp->StopMovementImmediately();

	// give clients some time to show explosion
	//SetLifeSpan(2.0f);

	// Destroy ourselves now since we don't have any flashy special effects
	// or explosions to show off.
	Destroy();
}

void AMagicBattleSoccerProjectile::OnRep_Exploded()
{
	FVector ProjDirection = GetActorRotation().Vector();

	const FVector StartTrace = GetActorLocation() - ProjDirection * 200;
	const FVector EndTrace = GetActorLocation() + ProjDirection * 150;
	FHitResult Impact;

	if (!GetWorld()->LineTraceSingle(Impact, StartTrace, EndTrace, COLLISION_PROJECTILE, FCollisionQueryParams(TEXT("ProjClient"), true, Instigator)))
	{
		// failsafe
		Impact.ImpactPoint = GetActorLocation();
		Impact.ImpactNormal = -ProjDirection;
	}

	Explode(Impact);
}

void AMagicBattleSoccerProjectile::PostNetReceiveVelocity(const FVector& NewVelocity)
{
	if (MovementComp)
	{
		MovementComp->Velocity = NewVelocity;
	}
}

void AMagicBattleSoccerProjectile::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMagicBattleSoccerProjectile, bExploded);
}