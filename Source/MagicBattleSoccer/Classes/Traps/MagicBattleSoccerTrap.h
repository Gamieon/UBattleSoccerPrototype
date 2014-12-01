#pragma once

#include "GameFramework/Actor.h"
#include "MagicBattleSoccerTrap.generated.h"


/**
* Actor is the base class for an Object that can be placed or spawned in a level.
* Actors may contain a collection of ActorComponents, which can be used to control how actors move, how they are rendered, etc.
* The other main function of an Actor is the replication of properties and function calls across the network during play.
*/
UCLASS(Abstract, Blueprintable)
class MAGICBATTLESOCCER_API AMagicBattleSoccerTrap : public AActor
{
	GENERATED_UCLASS_BODY()
};
