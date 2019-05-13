// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Weapons/MagicBattleSoccerWeapon.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerWeapon() {}
// Cross Module References
	MAGICBATTLESOCCER_API UEnum* Z_Construct_UEnum_MagicBattleSoccer_EWeaponState();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponActorEffectiveness();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FWeaponData();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	static UEnum* EWeaponState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_MagicBattleSoccer_EWeaponState, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("EWeaponState"));
		}
		return Singleton;
	}
	template<> MAGICBATTLESOCCER_API UEnum* StaticEnum<EWeaponState>()
	{
		return EWeaponState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EWeaponState(EWeaponState_StaticEnum, TEXT("/Script/MagicBattleSoccer"), TEXT("EWeaponState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_MagicBattleSoccer_EWeaponState_Hash() { return 857788319U; }
	UEnum* Z_Construct_UEnum_MagicBattleSoccer_EWeaponState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EWeaponState"), 0, Get_Z_Construct_UEnum_MagicBattleSoccer_EWeaponState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EWeaponState::Idle", (int64)EWeaponState::Idle },
				{ "EWeaponState::Firing", (int64)EWeaponState::Firing },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
				nullptr,
				"EWeaponState",
				"EWeaponState",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FWeaponActorEffectiveness::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponActorEffectiveness, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("WeaponActorEffectiveness"), sizeof(FWeaponActorEffectiveness), Get_Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FWeaponActorEffectiveness>()
{
	return FWeaponActorEffectiveness::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FWeaponActorEffectiveness(FWeaponActorEffectiveness::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("WeaponActorEffectiveness"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponActorEffectiveness
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponActorEffectiveness()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("WeaponActorEffectiveness")),new UScriptStruct::TCppStructOps<FWeaponActorEffectiveness>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponActorEffectiveness;
	struct Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HealthChange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HealthChange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponActorEffectiveness>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_HealthChange_MetaData[] = {
		{ "Category", "WeaponEffectiveness" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "The health change factor [-1,1]. A value of 1 means the actor would be destroyed.\n      A value of -1 means the actor would be restored to full health. A value of zero means\n      this weapon would have no effect on the actor" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_HealthChange = { "HealthChange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeaponActorEffectiveness, HealthChange), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_HealthChange_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_HealthChange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_Actor_MetaData[] = {
		{ "Category", "WeaponEffectiveness" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "The actor affected by this weapon" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeaponActorEffectiveness, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_Actor_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_Actor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_HealthChange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::NewProp_Actor,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"WeaponActorEffectiveness",
		sizeof(FWeaponActorEffectiveness),
		alignof(FWeaponActorEffectiveness),
		Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FWeaponActorEffectiveness()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("WeaponActorEffectiveness"), sizeof(FWeaponActorEffectiveness), Get_Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FWeaponActorEffectiveness_Hash() { return 3089755441U; }
class UScriptStruct* FWeaponData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FWeaponData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FWeaponData, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("WeaponData"), sizeof(FWeaponData), Get_Z_Construct_UScriptStruct_FWeaponData_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FWeaponData>()
{
	return FWeaponData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FWeaponData(FWeaponData::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("WeaponData"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponData
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("WeaponData")),new UScriptStruct::TCppStructOps<FWeaponData>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFWeaponData;
	struct Z_Construct_UScriptStruct_FWeaponData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterCanWalkWhileFiring_MetaData[];
#endif
		static void NewProp_CharacterCanWalkWhileFiring_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_CharacterCanWalkWhileFiring;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RepeatingFire_MetaData[];
#endif
		static void NewProp_RepeatingFire_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_RepeatingFire;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EffectiveRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_EffectiveRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AnimationTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AnimationTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeBetweenShots_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeBetweenShots;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWeaponData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWeaponData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "True if the character can walk while firing." },
	};
#endif
	void Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring_SetBit(void* Obj)
	{
		((FWeaponData*)Obj)->CharacterCanWalkWhileFiring = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring = { "CharacterCanWalkWhileFiring", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FWeaponData), &Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "True if the weapon continues to fire in TimeBetweenShot intervals.\n      False if the weapon only fires once, in which case when TimeBetweenShots\n      has expired, the pawn owner will be sent a notification and firing will cease." },
	};
#endif
	void Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire_SetBit(void* Obj)
	{
		((FWeaponData*)Obj)->RepeatingFire = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire = { "RepeatingFire", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FWeaponData), &Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_EffectiveRange_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "The effective range of the weapon. Used in AI to determine\n      whether the bot should fire at another soccer player." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_EffectiveRange = { "EffectiveRange", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeaponData, EffectiveRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_EffectiveRange_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_EffectiveRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_AnimationTime_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "the duration of the animation when attacking" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_AnimationTime = { "AnimationTime", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeaponData, AnimationTime), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_AnimationTime_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_AnimationTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_TimeBetweenShots_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "time between two consecutive shots" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_TimeBetweenShots = { "TimeBetweenShots", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWeaponData, TimeBetweenShots), METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_TimeBetweenShots_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_TimeBetweenShots_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWeaponData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_CharacterCanWalkWhileFiring,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_RepeatingFire,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_EffectiveRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_AnimationTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWeaponData_Statics::NewProp_TimeBetweenShots,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWeaponData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"WeaponData",
		sizeof(FWeaponData),
		alignof(FWeaponData),
		Z_Construct_UScriptStruct_FWeaponData_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FWeaponData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FWeaponData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FWeaponData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FWeaponData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("WeaponData"), sizeof(FWeaponData), Get_Z_Construct_UScriptStruct_FWeaponData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FWeaponData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FWeaponData_Hash() { return 966661402U; }
	static FName NAME_AMagicBattleSoccerWeapon_ServerHandleFiring = FName(TEXT("ServerHandleFiring"));
	void AMagicBattleSoccerWeapon::ServerHandleFiring()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_ServerHandleFiring),NULL);
	}
	static FName NAME_AMagicBattleSoccerWeapon_ServerSetTargetLocation = FName(TEXT("ServerSetTargetLocation"));
	void AMagicBattleSoccerWeapon::ServerSetTargetLocation(FVector TargetLocation)
	{
		MagicBattleSoccerWeapon_eventServerSetTargetLocation_Parms Parms;
		Parms.TargetLocation=TargetLocation;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_ServerSetTargetLocation),&Parms);
	}
	static FName NAME_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity = FName(TEXT("ServerSetTargetLocationAdjustedForVelocity"));
	void AMagicBattleSoccerWeapon::ServerSetTargetLocationAdjustedForVelocity(FVector TargetLocation, FVector TargetVelocity)
	{
		MagicBattleSoccerWeapon_eventServerSetTargetLocationAdjustedForVelocity_Parms Parms;
		Parms.TargetLocation=TargetLocation;
		Parms.TargetVelocity=TargetVelocity;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity),&Parms);
	}
	static FName NAME_AMagicBattleSoccerWeapon_ServerStartFire = FName(TEXT("ServerStartFire"));
	void AMagicBattleSoccerWeapon::ServerStartFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_ServerStartFire),NULL);
	}
	static FName NAME_AMagicBattleSoccerWeapon_ServerStopFire = FName(TEXT("ServerStopFire"));
	void AMagicBattleSoccerWeapon::ServerStopFire()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_ServerStopFire),NULL);
	}
	void AMagicBattleSoccerWeapon::StaticRegisterNativesAMagicBattleSoccerWeapon()
	{
		UClass* Class = AMagicBattleSoccerWeapon::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCurrentEffectiveness", &AMagicBattleSoccerWeapon::execGetCurrentEffectiveness },
			{ "GetCurrentState", &AMagicBattleSoccerWeapon::execGetCurrentState },
			{ "IsEquipped", &AMagicBattleSoccerWeapon::execIsEquipped },
			{ "OnRep_MyPawn", &AMagicBattleSoccerWeapon::execOnRep_MyPawn },
			{ "ServerHandleFiring", &AMagicBattleSoccerWeapon::execServerHandleFiring },
			{ "ServerSetTargetLocation", &AMagicBattleSoccerWeapon::execServerSetTargetLocation },
			{ "ServerSetTargetLocationAdjustedForVelocity", &AMagicBattleSoccerWeapon::execServerSetTargetLocationAdjustedForVelocity },
			{ "ServerStartFire", &AMagicBattleSoccerWeapon::execServerStartFire },
			{ "ServerStopFire", &AMagicBattleSoccerWeapon::execServerStopFire },
			{ "SetTargetLocation", &AMagicBattleSoccerWeapon::execSetTargetLocation },
			{ "SetTargetLocationAdjustedForVelocity", &AMagicBattleSoccerWeapon::execSetTargetLocationAdjustedForVelocity },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics
	{
		struct MagicBattleSoccerWeapon_eventGetCurrentEffectiveness_Parms
		{
			TArray<FWeaponActorEffectiveness> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventGetCurrentEffectiveness_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FWeaponActorEffectiveness, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "Returns how effective this weapon would be on scene actors in the world's current state" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "GetCurrentEffectiveness", sizeof(MagicBattleSoccerWeapon_eventGetCurrentEffectiveness_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics
	{
		struct MagicBattleSoccerWeapon_eventGetCurrentState_Parms
		{
			EWeaponState ReturnValue;
		};
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Underlying;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventGetCurrentState_Parms, ReturnValue), Z_Construct_UEnum_MagicBattleSoccer_EWeaponState, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::NewProp_ReturnValue_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::NewProp_ReturnValue_Underlying,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "get primary weapon state" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "GetCurrentState", sizeof(MagicBattleSoccerWeapon_eventGetCurrentState_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics
	{
		struct MagicBattleSoccerWeapon_eventIsEquipped_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerWeapon_eventIsEquipped_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerWeapon_eventIsEquipped_Parms), &Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "check if it's currently equipped" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "IsEquipped", sizeof(MagicBattleSoccerWeapon_eventIsEquipped_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "Replication & effects" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "OnRep_MyPawn", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "[server] fire & update ammo" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "ServerHandleFiring", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventServerSetTargetLocation_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::NewProp_TargetLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "Input - server side" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "ServerSetTargetLocation", sizeof(MagicBattleSoccerWeapon_eventServerSetTargetLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A80CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetVelocity;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetVelocity = { "TargetVelocity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventServerSetTargetLocationAdjustedForVelocity_Parms, TargetVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventServerSetTargetLocationAdjustedForVelocity_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "ServerSetTargetLocationAdjustedForVelocity", sizeof(MagicBattleSoccerWeapon_eventServerSetTargetLocationAdjustedForVelocity_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A80CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "ServerStartFire", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "ServerStopFire", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics
	{
		struct MagicBattleSoccerWeapon_eventSetTargetLocation_Parms
		{
			FVector TargetLocation;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventSetTargetLocation_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::NewProp_TargetLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "[local + server] sets the firing target" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "SetTargetLocation", sizeof(MagicBattleSoccerWeapon_eventSetTargetLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics
	{
		struct MagicBattleSoccerWeapon_eventSetTargetLocationAdjustedForVelocity_Parms
		{
			FVector TargetLocation;
			FVector TargetVelocity;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetVelocity;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TargetLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetVelocity = { "TargetVelocity", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventSetTargetLocationAdjustedForVelocity_Parms, TargetVelocity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_eventSetTargetLocationAdjustedForVelocity_Parms, TargetLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetVelocity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::NewProp_TargetLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "[local + server] sets the firing target" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon, nullptr, "SetTargetLocationAdjustedForVelocity", sizeof(MagicBattleSoccerWeapon_eventSetTargetLocationAdjustedForVelocity_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister()
	{
		return AMagicBattleSoccerWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ServerState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ServerState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LocalState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_LocalState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_LocalState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WeaponConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_WeaponConfig;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyPawn_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyPawn;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DashboardIcon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DashboardIcon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastFireTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LastFireTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentEffectiveness, "GetCurrentEffectiveness" }, // 4168426097
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_GetCurrentState, "GetCurrentState" }, // 1259297566
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_IsEquipped, "IsEquipped" }, // 4294219295
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_OnRep_MyPawn, "OnRep_MyPawn" }, // 2612753029
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerHandleFiring, "ServerHandleFiring" }, // 743981721
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocation, "ServerSetTargetLocation" }, // 1844128607
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerSetTargetLocationAdjustedForVelocity, "ServerSetTargetLocationAdjustedForVelocity" }, // 2153130928
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStartFire, "ServerStartFire" }, // 2224132871
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_ServerStopFire, "ServerStopFire" }, // 395601087
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocation, "SetTargetLocation" }, // 2029257553
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_SetTargetLocationAdjustedForVelocity, "SetTargetLocationAdjustedForVelocity" }, // 2339484268
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Weapons/MagicBattleSoccerWeapon.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "Actor is the base class for an Object that can be placed or spawned in a level.\nActors may contain a collection of ActorComponents, which can be used to control how actors move, how they are rendered, etc.\nThe other main function of an Actor is the replication of properties and function calls across the network during play." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "the weapon state as it is on the server." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState = { "ServerState", nullptr, (EPropertyFlags)0x0020080000002020, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, ServerState), Z_Construct_UEnum_MagicBattleSoccer_EWeaponState, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "[local] weapon state. this is first changed on the local player's instance, and then changed\n      on the server's instance once the server gets the ServerStartFire RPC." },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState = { "LocalState", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, LocalState), Z_Construct_UEnum_MagicBattleSoccer_EWeaponState, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_WeaponConfig_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "weapon data" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_WeaponConfig = { "WeaponConfig", nullptr, (EPropertyFlags)0x0020080000010015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, WeaponConfig), Z_Construct_UScriptStruct_FWeaponData, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_WeaponConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_WeaponConfig_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_MyPawn_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "pawn owner" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_MyPawn = { "MyPawn", "OnRep_MyPawn", (EPropertyFlags)0x0020080100002020, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, MyPawn), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_MyPawn_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_MyPawn_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_DashboardIcon_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "The weapon's icon to appear at the bottom of the screen" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_DashboardIcon = { "DashboardIcon", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, DashboardIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_DashboardIcon_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_DashboardIcon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LastFireTime_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon.h" },
		{ "ToolTip", "time of last successful weapon fire" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LastFireTime = { "LastFireTime", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon, LastFireTime), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LastFireTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LastFireTime_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_ServerState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LocalState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_WeaponConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_MyPawn,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_DashboardIcon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::NewProp_LastFireTime,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerWeapon>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::ClassParams = {
		&AMagicBattleSoccerWeapon::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerWeapon_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerWeapon, 381477393);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerWeapon>()
	{
		return AMagicBattleSoccerWeapon::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerWeapon(Z_Construct_UClass_AMagicBattleSoccerWeapon, &AMagicBattleSoccerWeapon::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerWeapon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerWeapon);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
