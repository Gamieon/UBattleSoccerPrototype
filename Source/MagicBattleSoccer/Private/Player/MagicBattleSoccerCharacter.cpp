#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerBall.h"
#include "MagicBattleSoccerGoal.h"
#include "MagicBattleSoccerGameMode.h"
#include "MagicBattleSoccerGameState.h"
#include "MagicBattleSoccerCharacter.h"
#include "MagicBattleSoccerWeapon.h"
#include "MagicBattleSoccerProjectile.h"
#include "MagicBattleSoccerSpawnPoint.h"
#include "MagicBattleSoccerPlayerController.h"
#include "AIController.h"
#include "Engine/TriggerBox.h"

AMagicBattleSoccerCharacter::AMagicBattleSoccerCharacter(const class FObjectInitializer& OI)
	: Super(OI)
{
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_PROJECTILE, ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(COLLISION_WEAPON, ECR_Ignore);

	PrimaryWeapon = nullptr;
	SecondaryWeapon = nullptr;
	WantsPrimaryFire = false;
	WantsSecondaryFire = false;
	LastTakeHitTimeTimeout = 0;
}

void AMagicBattleSoccerCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (ROLE_Authority == Role)
	{
		// Reset the health count
		Health = MaxHealth;

		// Give this player their default weapons
		SpawnDefaultInventory();
	}
}

void AMagicBattleSoccerCharacter::PreReplication(IRepChangedPropertyTracker & ChangedPropertyTracker)
{
	Super::PreReplication(ChangedPropertyTracker);

	// Only replicate this property for a short duration after it changes so join in progress players don't get spammed with fx when joining late
	DOREPLIFETIME_ACTIVE_OVERRIDE(AMagicBattleSoccerCharacter, LastTakeHitInfo, GetWorld() && GetWorld()->GetTimeSeconds() < LastTakeHitTimeTimeout);
}

void AMagicBattleSoccerCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Replicate to everyone
	DOREPLIFETIME(AMagicBattleSoccerCharacter, MaxHealth);
	DOREPLIFETIME(AMagicBattleSoccerCharacter, Health);
	DOREPLIFETIME(AMagicBattleSoccerCharacter, CurrentMovementSpeed);
	DOREPLIFETIME(AMagicBattleSoccerCharacter, PrimaryWeapon);
	DOREPLIFETIME(AMagicBattleSoccerCharacter, SecondaryWeapon);
}

void AMagicBattleSoccerCharacter::OnRep_PrimaryWeapon(AMagicBattleSoccerWeapon* LastWeapon)
{
	SetPrimaryWeapon(PrimaryWeapon, LastWeapon);
}

void AMagicBattleSoccerCharacter::OnRep_SecondaryWeapon(AMagicBattleSoccerWeapon* LastWeapon)
{
	SetPrimaryWeapon(SecondaryWeapon, LastWeapon);
}

/** Called on clients when the server changes this character's default movement speed */
void AMagicBattleSoccerCharacter::OnRep_CurrentMovementSpeed()
{
	// Update the default movement speed of the movement component
	// with the replicated value
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	MovementComponent->MaxWalkSpeed = CurrentMovementSpeed;
}

/** play hit or death on client */
void AMagicBattleSoccerCharacter::OnRep_LastTakeHitInfo()
{
	if (LastTakeHitInfo.bKilled)
	{
		OnDeath(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
	else
	{
		PlayHit(LastTakeHitInfo.ActualDamage, LastTakeHitInfo.GetDamageEvent(), LastTakeHitInfo.PawnInstigator.Get(), LastTakeHitInfo.DamageCauser.Get());
	}
}

void AMagicBattleSoccerCharacter::PossessedBy(class AController* InController)
{
	Super::PossessedBy(InController);

	// [server] as soon as PlayerState is assigned, set team colors of this pawn for local player
	AssignUniform();
}

/** [client] perform PlayerState related setup */
void AMagicBattleSoccerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// [client] as soon as PlayerState is assigned, set team colors of this pawn for local player
	AssignUniform();
}

/** This occurs when play begins for a character */
void AMagicBattleSoccerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (ROLE_Authority == Role)
	{
		// Servers should add this character to the game mode cache
		GetGameState()->SoccerPlayers.Add(this);

		// Assign the character max walk speed to the default movement speed
		UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
		DefaultMovementSpeed = CurrentMovementSpeed = MovementComponent->MaxWalkSpeed;
	}
	else
	{
		// The server manages the game state; the player list will be replicated to us.
	}
}

void AMagicBattleSoccerCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	// Servers should manage ball assignments
	if (ROLE_Authority == Role)
	{
		AMagicBattleSoccerBall *Ball = GetGameState()->SoccerBall;
		float d = FVector::DistSquared(GetActorLocation(), Ball->GetActorLocation());
		if (nullptr == Ball->Possessor
			&& FVector::DistSquared(GetActorLocation(), Ball->GetActorLocation()) < 12000.f)
		{
			// If the ball is overlapping us and doesn't presently have a possessor, try to assign ourselves
			// possession. This can fail if we just had possession moments ago (otherwise we could kick the ball
			// and immediately take possession again)
			Ball->SetPossessor(this);
		}
	}
}

/** This occurs when play ends */
void AMagicBattleSoccerCharacter::ReceiveEndPlay(EEndPlayReason::Type EndPlayReason)
{
	Super::ReceiveEndPlay(EndPlayReason);

	if (ROLE_Authority == Role)
	{
		// Remove this character from the game mode cache
		GetGameState()->SoccerPlayers.Remove(this);
	}
	else
	{
		// The server manages the game state; the player list will be replicated to us.
	}
}

/** This occurs when the player is destroyed */
void AMagicBattleSoccerCharacter::Destroyed()
{
	if (Role < ROLE_Authority)
	{
		// The server manages the game state; the player list will be replicated to us.
	}
	else
	{
		if (nullptr != GetGameState())
		{
			GetSoccerBall()->CharacterHasDestroyed(this);

			// Remove this character from the game mode cache
			GetGameState()->SoccerPlayers.Remove(this);
		}
	}

	Super::Destroyed();
	DestroyInventory();
}

//////////////////////////////////////////////////////////////////////////
// Damage & death

float AMagicBattleSoccerCharacter::TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	if (Health <= 0.f)
	{
		return 0.f;
	}

	// Modify based on game rules.
	AMagicBattleSoccerGameMode* const Game = GetWorld()->GetAuthGameMode<AMagicBattleSoccerGameMode>();
	Damage = Game ? Game->ModifyDamage(Damage, this, DamageEvent, EventInstigator, DamageCauser) : 0.f;

	const float ActualDamage = Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	if (ActualDamage > 0.f)
	{
		Health -= ActualDamage;
		if (Health <= 0.f)
		{
			Die(ActualDamage, DamageEvent, EventInstigator, DamageCauser);
		}
		else
		{
			PlayHit(ActualDamage, DamageEvent, EventInstigator ? EventInstigator->GetPawn() : NULL, DamageCauser);
		}
	}

	return ActualDamage;
}

bool AMagicBattleSoccerCharacter::CanDie(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser) const
{
	if (IsPendingKill()								// already destroyed
		|| Role != ROLE_Authority						// not authority
		|| GetWorld()->GetAuthGameMode() == NULL
		|| GetWorld()->GetAuthGameMode()->GetMatchState() == MatchState::LeavingMap)	// level transition occurring
	{
		return false;
	}

	return true;
}

bool AMagicBattleSoccerCharacter::Die(float KillingDamage, FDamageEvent const& DamageEvent, AController* Killer, AActor* DamageCauser)
{
	if (!CanDie(KillingDamage, DamageEvent, Killer, DamageCauser))
	{
		return false;
	}

	Health = FMath::Min(0.0f, Health);

	// if this is an environmental death then refer to the previous killer so that they receive credit (knocked into lava pits, etc)
	UDamageType const* const DamageType = DamageEvent.DamageTypeClass ? DamageEvent.DamageTypeClass->GetDefaultObject<UDamageType>() : GetDefault<UDamageType>();
	Killer = GetDamageInstigator(Killer, *DamageType);

	AController* const KilledPlayer = (Controller != NULL) ? Controller : Cast<AController>(GetOwner());
	GetWorld()->GetAuthGameMode<AMagicBattleSoccerGameMode>()->Killed(Killer, KilledPlayer, this, DamageType);

	NetUpdateFrequency = GetDefault<AMagicBattleSoccerCharacter>()->NetUpdateFrequency;
	GetCharacterMovement()->ForceReplicationUpdate();

	OnDeath(KillingDamage, DamageEvent, Killer ? Killer->GetPawn() : NULL, DamageCauser);
	return true;
}

