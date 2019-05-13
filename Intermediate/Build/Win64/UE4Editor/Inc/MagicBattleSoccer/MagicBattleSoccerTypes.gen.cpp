// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/MagicBattleSoccerTypes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerTypes() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FTakeHitInfo();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FRadialDamageEvent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FPointDamageEvent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FDamageEvent();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
class UScriptStruct* FTakeHitInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FTakeHitInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTakeHitInfo, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("TakeHitInfo"), sizeof(FTakeHitInfo), Get_Z_Construct_UScriptStruct_FTakeHitInfo_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FTakeHitInfo>()
{
	return FTakeHitInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTakeHitInfo(FTakeHitInfo::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("TakeHitInfo"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFTakeHitInfo
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFTakeHitInfo()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TakeHitInfo")),new UScriptStruct::TCppStructOps<FTakeHitInfo>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFTakeHitInfo;
	struct Z_Construct_UScriptStruct_FTakeHitInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RadialDamageEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RadialDamageEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PointDamageEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PointDamageEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GeneralDamageEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GeneralDamageEvent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EnsureReplicationByte_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnsureReplicationByte;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bKilled_MetaData[];
#endif
		static void NewProp_bKilled_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bKilled;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageEventClassID_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_DamageEventClassID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageCauser_MetaData[];
#endif
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_DamageCauser;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PawnInstigator_MetaData[];
#endif
		static const UE4CodeGen_Private::FWeakObjectPropertyParams NewProp_PawnInstigator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageTypeClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DamageTypeClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActualDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ActualDamage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "replicated information on a hit we've taken" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTakeHitInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_RadialDamageEvent_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Describes radial damage, if that is what was received." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_RadialDamageEvent = { "RadialDamageEvent", nullptr, (EPropertyFlags)0x0040008000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, RadialDamageEvent), Z_Construct_UScriptStruct_FRadialDamageEvent, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_RadialDamageEvent_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_RadialDamageEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PointDamageEvent_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Describes point damage, if that is what was received." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PointDamageEvent = { "PointDamageEvent", nullptr, (EPropertyFlags)0x0040008000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, PointDamageEvent), Z_Construct_UScriptStruct_FPointDamageEvent, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PointDamageEvent_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PointDamageEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_GeneralDamageEvent_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Describes general damage." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_GeneralDamageEvent = { "GeneralDamageEvent", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, GeneralDamageEvent), Z_Construct_UScriptStruct_FDamageEvent, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_GeneralDamageEvent_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_GeneralDamageEvent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_EnsureReplicationByte_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "A rolling counter used to ensure the struct is dirty and will replicate." },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_EnsureReplicationByte = { "EnsureReplicationByte", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, EnsureReplicationByte), nullptr, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_EnsureReplicationByte_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_EnsureReplicationByte_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Rather this was a kill" },
	};
#endif
	void Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled_SetBit(void* Obj)
	{
		((FTakeHitInfo*)Obj)->bKilled = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled = { "bKilled", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(uint8), sizeof(FTakeHitInfo), &Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageEventClassID_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Specifies which DamageEvent below describes the damage received." },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageEventClassID = { "DamageEventClassID", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, DamageEventClassID), METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageEventClassID_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageEventClassID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageCauser_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Who actually caused the damage" },
	};
#endif
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageCauser = { "DamageCauser", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, DamageCauser), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageCauser_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageCauser_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PawnInstigator_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "Who hit us" },
	};
#endif
	const UE4CodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PawnInstigator = { "PawnInstigator", nullptr, (EPropertyFlags)0x0014000000000000, UE4CodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, PawnInstigator), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PawnInstigator_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PawnInstigator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageTypeClass_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "The damage type we were hit with." },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageTypeClass = { "DamageTypeClass", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, DamageTypeClass), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageTypeClass_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageTypeClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_ActualDamage_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerTypes.h" },
		{ "ToolTip", "The amount of damage actually applied" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_ActualDamage = { "ActualDamage", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FTakeHitInfo, ActualDamage), METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_ActualDamage_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_ActualDamage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTakeHitInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_RadialDamageEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PointDamageEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_GeneralDamageEvent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_EnsureReplicationByte,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_bKilled,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageEventClassID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageCauser,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_PawnInstigator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_DamageTypeClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTakeHitInfo_Statics::NewProp_ActualDamage,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTakeHitInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"TakeHitInfo",
		sizeof(FTakeHitInfo),
		alignof(FTakeHitInfo),
		Z_Construct_UScriptStruct_FTakeHitInfo_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000005),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FTakeHitInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTakeHitInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTakeHitInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TakeHitInfo"), sizeof(FTakeHitInfo), Get_Z_Construct_UScriptStruct_FTakeHitInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTakeHitInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTakeHitInfo_Hash() { return 4115371990U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
