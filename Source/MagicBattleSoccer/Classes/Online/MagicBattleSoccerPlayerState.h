

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

protected:
	/** The team number */
	UPROPERTY(Transient, Replicated, VisibleAnywhere, BlueprintReadOnly, Category = Soccer)
	int32 TeamNumber;

public:
	/**
	* Set new team and update pawn. Also updates player character team colors.
	*
	* @param	NewTeamNumber	Team we want to be on.
	*/
	UFUNCTION(BlueprintCallable, Category = Soccer)
	void SetTeamNum(int32 NewTeamNumber);

	/** get current team */
	int32 GetTeamNum() const;
};