void AMagicBattleSoccerCharacter::OnDeath(float KillingDamage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	bReplicateMovement = false;
	bTearOff = true;

	if (ROLE_Authority == Role)
	{
		ReplicateHit(KillingDamage, DamageEvent, PawnInstigator, DamageCauser, true);
	}

	// remove all weapons
	DestroyInventory();

	// now destroy the player
	Destroy();
}

void AMagicBattleSoccerCharacter::PlayHit(float DamageTaken, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser)
{
	if (ROLE_Authority == Role)
	{
		ReplicateHit(DamageTaken, DamageEvent, PawnInstigator, DamageCauser, false);
	}

	if (DamageTaken > 0.f)
	{
		ApplyDamageMomentum(DamageTaken, DamageEvent, PawnInstigator, DamageCauser);
	}

	AMagicBattleSoccerPlayerController* MyPC = Cast<AMagicBattleSoccerPlayerController>(Controller);
	/*AShooterHUD* MyHUD = MyPC ? Cast<AShooterHUD>(MyPC->GetHUD()) : NULL;
	if (MyHUD)
	{
		MyHUD->NotifyHit(DamageTaken, DamageEvent, PawnInstigator);
	}*/

	if (PawnInstigator && PawnInstigator != this && PawnInstigator->IsLocallyControlled())
	{
		AMagicBattleSoccerPlayerController* InstigatorPC = Cast<AMagicBattleSoccerPlayerController>(PawnInstigator->Controller);
		/*AShooterHUD* InstigatorHUD = InstigatorPC ? Cast<AShooterHUD>(InstigatorPC->GetHUD()) : NULL;
		if (InstigatorHUD)
		{
			InstigatorHUD->NotifyEnemyHit();
		}*/
	}
}

void AMagicBattleSoccerCharacter::ReplicateHit(float Damage, struct FDamageEvent const& DamageEvent, class APawn* PawnInstigator, class AActor* DamageCauser, bool bKilled)
{
	const float TimeoutTime = GetWorld()->GetTimeSeconds() + 0.5f;

	FDamageEvent const& LastDamageEvent = LastTakeHitInfo.GetDamageEvent();
	if ((PawnInstigator == LastTakeHitInfo.PawnInstigator.Get()) && (LastDamageEvent.DamageTypeClass == LastTakeHitInfo.DamageTypeClass) && (LastTakeHitTimeTimeout == TimeoutTime))
	{
		// same frame damage
		if (bKilled && LastTakeHitInfo.bKilled)
		{
			// Redundant death take hit, just ignore it
			return;
		}

		// otherwise, accumulate damage done this frame
		Damage += LastTakeHitInfo.ActualDamage;
	}

	LastTakeHitInfo.ActualDamage = Damage;
	LastTakeHitInfo.PawnInstigator = Cast<AMagicBattleSoccerCharacter>(PawnInstigator);
	LastTakeHitInfo.DamageCauser = DamageCauser;
	LastTakeHitInfo.SetDamageEvent(DamageEvent);
	LastTakeHitInfo.bKilled = bKilled;
	LastTakeHitInfo.EnsureReplication();

	LastTakeHitTimeTimeout = TimeoutTime;
}

//////////////////////////////////////////////////////////////////////////
// Inventory and weapons

void AMagicBattleSoccerCharacter::SetPrimaryWeapon(AMagicBattleSoccerWeapon* NewWeapon, AMagicBattleSoccerWeapon* LastWeapon)
{
	AMagicBattleSoccerWeapon* LocalLastWeapon = NULL;

	if (LastWeapon != NULL)
	{
		LocalLastWeapon = LastWeapon;
	}
	else if (NewWeapon != PrimaryWeapon)
	{
		LocalLastWeapon = PrimaryWeapon;
	}

	// unequip previous
	if (LocalLastWeapon)
	{
		LocalLastWeapon->OnUnEquip();
	}

	PrimaryWeapon = NewWeapon;

	// equip new one
	if (NewWeapon)
	{
		NewWeapon->SetOwningPawn(this);	// Make sure weapon's MyPawn is pointing back to us. During replication, we can't guarantee APawn::PrimaryWeapon will rep after AWeapon::MyPawn!
		NewWeapon->OnEquip(FName(TEXT("RightHand")));
	}
}

