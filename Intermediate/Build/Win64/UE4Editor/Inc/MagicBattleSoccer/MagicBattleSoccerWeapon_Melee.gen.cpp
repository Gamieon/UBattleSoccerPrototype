// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Weapons/MagicBattleSoccerWeapon_Melee.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerWeapon_Melee() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FMeleeWeaponData();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon();
// End Cross Module References
class UScriptStruct* FMeleeWeaponData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FMeleeWeaponData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMeleeWeaponData, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("MeleeWeaponData"), sizeof(FMeleeWeaponData), Get_Z_Construct_UScriptStruct_FMeleeWeaponData_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FMeleeWeaponData>()
{
	return FMeleeWeaponData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMeleeWeaponData(FMeleeWeaponData::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("MeleeWeaponData"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMeleeWeaponData
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMeleeWeaponData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MeleeWeaponData")),new UScriptStruct::TCppStructOps<FMeleeWeaponData>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMeleeWeaponData;
	struct Z_Construct_UScriptStruct_FMeleeWeaponData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DamageType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DamageRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Damage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMeleeWeaponData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageType_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
		{ "ToolTip", "type of damage" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeleeWeaponData, DamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageType_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageRadius_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
		{ "ToolTip", "radius of damage" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageRadius = { "DamageRadius", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeleeWeaponData, DamageRadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageRadius_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
		{ "ToolTip", "damage at impact point" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMeleeWeaponData, Damage), METADATA_PARAMS(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_Damage_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_Damage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_DamageRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::NewProp_Damage,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"MeleeWeaponData",
		sizeof(FMeleeWeaponData),
		alignof(FMeleeWeaponData),
		Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMeleeWeaponData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMeleeWeaponData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MeleeWeaponData"), sizeof(FMeleeWeaponData), Get_Z_Construct_UScriptStruct_FMeleeWeaponData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMeleeWeaponData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMeleeWeaponData_Hash() { return 855223115U; }
	void AMagicBattleSoccerWeapon_Melee::StaticRegisterNativesAMagicBattleSoccerWeapon_Melee()
	{
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_NoRegister()
	{
		return AMagicBattleSoccerWeapon_Melee::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeleeConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_MeleeConfig;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/MagicBattleSoccerWeapon_Melee.h" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::NewProp_MeleeConfig_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Melee.h" },
		{ "ToolTip", "weapon config" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::NewProp_MeleeConfig = { "MeleeConfig", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon_Melee, MeleeConfig), Z_Construct_UScriptStruct_FMeleeWeaponData, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::NewProp_MeleeConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::NewProp_MeleeConfig_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::NewProp_MeleeConfig,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerWeapon_Melee>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::ClassParams = {
		&AMagicBattleSoccerWeapon_Melee::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerWeapon_Melee, 3175844678);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerWeapon_Melee>()
	{
		return AMagicBattleSoccerWeapon_Melee::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerWeapon_Melee(Z_Construct_UClass_AMagicBattleSoccerWeapon_Melee, &AMagicBattleSoccerWeapon_Melee::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerWeapon_Melee"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerWeapon_Melee);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
