// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Player/MagicBattleSoccerPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerPlayerController() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerPlayerController_ClientGetServerTime = FName(TEXT("ClientGetServerTime"));
	void AMagicBattleSoccerPlayerController::ClientGetServerTime(int64 serverTime)
	{
		MagicBattleSoccerPlayerController_eventClientGetServerTime_Parms Parms;
		Parms.serverTime=serverTime;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ClientGetServerTime),&Parms);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera = FName(TEXT("ClientSetSpectatorCamera"));
	void AMagicBattleSoccerPlayerController::ClientSetSpectatorCamera(FVector CameraLocation, FRotator CameraRotation)
	{
		MagicBattleSoccerPlayerController_eventClientSetSpectatorCamera_Parms Parms;
		Parms.CameraLocation=CameraLocation;
		Parms.CameraRotation=CameraRotation;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera),&Parms);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerBeginChargingBall = FName(TEXT("ServerBeginChargingBall"));
	void AMagicBattleSoccerPlayerController::ServerBeginChargingBall()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerBeginChargingBall),NULL);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerForceActorRotation = FName(TEXT("ServerForceActorRotation"));
	void AMagicBattleSoccerPlayerController::ServerForceActorRotation(FRotator rotation)
	{
		MagicBattleSoccerPlayerController_eventServerForceActorRotation_Parms Parms;
		Parms.rotation=rotation;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerForceActorRotation),&Parms);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerGetServerTime = FName(TEXT("ServerGetServerTime"));
	void AMagicBattleSoccerPlayerController::ServerGetServerTime()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerGetServerTime),NULL);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerSetPlayerName = FName(TEXT("ServerSetPlayerName"));
	void AMagicBattleSoccerPlayerController::ServerSetPlayerName(const FString& PlayerName)
	{
		MagicBattleSoccerPlayerController_eventServerSetPlayerName_Parms Parms;
		Parms.PlayerName=PlayerName;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerSetPlayerName),&Parms);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerSpawnCharacter = FName(TEXT("ServerSpawnCharacter"));
	void AMagicBattleSoccerPlayerController::ServerSpawnCharacter()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerSpawnCharacter),NULL);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_ServerSuicide = FName(TEXT("ServerSuicide"));
	void AMagicBattleSoccerPlayerController::ServerSuicide()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_ServerSuicide),NULL);
	}
	static FName NAME_AMagicBattleSoccerPlayerController_SpawnCharacter = FName(TEXT("SpawnCharacter"));
	void AMagicBattleSoccerPlayerController::SpawnCharacter()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerPlayerController_SpawnCharacter),NULL);
	}
	void AMagicBattleSoccerPlayerController::StaticRegisterNativesAMagicBattleSoccerPlayerController()
	{
		UClass* Class = AMagicBattleSoccerPlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanSpawnCharacter", &AMagicBattleSoccerPlayerController::execCanSpawnCharacter },
			{ "ClientGetServerTime", &AMagicBattleSoccerPlayerController::execClientGetServerTime },
			{ "ClientSetSpectatorCamera", &AMagicBattleSoccerPlayerController::execClientSetSpectatorCamera },
			{ "ServerBeginChargingBall", &AMagicBattleSoccerPlayerController::execServerBeginChargingBall },
			{ "ServerForceActorRotation", &AMagicBattleSoccerPlayerController::execServerForceActorRotation },
			{ "ServerGetServerTime", &AMagicBattleSoccerPlayerController::execServerGetServerTime },
			{ "ServerSetPlayerName", &AMagicBattleSoccerPlayerController::execServerSetPlayerName },
			{ "ServerSpawnCharacter", &AMagicBattleSoccerPlayerController::execServerSpawnCharacter },
			{ "ServerSuicide", &AMagicBattleSoccerPlayerController::execServerSuicide },
			{ "SpawnCharacter", &AMagicBattleSoccerPlayerController::execSpawnCharacter },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics
	{
		struct MagicBattleSoccerPlayerController_eventCanSpawnCharacter_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerPlayerController_eventCanSpawnCharacter_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerPlayerController_eventCanSpawnCharacter_Parms), &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Determines whether the character can be spawned at this time" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "CanSpawnCharacter", sizeof(MagicBattleSoccerPlayerController_eventCanSpawnCharacter_Parms), Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics
	{
		static const UE4CodeGen_Private::FInt64PropertyParams NewProp_serverTime;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FInt64PropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::NewProp_serverTime = { "serverTime", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int64, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerPlayerController_eventClientGetServerTime_Parms, serverTime), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::NewProp_serverTime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Sent from the server to a client to give them the server's system time" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ClientGetServerTime", sizeof(MagicBattleSoccerPlayerController_eventClientGetServerTime_Parms), Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01080CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CameraRotation;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_CameraLocation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::NewProp_CameraRotation = { "CameraRotation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerPlayerController_eventClientSetSpectatorCamera_Parms, CameraRotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::NewProp_CameraLocation = { "CameraLocation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerPlayerController_eventClientSetSpectatorCamera_Parms, CameraLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::NewProp_CameraRotation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::NewProp_CameraLocation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "sets spectator location and rotation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ClientSetSpectatorCamera", sizeof(MagicBattleSoccerPlayerController_eventClientSetSpectatorCamera_Parms), Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x01820CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Requests that the server start charging the ball" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerBeginChargingBall", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_rotation;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::NewProp_rotation = { "rotation", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerPlayerController_eventServerForceActorRotation_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::NewProp_rotation,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Requests that the server change the character's rotation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerForceActorRotation", sizeof(MagicBattleSoccerPlayerController_eventServerForceActorRotation_Parms), Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Sent from a client to the server to get the server's system time" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerGetServerTime", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PlayerName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::NewProp_PlayerName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerPlayerController_eventServerSetPlayerName_Parms, PlayerName), METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::NewProp_PlayerName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::NewProp_PlayerName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::NewProp_PlayerName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Sent from a client to the server to set the client's player name. We don't use\n      any sort of known online subsystem so we do it this way" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerSetPlayerName", sizeof(MagicBattleSoccerPlayerController_eventServerSetPlayerName_Parms), Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Requests that the server spawns a character" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerSpawnCharacter", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "Requests that the server suicide this character" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "ServerSuicide", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
		{ "ToolTip", "[server] Spawns the character  via blueprints" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerController, nullptr, "SpawnCharacter", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_NoRegister()
	{
		return AMagicBattleSoccerPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_CanSpawnCharacter, "CanSpawnCharacter" }, // 2729499048
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientGetServerTime, "ClientGetServerTime" }, // 3007671822
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ClientSetSpectatorCamera, "ClientSetSpectatorCamera" }, // 3696641581
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerBeginChargingBall, "ServerBeginChargingBall" }, // 3424295171
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerForceActorRotation, "ServerForceActorRotation" }, // 1959353939
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerGetServerTime, "ServerGetServerTime" }, // 3348202360
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSetPlayerName, "ServerSetPlayerName" }, // 3513605268
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSpawnCharacter, "ServerSpawnCharacter" }, // 3229532621
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_ServerSuicide, "ServerSuicide" }, // 1967226282
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerController_SpawnCharacter, "SpawnCharacter" }, // 975461682
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Player/MagicBattleSoccerPlayerController.h" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::ClassParams = {
		&AMagicBattleSoccerPlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerPlayerController, 634064561);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerPlayerController>()
	{
		return AMagicBattleSoccerPlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerPlayerController(Z_Construct_UClass_AMagicBattleSoccerPlayerController, &AMagicBattleSoccerPlayerController::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