void AMagicBattleSoccerCharacter::SetSecondaryWeapon(AMagicBattleSoccerWeapon* NewWeapon, AMagicBattleSoccerWeapon* LastWeapon)
{
	AMagicBattleSoccerWeapon* LocalLastWeapon = NULL;

	if (LastWeapon != NULL)
	{
		LocalLastWeapon = LastWeapon;
	}
	else if (NewWeapon != SecondaryWeapon)
	{
		LocalLastWeapon = SecondaryWeapon;
	}

	// unequip previous
	if (LocalLastWeapon)
	{
		LocalLastWeapon->OnUnEquip();
	}

	SecondaryWeapon = NewWeapon;

	// equip new one
	if (NewWeapon)
	{
		NewWeapon->SetOwningPawn(this);	// Make sure weapon's MyPawn is pointing back to us. During replication, we can't guarantee APawn::PrimaryWeapon will rep after AWeapon::MyPawn!
		NewWeapon->OnEquip(FName(TEXT("LeftHand")));
	}
}

void AMagicBattleSoccerCharacter::SpawnDefaultInventory()
{
	if (Role < ROLE_Authority)
	{
		return;
	}

	int32 NumWeaponClasses = DefaultInventoryClasses.Num();
	for (int32 i = 0; i < NumWeaponClasses; i++)
	{
		if (DefaultInventoryClasses[i])
		{
			FActorSpawnParameters SpawnInfo;
			SpawnInfo.bNoCollisionFail = true;
			AMagicBattleSoccerWeapon* NewWeapon = GetWorld()->SpawnActor<AMagicBattleSoccerWeapon>(DefaultInventoryClasses[i], SpawnInfo);
			AddWeapon(NewWeapon);
		}
	}

	// equip first weapon in inventory
	if (Inventory.Num() > 0)
	{
		EquipPrimaryWeapon(Inventory[0]);
	}
	// equip second weapon in inventory
	if (Inventory.Num() > 1)
	{
		EquipSecondaryWeapon(Inventory[1]);
	}
}

void AMagicBattleSoccerCharacter::DestroyInventory()
{
	if (Role < ROLE_Authority)
	{
		return;
	}

	// remove all weapons from inventory and destroy them
	for (int32 i = Inventory.Num() - 1; i >= 0; i--)
	{
		AMagicBattleSoccerWeapon* Weapon = Inventory[i];
		if (Weapon)
		{
			RemoveWeapon(Weapon);
			Weapon->Destroy();
		}
	}
}

bool AMagicBattleSoccerCharacter::ServerEquipPrimaryWeapon_Validate(AMagicBattleSoccerWeapon* Weapon)
{
	return true;
}

void AMagicBattleSoccerCharacter::ServerEquipPrimaryWeapon_Implementation(AMagicBattleSoccerWeapon* Weapon)
{
	EquipPrimaryWeapon(Weapon);
}

bool AMagicBattleSoccerCharacter::ServerEquipSecondaryWeapon_Validate(AMagicBattleSoccerWeapon* Weapon)
{
	return true;
}

void AMagicBattleSoccerCharacter::ServerEquipSecondaryWeapon_Implementation(AMagicBattleSoccerWeapon* Weapon)
{
	EquipSecondaryWeapon(Weapon);
}

void AMagicBattleSoccerCharacter::AddWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon && Role == ROLE_Authority)
	{
		Weapon->OnEnterInventory(this);
		Inventory.AddUnique(Weapon);
	}
}

void AMagicBattleSoccerCharacter::RemoveWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon && Role == ROLE_Authority)
	{
		Weapon->OnLeaveInventory();
		Inventory.RemoveSingle(Weapon);
	}
}

void AMagicBattleSoccerCharacter::EquipPrimaryWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon)
	{
		if (Role == ROLE_Authority)
		{
			SetPrimaryWeapon(Weapon);
		}
		else
		{
			ServerEquipPrimaryWeapon(Weapon);
		}
	}
}

void AMagicBattleSoccerCharacter::EquipSecondaryWeapon(AMagicBattleSoccerWeapon* Weapon)
{
	if (Weapon)
	{
		if (Role == ROLE_Authority)
		{
			SetSecondaryWeapon(Weapon);
		}
		else
		{
			ServerEquipSecondaryWeapon(Weapon);
		}
	}
}

/** Called to change a player's outfit based on team */
void AMagicBattleSoccerCharacter::AssignUniform_Implementation()
{
	// Handled entirely in blueprints
}

//////////////////////////////////////////////////////////////////////////
// Actions

