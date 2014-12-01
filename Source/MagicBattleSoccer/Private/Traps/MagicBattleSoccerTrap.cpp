
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerTrap.h"

AMagicBattleSoccerTrap::AMagicBattleSoccerTrap(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bReplicates = true;
	bReplicateInstigator = true;
	bNetUseOwnerRelevancy = true;
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}
