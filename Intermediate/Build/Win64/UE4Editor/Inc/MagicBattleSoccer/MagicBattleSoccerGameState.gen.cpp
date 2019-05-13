// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Online/MagicBattleSoccerGameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerGameState() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameState_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameState();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers();
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerBall_NoRegister();
// End Cross Module References
	void AMagicBattleSoccerGameState::StaticRegisterNativesAMagicBattleSoccerGameState()
	{
		UClass* Class = AMagicBattleSoccerGameState::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetClosestOpponent", &AMagicBattleSoccerGameState::execGetClosestOpponent },
			{ "GetClosestOpponentToLocation", &AMagicBattleSoccerGameState::execGetClosestOpponentToLocation },
			{ "GetOpponents", &AMagicBattleSoccerGameState::execGetOpponents },
			{ "GetTeammateControllers", &AMagicBattleSoccerGameState::execGetTeammateControllers },
			{ "GetTeammates", &AMagicBattleSoccerGameState::execGetTeammates },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics
	{
		struct MagicBattleSoccerGameState_eventGetClosestOpponent_Parms
		{
			AMagicBattleSoccerCharacter* Player;
			AMagicBattleSoccerCharacter* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetClosestOpponent_Parms, ReturnValue), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetClosestOpponent_Parms, Player), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::NewProp_Player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Gets the closest opponent" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameState, nullptr, "GetClosestOpponent", sizeof(MagicBattleSoccerGameState_eventGetClosestOpponent_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics
	{
		struct MagicBattleSoccerGameState_eventGetClosestOpponentToLocation_Parms
		{
			AMagicBattleSoccerCharacter* Player;
			FVector Location;
			AMagicBattleSoccerCharacter* ReturnValue;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Location;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetClosestOpponentToLocation_Parms, ReturnValue), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_Location = { "Location", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetClosestOpponentToLocation_Parms, Location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetClosestOpponentToLocation_Parms, Player), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_Location,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::NewProp_Player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Gets the closest enemy to a world location that can be pursued" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameState, nullptr, "GetClosestOpponentToLocation", sizeof(MagicBattleSoccerGameState_eventGetClosestOpponentToLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics
	{
		struct MagicBattleSoccerGameState_eventGetOpponents_Parms
		{
			AMagicBattleSoccerPlayerState* PlayerState;
			TArray<AMagicBattleSoccerCharacter*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetOpponents_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_PlayerState = { "PlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetOpponents_Parms, PlayerState), Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::NewProp_PlayerState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Gets all the opponents of a specified player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameState, nullptr, "GetOpponents", sizeof(MagicBattleSoccerGameState_eventGetOpponents_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics
	{
		struct MagicBattleSoccerGameState_eventGetTeammateControllers_Parms
		{
			AMagicBattleSoccerPlayerState* PlayerState;
			TArray<AController*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetTeammateControllers_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_PlayerState = { "PlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetTeammateControllers_Parms, PlayerState), Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::NewProp_PlayerState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Gets all the teammate controllers of a specified player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameState, nullptr, "GetTeammateControllers", sizeof(MagicBattleSoccerGameState_eventGetTeammateControllers_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics
	{
		struct MagicBattleSoccerGameState_eventGetTeammates_Parms
		{
			AMagicBattleSoccerPlayerState* PlayerState;
			TArray<AMagicBattleSoccerCharacter*> ReturnValue;
		};
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetTeammates_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_PlayerState = { "PlayerState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameState_eventGetTeammates_Parms, PlayerState), Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_ReturnValue_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::NewProp_PlayerState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Gets all the teammates of a specified player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameState, nullptr, "GetTeammates", sizeof(MagicBattleSoccerGameState_eventGetTeammates_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameState_NoRegister()
	{
		return AMagicBattleSoccerGameState::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerGameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RoundInProgress_MetaData[];
#endif
		static void NewProp_RoundInProgress_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_RoundInProgress;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PenetratedGoal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PenetratedGoal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team2Score_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Team2Score;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team1Score_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Team1Score;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team2SoccerBallSpawnPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Team2SoccerBallSpawnPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team1SoccerBallSpawnPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Team1SoccerBallSpawnPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team2Goal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Team2Goal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Team1Goal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Team1Goal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoccerBall_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoccerBall;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SoccerPlayers_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SoccerPlayers;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SoccerPlayers_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameState,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponent, "GetClosestOpponent" }, // 560798386
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameState_GetClosestOpponentToLocation, "GetClosestOpponentToLocation" }, // 1939125897
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameState_GetOpponents, "GetOpponents" }, // 2480586083
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammateControllers, "GetTeammateControllers" }, // 2554599814
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameState_GetTeammates, "GetTeammates" }, // 2683991206
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Online/MagicBattleSoccerGameState.h" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "GameState is replicated and is valid on servers and clients." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "True if a round is in progress; false if we're in between rounds" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress_SetBit(void* Obj)
	{
		((AMagicBattleSoccerGameState*)Obj)->RoundInProgress = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress = { "RoundInProgress", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerGameState), &Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_PenetratedGoal_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "The penetrated goal" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_PenetratedGoal = { "PenetratedGoal", nullptr, (EPropertyFlags)0x0010000000020025, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, PenetratedGoal), Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_PenetratedGoal_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_PenetratedGoal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Score_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 2 score" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Score = { "Team2Score", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team2Score), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Score_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Score_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Score_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 1 score" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Score = { "Team1Score", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team1Score), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Score_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Score_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2SoccerBallSpawnPoint_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 2 soccer ball spawn point. Cached locally for all sessions" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2SoccerBallSpawnPoint = { "Team2SoccerBallSpawnPoint", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team2SoccerBallSpawnPoint), Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2SoccerBallSpawnPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2SoccerBallSpawnPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1SoccerBallSpawnPoint_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 1 soccer ball spawn point. Cached locally for all sessions" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1SoccerBallSpawnPoint = { "Team1SoccerBallSpawnPoint", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team1SoccerBallSpawnPoint), Z_Construct_UClass_AMagicBattleSoccerSpawnPoint_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1SoccerBallSpawnPoint_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1SoccerBallSpawnPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Goal_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 2 goal. Cached locally for all sessions" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Goal = { "Team2Goal", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team2Goal), Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Goal_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Goal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Goal_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "Team 1 goal. Cached locally for all sessions" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Goal = { "Team1Goal", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, Team1Goal), Z_Construct_UClass_AMagicBattleSoccerGoal_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Goal_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Goal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerBall_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "The one and only soccer ball. Cached locally for all sessions" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerBall = { "SoccerBall", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, SoccerBall), Z_Construct_UClass_AMagicBattleSoccerBall_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerBall_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerBall_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameState.h" },
		{ "ToolTip", "The cache of all soccer players in the scene." },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers = { "SoccerPlayers", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerGameState, SoccerPlayers), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers_Inner = { "SoccerPlayers", nullptr, (EPropertyFlags)0x0000000000020000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_RoundInProgress,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_PenetratedGoal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Score,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Score,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2SoccerBallSpawnPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1SoccerBallSpawnPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team2Goal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_Team1Goal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerBall,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::NewProp_SoccerPlayers_Inner,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerGameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::ClassParams = {
		&AMagicBattleSoccerGameState::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::PropPointers),
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerGameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerGameState, 2622869341);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerGameState>()
	{
		return AMagicBattleSoccerGameState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerGameState(Z_Construct_UClass_AMagicBattleSoccerGameState, &AMagicBattleSoccerGameState::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerGameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerGameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
