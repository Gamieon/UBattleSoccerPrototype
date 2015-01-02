

#pragma once

#include "GameFramework/PlayerState.h"
#include "MagicBattleSoccerPlayerState.generated.h"

/**
 * A PlayerState is created for every player on a server (or in a standalone game).
 PlayerStates are replicated to all clients, and contain network game relevant information about the player,
 as playername, score, etc.
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerPlayerState : public APlayerState
{
	GENERATED_UCLASS_BODY()

	/** the character class to spawn */
	UPROPERTY(Transient, Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	TSubclassOf<class AMagicBattleSoccerCharacter> CharacterClass;

	/** the icon of the character */
	UPROPERTY(Transient, Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	UTexture2D *CharacterIcon;

	/** The team number */
	UPROPERTY(Transient, Replicated, EditAnywhere, BlueprintReadWrite, Category = Soccer)
	int32 TeamNumber;

	/** Assigns a unique bot name to the player */
	UFUNCTION(BlueprintCallable, Category = PlayerState)
	void AssignBotName();
};
