/** MagicBattleSoccerEngine.h - The one and only game application engine */

#pragma once

#include "Engine/GameEngine.h"
#include "MagicBattleSoccerEngine.generated.h"

UCLASS()
class MAGICBATTLESOCCER_API UMagicBattleSoccerEngine : public UGameEngine
{
	GENERATED_UCLASS_BODY()

private:
	/** The last error string received by the engine */
	FString LastErrorString;

public:
	/* Hook up specific callbacks */
	virtual void Init(IEngineLoop* InEngineLoop);

public:
	/** Gets the last error string */
	const FString& GetLastErrorString() const { return LastErrorString; }

	/** Clears the last error string */
	void ClearLastErrorString() { LastErrorString.Empty(); }

	/** Goes to the main menu */
	void GoToMainMenu();

public:
	/**
	* Notification of network error messages, allows the engine to handle the failure
	*
	* @param	World associated with failure
	* @param	FailureType	the type of error
	* @param	NetDriverName name of the network driver generating the error
	* @param	ErrorString	additional string detailing the error
	*/
	virtual void HandleNetworkFailure(UWorld *World, UNetDriver *NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString) override;

	/**
	* Notification of server travel error messages, generally network connection related (package verification, client server handshaking, etc)
	* allows the engine to handle the failure
	*
	* @param   InWorld     the world we were in when the travel failure occurred
	* @param	FailureType	the type of error
	* @param	ErrorString	additional string detailing the error
	*/
	virtual void HandleTravelFailure(UWorld* InWorld, ETravelFailure::Type FailureType, const FString& ErrorString);

};

