

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

	/** The team number */
	UPROPERTY(Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	int32 TeamNumber;
};
