

#include "MagicBattleSoccerPlayerState.h"
#include "MagicBattleSoccer.h"
#include "MagicBattleSoccerGameMode.h"

AMagicBattleSoccerPlayerState::AMagicBattleSoccerPlayerState(const class FObjectInitializer& OI)
	: Super(OI)
{
	static ConstructorHelpers::FClassFinder<AMagicBattleSoccerCharacter> DefaultCharacter(TEXT("/Game/Characters/Tyler/tyler"));
	static ConstructorHelpers::FObjectFinder<UTexture2D> DefaultCharacterIcon(TEXT("/Game/Characters/Tyler/Textures/avatar_tyler"));

	TeamNumber = 0;

	// TODO: Have the character choose their class
	CharacterClass = DefaultCharacter.Class;
	CharacterIcon = DefaultCharacterIcon.Object;
}

void AMagicBattleSoccerPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMagicBattleSoccerPlayerState, CharacterClass);
	DOREPLIFETIME(AMagicBattleSoccerPlayerState, CharacterIcon);
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