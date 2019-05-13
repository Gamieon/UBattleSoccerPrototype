// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Weapons/MagicBattleSoccerWeapon_Trap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerWeapon_Trap() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerTrap_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned = FName(TEXT("OnTrapSpawned"));
	void AMagicBattleSoccerWeapon_Trap::OnTrapSpawned(AMagicBattleSoccerTrap* Trap)
	{
		MagicBattleSoccerWeapon_Trap_eventOnTrapSpawned_Parms Parms;
		Parms.Trap=Trap;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned),&Parms);
	}
	static FName NAME_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap = FName(TEXT("ServerSpawnTrap"));
	void AMagicBattleSoccerWeapon_Trap::ServerSpawnTrap(FVector Origin)
	{
		MagicBattleSoccerWeapon_Trap_eventServerSpawnTrap_Parms Parms;
		Parms.Origin=Origin;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap),&Parms);
	}
	void AMagicBattleSoccerWeapon_Trap::StaticRegisterNativesAMagicBattleSoccerWeapon_Trap()
	{
		UClass* Class = AMagicBattleSoccerWeapon_Trap::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnTrapSpawned", &AMagicBattleSoccerWeapon_Trap::execOnTrapSpawned },
			{ "ServerSpawnTrap", &AMagicBattleSoccerWeapon_Trap::execServerSpawnTrap },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Trap;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::NewProp_Trap = { "Trap", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_Trap_eventOnTrapSpawned_Parms, Trap), Z_Construct_UClass_AMagicBattleSoccerTrap_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::NewProp_Trap,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Trap.h" },
		{ "ToolTip", "Called when the trap is spawned" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap, nullptr, "OnTrapSpawned", sizeof(MagicBattleSoccerWeapon_Trap_eventOnTrapSpawned_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08080C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Origin;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerWeapon_Trap_eventServerSpawnTrap_Parms, Origin), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::NewProp_Origin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Trap.h" },
		{ "ToolTip", "spawn trap on server" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap, nullptr, "ServerSpawnTrap", sizeof(MagicBattleSoccerWeapon_Trap_eventServerSpawnTrap_Parms), Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A80CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_NoRegister()
	{
		return AMagicBattleSoccerWeapon_Trap::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TrapClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_TrapClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerWeapon,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_OnTrapSpawned, "OnTrapSpawned" }, // 3584763090
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_Trap_ServerSpawnTrap, "ServerSpawnTrap" }, // 4214212851
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/MagicBattleSoccerWeapon_Trap.h" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Trap.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::NewProp_TrapClass_MetaData[] = {
		{ "Category", "Projectile" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Trap.h" },
		{ "ToolTip", "trap class" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::NewProp_TrapClass = { "TrapClass", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon_Trap, TrapClass), Z_Construct_UClass_AMagicBattleSoccerTrap_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::NewProp_TrapClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::NewProp_TrapClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::NewProp_TrapClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerWeapon_Trap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::ClassParams = {
		&AMagicBattleSoccerWeapon_Trap::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerWeapon_Trap, 1108509359);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerWeapon_Trap>()
	{
		return AMagicBattleSoccerWeapon_Trap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerWeapon_Trap(Z_Construct_UClass_AMagicBattleSoccerWeapon_Trap, &AMagicBattleSoccerWeapon_Trap::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerWeapon_Trap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerWeapon_Trap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
