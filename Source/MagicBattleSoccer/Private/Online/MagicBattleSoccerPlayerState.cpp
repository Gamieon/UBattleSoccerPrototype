

#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccerGameMode.h"

AMagicBattleSoccerPlayerState::AMagicBattleSoccerPlayerState(const class FObjectInitializer& OI)
	: Super(OI)
{
	TeamNumber = 0;
}

void AMagicBattleSoccerPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMagicBattleSoccerPlayerState, TeamNumber);
}

/** Assigns a unique bot name to the player */
void AMagicBattleSoccerPlayerState::AssignBotName()
{
	if (ROLE_Authority > Role)
	{
		// Only servers should be calling this
	}
	else
	{
		AMagicBattleSoccerGameMode *GameMode = Cast<AMagicBattleSoccerGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		SetPlayerName(FString::Printf(TEXT("Bot %d"), GameMode->NextBotNameID++));
	}
}