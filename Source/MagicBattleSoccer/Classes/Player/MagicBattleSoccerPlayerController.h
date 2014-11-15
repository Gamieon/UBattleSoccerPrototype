

#pragma once

#include "GameFramework/PlayerController.h"
#include "MagicBattleSoccerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	/** stores pawn location at last player death, used where player scores a kill after they died **/
	FVector LastDeathLocation;

	//Begin AController interface

	/** sets up input */
	virtual void SetupInputComponent() override;

	/** Sets the pawn */
	virtual void SetPawn(APawn* inPawn) override;

	/** update camera when pawn dies */
	virtual void PawnPendingDestroy(APawn* inPawn) override;

	//End AController interface

	/** try to find spot for death cam */
	bool FindDeathCameraSpot(FVector& CameraLocation, FRotator& CameraRotation);

	//////////////////////////////////////////////////////////////////////////
	// Input handlers

	/** Player move forward event */
	void OnMoveForward(float axisValue);

	/** Player move right event */
	void OnMoveRight(float axisValue);

	/** Player primary action event */
	void OnStartPrimaryAction();

	/** Player primary action event */
	void OnStopPrimaryAction();

	/** Player suicide event */
	void OnSuicide();

};
