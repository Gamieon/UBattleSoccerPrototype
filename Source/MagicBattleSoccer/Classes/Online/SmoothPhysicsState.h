#pragma once

#include "SmoothPhysicsState.generated.h"

USTRUCT()
struct FSmoothPhysicsState
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	uint64 timestamp;
	UPROPERTY()
	FVector pos;
	UPROPERTY()
	FVector vel;
	UPROPERTY()
	FRotator rot;

	FSmoothPhysicsState()
	{
		timestamp = 0;
		pos = FVector::ZeroVector;
		vel = FVector::ZeroVector;
		rot = FRotator::ZeroRotator;
	}
};
