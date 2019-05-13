
#include "MagicBattleSoccerTrap.h"
#include "MagicBattleSoccer.h"

AMagicBattleSoccerTrap::AMagicBattleSoccerTrap(const class FObjectInitializer& OI)
	: Super(OI)
{
	bReplicates = true;
	bNetUseOwnerRelevancy = true;
	this->SetActorTickEnabled(true);
	PrimaryActorTick.bCanEverTick = true;
}
