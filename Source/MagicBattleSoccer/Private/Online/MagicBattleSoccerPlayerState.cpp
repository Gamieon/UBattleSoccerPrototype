

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerState.h"

AMagicBattleSoccerPlayerState::AMagicBattleSoccerPlayerState(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// TODO: Let players choose their team. For now default all players to team 1.
	TeamNumber = 1;
}

void AMagicBattleSoccerPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMagicBattleSoccerPlayerState, TeamNumber);
}
