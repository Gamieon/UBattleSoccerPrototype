

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerState.h"

AMagicBattleSoccerPlayerState::AMagicBattleSoccerPlayerState(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	TeamNumber = 0;
}

void AMagicBattleSoccerPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMagicBattleSoccerPlayerState, TeamNumber);
}
