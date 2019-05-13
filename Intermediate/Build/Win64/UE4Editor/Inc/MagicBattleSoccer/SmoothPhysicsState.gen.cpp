// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Online/SmoothPhysicsState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSmoothPhysicsState() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FSmoothPhysicsState();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
class UScriptStruct* FSmoothPhysicsState::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FSmoothPhysicsState_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FSmoothPhysicsState, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("SmoothPhysicsState"), sizeof(FSmoothPhysicsState), Get_Z_Construct_UScriptStruct_FSmoothPhysicsState_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FSmoothPhysicsState>()
{
	return FSmoothPhysicsState::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FSmoothPhysicsState(FSmoothPhysicsState::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("SmoothPhysicsState"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFSmoothPhysicsState
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFSmoothPhysicsState()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("SmoothPhysicsState")),new UScriptStruct::TCppStructOps<FSmoothPhysicsState>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFSmoothPhysicsState;
	struct Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_rot_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_rot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_vel_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_vel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_pos_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_timestamp_MetaData[];
#endif
		static const UE4CodeGen_Private::FUInt64PropertyParams NewProp_timestamp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Online/SmoothPhysicsState.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSmoothPhysicsState>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_rot_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Online/SmoothPhysicsState.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_rot = { "rot", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSmoothPhysicsState, rot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_rot_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_rot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_vel_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Online/SmoothPhysicsState.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_vel = { "vel", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSmoothPhysicsState, vel), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_vel_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_vel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_pos_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Online/SmoothPhysicsState.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_pos = { "pos", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSmoothPhysicsState, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_pos_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_pos_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_timestamp_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Online/SmoothPhysicsState.h" },
	};
#endif
	const UE4CodeGen_Private::FUInt64PropertyParams Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_timestamp = { "timestamp", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::UInt64, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSmoothPhysicsState, timestamp), METADATA_PARAMS(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_timestamp_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_timestamp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_rot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_vel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_pos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::NewProp_timestamp,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"SmoothPhysicsState",
		sizeof(FSmoothPhysicsState),
		alignof(FSmoothPhysicsState),
		Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSmoothPhysicsState()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FSmoothPhysicsState_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("SmoothPhysicsState"), sizeof(FSmoothPhysicsState), Get_Z_Construct_UScriptStruct_FSmoothPhysicsState_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FSmoothPhysicsState_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FSmoothPhysicsState_Hash() { return 4239037641U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
