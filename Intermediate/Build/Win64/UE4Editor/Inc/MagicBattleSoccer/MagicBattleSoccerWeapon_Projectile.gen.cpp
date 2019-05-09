// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerWeapon_Projectile() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FProjectileWeaponData();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_UDamageType_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerProjectile_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FVector_NetQuantizeNormal();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
class UScriptStruct* FProjectileWeaponData::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FProjectileWeaponData_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FProjectileWeaponData, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("ProjectileWeaponData"), sizeof(FProjectileWeaponData), Get_Z_Construct_UScriptStruct_FProjectileWeaponData_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FProjectileWeaponData>()
{
	return FProjectileWeaponData::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FProjectileWeaponData(FProjectileWeaponData::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("ProjectileWeaponData"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFProjectileWeaponData
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFProjectileWeaponData()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("ProjectileWeaponData")),new UScriptStruct::TCppStructOps<FProjectileWeaponData>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFProjectileWeaponData;
	struct Z_Construct_UScriptStruct_FProjectileWeaponData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReleaseDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReleaseDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageType_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DamageType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionRadius_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ExplosionRadius;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExplosionDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ExplosionDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileLife_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ProjectileLife;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ProjectileClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FProjectileWeaponData>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ReleaseDelay_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "how long to wait between the time the player fires and the time the projectile is released" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ReleaseDelay = { "ReleaseDelay", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, ReleaseDelay), METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ReleaseDelay_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ReleaseDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_DamageType_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "type of damage" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_DamageType = { "DamageType", nullptr, (EPropertyFlags)0x0014000000010015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, DamageType), Z_Construct_UClass_UDamageType_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_DamageType_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_DamageType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionRadius_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "radius of damage" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionRadius = { "ExplosionRadius", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, ExplosionRadius), METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionRadius_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionRadius_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionDamage_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "damage at impact point" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionDamage = { "ExplosionDamage", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, ExplosionDamage), METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionDamage_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileLife_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "life time" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileLife = { "ProjectileLife", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, ProjectileLife), METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileLife_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileLife_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileClass_MetaData[] = {
		{ "Category", "WeaponStat" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "projectile class" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileClass = { "ProjectileClass", nullptr, (EPropertyFlags)0x0014000000010015, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FProjectileWeaponData, ProjectileClass), Z_Construct_UClass_AMagicBattleSoccerProjectile_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileClass_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ReleaseDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_DamageType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ExplosionDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileLife,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::NewProp_ProjectileClass,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		nullptr,
		&NewStructOps,
		"ProjectileWeaponData",
		sizeof(FProjectileWeaponData),
		alignof(FProjectileWeaponData),
		Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FProjectileWeaponData()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FProjectileWeaponData_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ProjectileWeaponData"), sizeof(FProjectileWeaponData), Get_Z_Construct_UScriptStruct_FProjectileWeaponData_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FProjectileWeaponData_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FProjectileWeaponData_Hash() { return 645576474U; }
	static FName NAME_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile = FName(TEXT("ServerFireProjectile"));
	void AMagicBattleSoccerWeapon_Projectile::ServerFireProjectile(FVector Origin, FVector_NetQuantizeNormal ShootDir)
	{
		MagicBattleSoccerWeapon_Projectile_eventServerFireProjectile_Parms Parms;
		Parms.Origin=Origin;
		Parms.ShootDir=ShootDir;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile),&Parms);
	}
	void AMagicBattleSoccerWeapon_Projectile::StaticRegisterNativesAMagicBattleSoccerWeapon_Projectile()
	{
		UClass* Class = AMagicBattleSoccerWeapon_Projectile::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ServerFireProjectile", &AMagicBattleSoccerWeapon_Projectile::execServerFireProjectile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ShootDir;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Origin;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::NewProp_ShootDir = { "ShootDir", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_Projectile_eventServerFireProjectile_Parms, ShootDir), Z_Construct_UScriptStruct_FVector_NetQuantizeNormal, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_Projectile_eventServerFireProjectile_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::NewProp_ShootDir,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::NewProp_Origin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "spawn projectile on server" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile, nullptr, "ServerFireProjectile", sizeof(MagicBattleSoccerWeapon_Projectile_eventServerFireProjectile_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A80CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_NoRegister()
	{
		return AMagicBattleSoccerWeapon_Projectile::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ProjectileConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ProjectileConfig;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_Projectile_ServerFireProjectile, "ServerFireProjectile" }, // 2585889521
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::NewProp_ProjectileConfig_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Projectile.h" },
		{ "ToolTip", "weapon config" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::NewProp_ProjectileConfig = { "ProjectileConfig", nullptr, (EPropertyFlags)0x0020080000010015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon_Projectile, ProjectileConfig), Z_Construct_UScriptStruct_FProjectileWeaponData, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::NewProp_ProjectileConfig_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::NewProp_ProjectileConfig_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::NewProp_ProjectileConfig,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerWeapon_Projectile>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::ClassParams = {
		&AMagicBattleSoccerWeapon_Projectile::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerWeapon_Projectile, 2002661193);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerWeapon_Projectile>()
	{
		return AMagicBattleSoccerWeapon_Projectile::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerWeapon_Projectile(Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile, &AMagicBattleSoccerWeapon_Projectile::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerWeapon_Projectile"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerWeapon_Projectile);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
