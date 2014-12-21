
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerWeapon_Bow.h"

AMagicBattleSoccerWeapon_Bow::AMagicBattleSoccerWeapon_Bow(const class FObjectInitializer& OI)
	: Super(OI)
{
	ArrowReleaseDelay = .5f;
	DrawnArrowComponent = nullptr;
}

//////////////////////////////////////////////////////////////////////////
// Inventory

/** weapon is being equipped by owner pawn */
void AMagicBattleSoccerWeapon_Bow::OnEquip(FName InSocketName)
{
	Super::OnEquip(InSocketName);
	// Make sure the instigator can draw an arrow out of their quiver as they fire
	UpdateDrawnArrowComponent();
	// Make sure the component is initially invisible
	if (nullptr != DrawnArrowComponent)
	{
		DrawnArrowComponent->SetVisibility(false);
	}
}

/** weapon is holstered by owner pawn */
void AMagicBattleSoccerWeapon_Bow::OnUnEquip()
{
	Super::OnUnEquip();
	// Ensure that any components we added to the instigator for our purposes are destroyed
	UpdateDrawnArrowComponent();
}

/** when equipping a bow, the instigator needs to have an arrow mesh in their hand so it looks like they're drawing an arrow from their
quiver before firing. This should be called whenever the weapon is equipped or unequipped to update the state of the arrow mesh. */
void AMagicBattleSoccerWeapon_Bow::UpdateDrawnArrowComponent_Implementation()
{
}

//////////////////////////////////////////////////////////////////////////
// Weapon usage

void AMagicBattleSoccerWeapon_Bow::FireWeapon()
{
	if (nullptr != Instigator && Instigator->GetVelocity().Size() > 0.001f)
	{
		// If the instigator is running, then fire the arrow immediately
		Super::FireWeapon();
	}
	else
	{
		// Make sure the user can see the instigator drawing an arrow out of their quiver
		if (nullptr != DrawnArrowComponent)
		{
			DrawnArrowComponent->SetVisibility(true);
		}

		// Set the timer for the delayed fire
		GetWorldTimerManager().SetTimer(this, &AMagicBattleSoccerWeapon_Bow::FireWeapon_Delayed, ArrowReleaseDelay);
	}
}

void AMagicBattleSoccerWeapon_Bow::FireWeapon_Delayed()
{
	Super::FireWeapon();

	// The arrow has been released, so hide the instigator's drawn arrow component
	if (nullptr != DrawnArrowComponent)
	{
		DrawnArrowComponent->SetVisibility(false);
	}
}