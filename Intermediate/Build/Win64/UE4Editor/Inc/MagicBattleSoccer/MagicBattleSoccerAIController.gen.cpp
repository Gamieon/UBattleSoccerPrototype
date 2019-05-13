// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Bots/MagicBattleSoccerAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerAIController() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerAIController_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerAIController_RoundHasEnded = FName(TEXT("RoundHasEnded"));
	void AMagicBattleSoccerAIController::RoundHasEnded()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerAIController_RoundHasEnded),NULL);
	}
	static FName NAME_AMagicBattleSoccerAIController_RoundHasStarted = FName(TEXT("RoundHasStarted"));
	void AMagicBattleSoccerAIController::RoundHasStarted()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerAIController_RoundHasStarted),NULL);
	}
	static FName NAME_AMagicBattleSoccerAIController_SpawnCharacter = FName(TEXT("SpawnCharacter"));
	void AMagicBattleSoccerAIController::SpawnCharacter()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerAIController_SpawnCharacter),NULL);
	}
	void AMagicBattleSoccerAIController::StaticRegisterNativesAMagicBattleSoccerAIController()
	{
		UClass* Class = AMagicBattleSoccerAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanBePursued", &AMagicBattleSoccerAIController::execCanBePursued },
			{ "CanSpawnCharacter", &AMagicBattleSoccerAIController::execCanSpawnCharacter },
			{ "ClipToActionZone", &AMagicBattleSoccerAIController::execClipToActionZone },
			{ "GetClosestActorObstructingPoint", &AMagicBattleSoccerAIController::execGetClosestActorObstructingPoint },
			{ "GetClosestOpponent", &AMagicBattleSoccerAIController::execGetClosestOpponent },
			{ "GetEnemyGoal", &AMagicBattleSoccerAIController::execGetEnemyGoal },
			{ "GetIdealPassMate", &AMagicBattleSoccerAIController::execGetIdealPassMate },
			{ "GetIdealPossessorFollowLocation", &AMagicBattleSoccerAIController::execGetIdealPossessorFollowLocation },
			{ "GetIdealPursuitTarget", &AMagicBattleSoccerAIController::execGetIdealPursuitTarget },
			{ "GetOpponents", &AMagicBattleSoccerAIController::execGetOpponents },
			{ "GetTeammates", &AMagicBattleSoccerAIController::execGetTeammates },
			{ "KickBallToGoal", &AMagicBattleSoccerAIController::execKickBallToGoal },
			{ "KickBallToLocation", &AMagicBattleSoccerAIController::execKickBallToLocation },
			{ "RoundHasEnded", &AMagicBattleSoccerAIController::execRoundHasEnded },
			{ "RoundHasStarted", &AMagicBattleSoccerAIController::execRoundHasStarted },
			{ "SpawnCharacter", &AMagicBattleSoccerAIController::execSpawnCharacter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics
	{
		struct MagicBattleSoccerAIController_eventCanBePursued_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerAIController_eventCanBePursued_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerAIController_eventCanBePursued_Parms), &Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "True if the player can be pursued" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "CanBePursued", sizeof(MagicBattleSoccerAIController_eventCanBePursued_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics
	{
		struct MagicBattleSoccerAIController_eventCanSpawnCharacter_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerAIController_eventCanSpawnCharacter_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerAIController_eventCanSpawnCharacter_Parms), &Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Determines whether the character can be spawned at this time" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "CanSpawnCharacter", sizeof(MagicBattleSoccerAIController_eventCanSpawnCharacter_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics
	{
		struct MagicBattleSoccerAIController_eventClipToActionZone_Parms
		{
			FVector Location;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventClipToActionZone_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventClipToActionZone_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_Location_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_Location_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "If this player is in their action zone, call this function to ensure the location will not leave the zone bounds" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "ClipToActionZone", sizeof(MagicBattleSoccerAIController_eventClipToActionZone_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics
	{
		struct MagicBattleSoccerAIController_eventGetClosestActorObstructingPoint_Parms
		{
			FVector Point;
			TArray<AActor*> ActorsToIgnore;
			AActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActorsToIgnore_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ActorsToIgnore;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActorsToIgnore_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Point_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetClosestActorObstructingPoint_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore = { "ActorsToIgnore", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetClosestActorObstructingPoint_Parms, ActorsToIgnore), METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore_Inner = { "ActorsToIgnore", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_Point_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetClosestActorObstructingPoint_Parms, Point), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_Point_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_Point_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_ActorsToIgnore_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::NewProp_Point,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets the closest actor between this player and a point" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetClosestActorObstructingPoint", sizeof(MagicBattleSoccerAIController_eventGetClosestActorObstructingPoint_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics
	{
		struct MagicBattleSoccerAIController_eventGetClosestOpponent_Parms
		{
			AMagicBattleSoccerCharacter* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetClosestOpponent_Parms, ReturnValue), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets the closest enemy to this player that can be pursued" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetClosestOpponent", sizeof(MagicBattleSoccerAIController_eventGetClosestOpponent_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics
	{
		struct MagicBattleSoccerAIController_eventGetEnemyGoal_Parms
		{
			AMagicBattleSoccerGoal* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetEnemyGoal_Parms, ReturnValue), Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "The goal we want to kick the ball into" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetEnemyGoal", sizeof(MagicBattleSoccerAIController_eventGetEnemyGoal_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics
	{
		struct MagicBattleSoccerAIController_eventGetIdealPassMate_Parms
		{
			AMagicBattleSoccerCharacter* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetIdealPassMate_Parms, ReturnValue), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets the ideal teammate to pass the soccer ball to" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetIdealPassMate", sizeof(MagicBattleSoccerAIController_eventGetIdealPassMate_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics
	{
		struct MagicBattleSoccerAIController_eventGetIdealPossessorFollowLocation_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetIdealPossessorFollowLocation_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets the ideal point to run to when not chasing another actor while following the ball possessor" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetIdealPossessorFollowLocation", sizeof(MagicBattleSoccerAIController_eventGetIdealPossessorFollowLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics
	{
		struct MagicBattleSoccerAIController_eventGetIdealPursuitTarget_Parms
		{
			AActor* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetIdealPursuitTarget_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets the ideal object to run to if the player is idle" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetIdealPursuitTarget", sizeof(MagicBattleSoccerAIController_eventGetIdealPursuitTarget_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics
	{
		struct MagicBattleSoccerAIController_eventGetOpponents_Parms
		{
			TArray<AMagicBattleSoccerCharacter*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetOpponents_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets all the opponents of this player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetOpponents", sizeof(MagicBattleSoccerAIController_eventGetOpponents_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics
	{
		struct MagicBattleSoccerAIController_eventGetTeammates_Parms
		{
			TArray<AMagicBattleSoccerCharacter*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventGetTeammates_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::NewProp_ReturnValue_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Gets all the teammates of this player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "GetTeammates", sizeof(MagicBattleSoccerAIController_eventGetTeammates_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics
	{
		struct MagicBattleSoccerAIController_eventKickBallToGoal_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerAIController_eventKickBallToGoal_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerAIController_eventKickBallToGoal_Parms), &Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Tries to kick ball into the goal. Returns true if the ball was kicked." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "KickBallToGoal", sizeof(MagicBattleSoccerAIController_eventKickBallToGoal_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics
	{
		struct MagicBattleSoccerAIController_eventKickBallToLocation_Parms
		{
			FVector Location;
			float AngleInDegrees;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AngleInDegrees;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Location_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_AngleInDegrees = { "AngleInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventKickBallToLocation_Parms, AngleInDegrees), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_Location_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerAIController_eventKickBallToLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_Location_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_Location_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_AngleInDegrees,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::NewProp_Location,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Kicks the ball to the specified location" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "KickBallToLocation", sizeof(MagicBattleSoccerAIController_eventKickBallToLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04C20401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Called by the GameMode object when the current round has ended" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "RoundHasEnded", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Called by the GameMode object when the next round has begun. The character has not yet spawned at this point" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "RoundHasStarted", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "Spawns the character" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerAIController, nullptr, "SpawnCharacter", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerAIController_NoRegister()
	{
		return AMagicBattleSoccerAIController::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ActionZone_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ActionZone;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SpawnPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SpawnPoint;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_CanBePursued, "CanBePursued" }, // 2159917546
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_CanSpawnCharacter, "CanSpawnCharacter" }, // 156358512
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_ClipToActionZone, "ClipToActionZone" }, // 1413198799
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestActorObstructingPoint, "GetClosestActorObstructingPoint" }, // 374176914
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetClosestOpponent, "GetClosestOpponent" }, // 3528164733
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetEnemyGoal, "GetEnemyGoal" }, // 3637522205
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPassMate, "GetIdealPassMate" }, // 3977135673
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPossessorFollowLocation, "GetIdealPossessorFollowLocation" }, // 1102869129
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetIdealPursuitTarget, "GetIdealPursuitTarget" }, // 4145402632
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetOpponents, "GetOpponents" }, // 2201857474
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_GetTeammates, "GetTeammates" }, // 1654542030
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToGoal, "KickBallToGoal" }, // 2783005257
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_KickBallToLocation, "KickBallToLocation" }, // 2421591441
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasEnded, "RoundHasEnded" }, // 73243003
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_RoundHasStarted, "RoundHasStarted" }, // 1891328019
		{ &Z_Construct_UFunction_AMagicBattleSoccerAIController_SpawnCharacter, "SpawnCharacter" }, // 1297167413
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Bots/MagicBattleSoccerAIController.h" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_ActionZone_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "The zone that this player is restricted to. This is only used for AI\n      so only the server should care about this value." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_ActionZone = { "ActionZone", nullptr, (EPropertyFlags)0x0010000000002005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerAIController, ActionZone), Z_Construct_UClass_ATriggerBox_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_ActionZone_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_ActionZone_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_SpawnPoint_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Bots/MagicBattleSoccerAIController.h" },
		{ "ToolTip", "The spawn point where the character should spawn." },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_SpawnPoint = { "SpawnPoint", nullptr, (EPropertyFlags)0x0010000000002005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerAIController, SpawnPoint), Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_SpawnPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_SpawnPoint_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_ActionZone,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::NewProp_SpawnPoint,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::ClassParams = {
		&AMagicBattleSoccerAIController::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::PropPointers),
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerAIController, 2234312617);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerAIController>()
	{
		return AMagicBattleSoccerAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerAIController(Z_Construct_UClass_AMagicBattleSoccerAIController, &AMagicBattleSoccerAIController::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
