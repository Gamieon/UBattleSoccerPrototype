// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Soccer/MagicBattleSoccerSpawnPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerSpawnPoint() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint();
	ENGINE_API UClass* Z_Construct_UClass_ATargetPoint();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerAIController_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox_NoRegister();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerSpawnPoint_RoundHasStarted = FName(TEXT("RoundHasStarted"));
	void AMagicBattleSoccerSpawnPoint::RoundHasStarted()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerSpawnPoint_RoundHasStarted),NULL);
	}
	static FName NAME_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed = FName(TEXT("SpawnedPlayerBeingDestroyed"));
	void AMagicBattleSoccerSpawnPoint::SpawnedPlayerBeingDestroyed(AMagicBattleSoccerAIController* Controller)
	{
		MagicBattleSoccerSpawnPoint_eventSpawnedPlayerBeingDestroyed_Parms Parms;
		Parms.Controller=Controller;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed),&Parms);
	}
	void AMagicBattleSoccerSpawnPoint::StaticRegisterNativesAMagicBattleSoccerSpawnPoint()
	{
		UClass* Class = AMagicBattleSoccerSpawnPoint::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RoundHasStarted", &AMagicBattleSoccerSpawnPoint::execRoundHasStarted },
			{ "SpawnedPlayerBeingDestroyed", &AMagicBattleSoccerSpawnPoint::execSpawnedPlayerBeingDestroyed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "Called by the GameMode object when the next round has begun" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerSpawnPoint, nullptr, "RoundHasStarted", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerSpawnPoint_eventSpawnedPlayerBeingDestroyed_Parms, Controller), Z_Construct_UClass_AMagicBattleSoccerAIController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::NewProp_Controller,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "Called by the GameMode object when a spawned player is about to be destroyed" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerSpawnPoint, nullptr, "SpawnedPlayerBeingDestroyed", sizeof(MagicBattleSoccerSpawnPoint_eventSpawnedPlayerBeingDestroyed_Parms), Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister()
	{
		return AMagicBattleSoccerSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxBotsOnField_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxBotsOnField;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActionZone_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActionZone;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnSoccerBalls_MetaData[];
#endif
		static void NewProp_SpawnSoccerBalls_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SpawnSoccerBalls;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnHumanPlayers_MetaData[];
#endif
		static void NewProp_SpawnHumanPlayers_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SpawnHumanPlayers;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OwningTeamNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OwningTeamNumber;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATargetPoint,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_RoundHasStarted, "RoundHasStarted" }, // 296944076
		{ &Z_Construct_UFunction_AMagicBattleSoccerSpawnPoint_SpawnedPlayerBeingDestroyed, "SpawnedPlayerBeingDestroyed" }, // 1736214730
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_MaxBotsOnField_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "The maximum number of bots to spawn on the field" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_MaxBotsOnField = { "MaxBotsOnField", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerSpawnPoint, MaxBotsOnField), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_MaxBotsOnField_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_MaxBotsOnField_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_ActionZone_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "The zone that the spawned player is restricted to" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_ActionZone = { "ActionZone", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerSpawnPoint, ActionZone), Z_Construct_UClass_ATriggerBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_ActionZone_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_ActionZone_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "True if this is the spawn point for soccer balls when a round begins" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls_SetBit(void* Obj)
	{
		((AMagicBattleSoccerSpawnPoint*)Obj)->SpawnSoccerBalls = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls = { "SpawnSoccerBalls", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerSpawnPoint), &Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "True if this is the spawn point for spawning human players who are on the owning team" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers_SetBit(void* Obj)
	{
		((AMagicBattleSoccerSpawnPoint*)Obj)->SpawnHumanPlayers = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers = { "SpawnHumanPlayers", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerSpawnPoint), &Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_OwningTeamNumber_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerSpawnPoint.h" },
		{ "ToolTip", "The team number to assign to the spawned soccer player" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_OwningTeamNumber = { "OwningTeamNumber", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerSpawnPoint, OwningTeamNumber), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_OwningTeamNumber_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_OwningTeamNumber_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_MaxBotsOnField,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_ActionZone,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnSoccerBalls,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_SpawnHumanPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::NewProp_OwningTeamNumber,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::ClassParams = {
		&AMagicBattleSoccerSpawnPoint::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerSpawnPoint, 598297672);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerSpawnPoint>()
	{
		return AMagicBattleSoccerSpawnPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerSpawnPoint(Z_Construct_UClass_AMagicBattleSoccerSpawnPoint, &AMagicBattleSoccerSpawnPoint::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerSpawnPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerSpawnPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
