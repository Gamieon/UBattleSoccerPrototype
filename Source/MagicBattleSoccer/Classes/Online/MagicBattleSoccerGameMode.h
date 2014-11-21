#pragma once

#include "GameFramework/GameMode.h"
#include "MagicBattleSoccerGameMode.generated.h"

class AMagicBattleSoccerBall;
class AMagicBattleSoccerGoal;
class AMagicBattleSoccerPlayer;

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 * A GameMode actor is instantiated when the level is initialized for gameplay in
 * C++ UGameEngine::LoadMap().  The class of this GameMode actor is determined by
 * (in order) either the URL ?game=xxx, or the
 * DefaultGameMode entry in the game's .ini file (in the /Script/Engine.Engine section).
 * The GameMode used can be overridden in the GameMode function GetGameModeClass(), called
 * on the game class picked by the above process.
 */
UCLASS()
class MAGICBATTLESOCCER_API AMagicBattleSoccerGameMode : public AGameMode
{
	GENERATED_UCLASS_BODY()

	//Begin AGameMode interface

	/** Returns game session class to use */
	virtual TSubclassOf<AGameSession> GetGameSessionClass() const override;

	void PostLogin(APlayerController* NewPlayer) override;

	//End AGameMode interface

	//////////////////////////////////////////////////////////////////////////
	// Damage & death

	/** prevents friendly fire */
	virtual float ModifyDamage(float Damage, AActor* DamagedActor, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) const;

	/** can players damage each other? */
	virtual bool CanDealDamage(class AMagicBattleSoccerPlayerState* DamageInstigator, class AMagicBattleSoccerPlayerState* DamagedPlayer) const;

	/** notify about kills */
	virtual void Killed(AController* Killer, AController* KilledPlayer, APawn* KilledPawn, const UDamageType* DamageType);
};