/** [local] starts weapon fire */
void AMagicBattleSoccerCharacter::StartPrimaryWeaponFire()
{
	if (!WantsPrimaryFire)
	{
		WantsPrimaryFire = true;
		if (PrimaryWeapon)
		{
			PrimaryWeapon->StartFire();
		}
	}
}

/** [local] stops weapon fire */
void AMagicBattleSoccerCharacter::StopPrimaryWeaponFire()
{
	if (WantsPrimaryFire)
	{
		WantsPrimaryFire = false;
		if (nullptr != PrimaryWeapon)
		{
			PrimaryWeapon->StopFire();
		}
	}
}

/** [local] starts secondary attack */
void AMagicBattleSoccerCharacter::StartSecondaryWeaponFire()
{
	if (!WantsSecondaryFire)
	{
		WantsSecondaryFire = true;
		if (nullptr != SecondaryWeapon)
		{
			SecondaryWeapon->StartFire();
		}
	}
}

/** [local] stops secondary attack */
void AMagicBattleSoccerCharacter::StopSecondaryWeaponFire()
{
	if (WantsSecondaryFire)
	{
		WantsSecondaryFire = false;
		if (nullptr != SecondaryWeapon)
		{
			SecondaryWeapon->StopFire();
		}
	}
}

/** check if pawn can fire weapon */
bool AMagicBattleSoccerCharacter::CanFire()
{
	return IsAlive() && GetGameState()->RoundInProgress;
}

/** [server] Updates the movement speed based on conditions (ball possessor, etc) */
void AMagicBattleSoccerCharacter::UpdateMovementSpeed()
{
	UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetComponentByClass(UCharacterMovementComponent::StaticClass()));
	AMagicBattleSoccerBall *Ball = GetSoccerBall();

	if (nullptr != Ball->Possessor && Ball->Possessor->GetUniqueID() == GetUniqueID())
	{
		CurrentMovementSpeed = DefaultMovementSpeed * 0.75f;
	}

	MovementComponent->MaxWalkSpeed = CurrentMovementSpeed;
}

/** [local] Kicks the ball with a force */
void AMagicBattleSoccerCharacter::KickBall(const FVector& Force)
{
	if (Role < ROLE_Authority)
	{
		ServerKickBall(Force);
	}
	else
	{
		AMagicBattleSoccerBall *Ball = GetSoccerBall();
		Ball->Kick(Force);
	}
}

/** [local] Kicks the ball to a location */
void AMagicBattleSoccerCharacter::KickBallToLocation(const FVector& Location, float AngleInDegrees)
{
	if (Role < ROLE_Authority)
	{
		ServerKickBallToLocation(Location, AngleInDegrees);
	}
	else
	{
		AMagicBattleSoccerBall *Ball = GetSoccerBall();
		Ball->KickToLocation(Location, AngleInDegrees);
	}
}


//////////////////////////////////////////////////////////////////////////
// Actions - server side

bool AMagicBattleSoccerCharacter::ServerKickBall_Validate(FVector Force)
{
	return IsAlive();
}

void AMagicBattleSoccerCharacter::ServerKickBall_Implementation(FVector Force)
{
	KickBall(Force);
}

bool AMagicBattleSoccerCharacter::ServerKickBallToLocation_Validate(FVector Force, float AngleInDegrees)
{
	return IsAlive();
}

void AMagicBattleSoccerCharacter::ServerKickBallToLocation_Implementation(FVector Force, float AngleInDegrees)
{
	KickBallToLocation(Force, AngleInDegrees);
}

//////////////////////////////////////////////////////////////////////////
// Player attributes

/** Gets the game mode (only the server should be interested in this) */
AMagicBattleSoccerGameMode* AMagicBattleSoccerCharacter::GetGameMode()
{
	return Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

/** Gets the game state (all instances should be interested in this) */
AMagicBattleSoccerGameState* AMagicBattleSoccerCharacter::GetGameState()
{
	UWorld *World = GetWorld();
	return World->GetGameState<AMagicBattleSoccerGameState>();
}

/** Gets the soccer ball */
AMagicBattleSoccerBall* AMagicBattleSoccerCharacter::GetSoccerBall()
{
	return GetGameState()->SoccerBall;
}

/** check if pawn is still alive */
bool AMagicBattleSoccerCharacter::IsAlive() const
{
	return Health > 0;
}

/** True if this player possesses the ball */
bool AMagicBattleSoccerCharacter::PossessesBall()
{
	AMagicBattleSoccerCharacter *Possessor = GetSoccerBall()->Possessor;
	return (this == Possessor);
}

