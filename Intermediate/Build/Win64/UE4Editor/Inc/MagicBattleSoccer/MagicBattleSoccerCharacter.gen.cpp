// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Player/MagicBattleSoccerCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerCharacter() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FTakeHitInfo();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon = FName(TEXT("ServerEquipPrimaryWeapon"));
	void AMagicBattleSoccerCharacter::ServerEquipPrimaryWeapon(AMagicBattleSoccerWeapon* NewWeapon)
	{
		MagicBattleSoccerCharacter_eventServerEquipPrimaryWeapon_Parms Parms;
		Parms.NewWeapon=NewWeapon;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon),&Parms);
	}
	static FName NAME_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon = FName(TEXT("ServerEquipSecondaryWeapon"));
	void AMagicBattleSoccerCharacter::ServerEquipSecondaryWeapon(AMagicBattleSoccerWeapon* NewWeapon)
	{
		MagicBattleSoccerCharacter_eventServerEquipSecondaryWeapon_Parms Parms;
		Parms.NewWeapon=NewWeapon;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon),&Parms);
	}
	static FName NAME_AMagicBattleSoccerCharacter_ServerKickBall = FName(TEXT("ServerKickBall"));
	void AMagicBattleSoccerCharacter::ServerKickBall(FVector Force)
	{
		MagicBattleSoccerCharacter_eventServerKickBall_Parms Parms;
		Parms.Force=Force;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerCharacter_ServerKickBall),&Parms);
	}
	static FName NAME_AMagicBattleSoccerCharacter_ServerKickBallToLocation = FName(TEXT("ServerKickBallToLocation"));
	void AMagicBattleSoccerCharacter::ServerKickBallToLocation(FVector Force, float AngleInDegrees)
	{
		MagicBattleSoccerCharacter_eventServerKickBallToLocation_Parms Parms;
		Parms.Force=Force;
		Parms.AngleInDegrees=AngleInDegrees;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerCharacter_ServerKickBallToLocation),&Parms);
	}
	static FName NAME_AMagicBattleSoccerCharacter_SetTeamColors = FName(TEXT("SetTeamColors"));
	void AMagicBattleSoccerCharacter::SetTeamColors()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerCharacter_SetTeamColors),NULL);
	}
	void AMagicBattleSoccerCharacter::StaticRegisterNativesAMagicBattleSoccerCharacter()
	{
		UClass* Class = AMagicBattleSoccerCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetTeamNumber", &AMagicBattleSoccerCharacter::execGetTeamNumber },
			{ "OnRep_CurrentMovementSpeed", &AMagicBattleSoccerCharacter::execOnRep_CurrentMovementSpeed },
			{ "OnRep_IsStunned", &AMagicBattleSoccerCharacter::execOnRep_IsStunned },
			{ "OnRep_LastTakeHitInfo", &AMagicBattleSoccerCharacter::execOnRep_LastTakeHitInfo },
			{ "OnRep_PrimaryWeapon", &AMagicBattleSoccerCharacter::execOnRep_PrimaryWeapon },
			{ "OnRep_SecondaryWeapon", &AMagicBattleSoccerCharacter::execOnRep_SecondaryWeapon },
			{ "PossessesBall", &AMagicBattleSoccerCharacter::execPossessesBall },
			{ "ServerEquipPrimaryWeapon", &AMagicBattleSoccerCharacter::execServerEquipPrimaryWeapon },
			{ "ServerEquipSecondaryWeapon", &AMagicBattleSoccerCharacter::execServerEquipSecondaryWeapon },
			{ "ServerKickBall", &AMagicBattleSoccerCharacter::execServerKickBall },
			{ "ServerKickBallToLocation", &AMagicBattleSoccerCharacter::execServerKickBallToLocation },
			{ "SetTeamColors", &AMagicBattleSoccerCharacter::execSetTeamColors },
			{ "StartWeaponFire", &AMagicBattleSoccerCharacter::execStartWeaponFire },
			{ "StopWeaponFire", &AMagicBattleSoccerCharacter::execStopWeaponFire },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics
	{
		struct MagicBattleSoccerCharacter_eventGetTeamNumber_Parms
		{
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventGetTeamNumber_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "Gets the character's team number" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "GetTeamNumber", sizeof(MagicBattleSoccerCharacter_eventGetTeamNumber_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "OnRep_CurrentMovementSpeed", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "OnRep_IsStunned", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "play hit or death on client" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "OnRep_LastTakeHitInfo", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics
	{
		struct MagicBattleSoccerCharacter_eventOnRep_PrimaryWeapon_Parms
		{
			AMagicBattleSoccerWeapon* LastWeapon;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LastWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::NewProp_LastWeapon = { "LastWeapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventOnRep_PrimaryWeapon_Parms, LastWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::NewProp_LastWeapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "OnRep_PrimaryWeapon", sizeof(MagicBattleSoccerCharacter_eventOnRep_PrimaryWeapon_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics
	{
		struct MagicBattleSoccerCharacter_eventOnRep_SecondaryWeapon_Parms
		{
			AMagicBattleSoccerWeapon* LastWeapon;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LastWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::NewProp_LastWeapon = { "LastWeapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventOnRep_SecondaryWeapon_Parms, LastWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::NewProp_LastWeapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "OnRep_SecondaryWeapon", sizeof(MagicBattleSoccerCharacter_eventOnRep_SecondaryWeapon_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics
	{
		struct MagicBattleSoccerCharacter_eventPossessesBall_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerCharacter_eventPossessesBall_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerCharacter_eventPossessesBall_Parms), &Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "True if this player possesses the ball" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "PossessesBall", sizeof(MagicBattleSoccerCharacter_eventPossessesBall_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::NewProp_NewWeapon = { "NewWeapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventServerEquipPrimaryWeapon_Parms, NewWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::NewProp_NewWeapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "equip weapon" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "ServerEquipPrimaryWeapon", sizeof(MagicBattleSoccerCharacter_eventServerEquipPrimaryWeapon_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_NewWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::NewProp_NewWeapon = { "NewWeapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventServerEquipSecondaryWeapon_Parms, NewWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::NewProp_NewWeapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "equip weapon" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "ServerEquipSecondaryWeapon", sizeof(MagicBattleSoccerCharacter_eventServerEquipSecondaryWeapon_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80220CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Force;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::NewProp_Force = { "Force", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventServerKickBall_Parms, Force), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::NewProp_Force,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "Actions - server side" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "ServerKickBall", sizeof(MagicBattleSoccerCharacter_eventServerKickBall_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AngleInDegrees;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Force;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::NewProp_AngleInDegrees = { "AngleInDegrees", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventServerKickBallToLocation_Parms, AngleInDegrees), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::NewProp_Force = { "Force", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventServerKickBallToLocation_Parms, Force), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::NewProp_AngleInDegrees,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::NewProp_Force,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "ServerKickBallToLocation", sizeof(MagicBattleSoccerCharacter_eventServerKickBallToLocation_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80A20CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "Called to change a player's outfit based on team" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "SetTeamColors", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics
	{
		struct MagicBattleSoccerCharacter_eventStartWeaponFire_Parms
		{
			AMagicBattleSoccerWeapon* Weapon;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Weapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventStartWeaponFire_Parms, Weapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::NewProp_Weapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "[local] starts weapon fire" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "StartWeaponFire", sizeof(MagicBattleSoccerCharacter_eventStartWeaponFire_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics
	{
		struct MagicBattleSoccerCharacter_eventStopWeaponFire_Parms
		{
			AMagicBattleSoccerWeapon* Weapon;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Weapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerCharacter_eventStopWeaponFire_Parms, Weapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::NewProp_Weapon,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "[local] stops weapon fire" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerCharacter, nullptr, "StopWeaponFire", sizeof(MagicBattleSoccerCharacter_eventStopWeaponFire_Parms), Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister()
	{
		return AMagicBattleSoccerCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsStunned_MetaData[];
#endif
		static void NewProp_IsStunned_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsStunned;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SecondaryWeaponSocket_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SecondaryWeaponSocket;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrimaryWeaponSocket_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_PrimaryWeaponSocket;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SecondaryWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SecondaryWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PrimaryWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PrimaryWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultSecondaryWeaponClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DefaultSecondaryWeaponClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DefaultPrimaryWeaponClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DefaultPrimaryWeaponClass;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastTakeHitInfo_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LastTakeHitInfo;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastBallPossessionTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LastBallPossessionTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentMovementSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_CurrentMovementSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsDead_MetaData[];
#endif
		static void NewProp_bIsDead_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsDead;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_GetTeamNumber, "GetTeamNumber" }, // 1219429572
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_CurrentMovementSpeed, "OnRep_CurrentMovementSpeed" }, // 1354783389
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_IsStunned, "OnRep_IsStunned" }, // 4015929358
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_LastTakeHitInfo, "OnRep_LastTakeHitInfo" }, // 1367860416
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_PrimaryWeapon, "OnRep_PrimaryWeapon" }, // 82578269
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_OnRep_SecondaryWeapon, "OnRep_SecondaryWeapon" }, // 759251237
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_PossessesBall, "PossessesBall" }, // 1934056512
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipPrimaryWeapon, "ServerEquipPrimaryWeapon" }, // 1397308586
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerEquipSecondaryWeapon, "ServerEquipSecondaryWeapon" }, // 1103748515
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBall, "ServerKickBall" }, // 1468566658
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_ServerKickBallToLocation, "ServerKickBallToLocation" }, // 1888594634
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_SetTeamColors, "SetTeamColors" }, // 3047416900
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_StartWeaponFire, "StartWeaponFire" }, // 1632244768
		{ &Z_Construct_UFunction_AMagicBattleSoccerCharacter_StopWeaponFire, "StopWeaponFire" }, // 1631537071
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/MagicBattleSoccerCharacter.h" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "[server + local] True if the character is stunned" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned_SetBit(void* Obj)
	{
		((AMagicBattleSoccerCharacter*)Obj)->IsStunned = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned = { "IsStunned", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerCharacter), &Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeaponSocket_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The socket where the player holds the secondary weapon" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeaponSocket = { "SecondaryWeaponSocket", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, SecondaryWeaponSocket), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeaponSocket_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeaponSocket_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeaponSocket_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The socket where the player holds the primary weapon" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeaponSocket = { "PrimaryWeaponSocket", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, PrimaryWeaponSocket), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeaponSocket_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeaponSocket_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeapon_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The player's secondary weapon" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeapon = { "SecondaryWeapon", "OnRep_SecondaryWeapon", (EPropertyFlags)0x0010000100002034, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, SecondaryWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeapon_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The player's primary weapon" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeapon = { "PrimaryWeapon", "OnRep_PrimaryWeapon", (EPropertyFlags)0x0010000100002034, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, PrimaryWeapon), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeapon_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultSecondaryWeaponClass_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "default secondary weapon class" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultSecondaryWeaponClass = { "DefaultSecondaryWeaponClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, DefaultSecondaryWeaponClass), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultSecondaryWeaponClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultSecondaryWeaponClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultPrimaryWeaponClass_MetaData[] = {
		{ "Category", "Inventory" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "default primary weapon class" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultPrimaryWeaponClass = { "DefaultPrimaryWeaponClass", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, DefaultPrimaryWeaponClass), Z_Construct_UClass_AMagicBattleSoccerWeapon_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultPrimaryWeaponClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultPrimaryWeaponClass_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastTakeHitInfo_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "Replicate where this pawn was last hit and damaged" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastTakeHitInfo = { "LastTakeHitInfo", "OnRep_LastTakeHitInfo", (EPropertyFlags)0x0010008100002020, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, LastTakeHitInfo), Z_Construct_UScriptStruct_FTakeHitInfo, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastTakeHitInfo_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastTakeHitInfo_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastBallPossessionTime_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The last time that this player possessed the ball. Only the server\n      should care about this value." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastBallPossessionTime = { "LastBallPossessionTime", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, LastBallPossessionTime), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastBallPossessionTime_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastBallPossessionTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_CurrentMovementSpeed_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The current movement speed for this player. This changes if the player\n      possesses the ball" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_CurrentMovementSpeed = { "CurrentMovementSpeed", "OnRep_CurrentMovementSpeed", (EPropertyFlags)0x0010000100000020, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, CurrentMovementSpeed), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_CurrentMovementSpeed_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_CurrentMovementSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead_MetaData[] = {
		{ "Category", "MagicBattleSoccerCharacter" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "true if the character is dead" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead_SetBit(void* Obj)
	{
		((AMagicBattleSoccerCharacter*)Obj)->bIsDead = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead = { "bIsDead", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerCharacter), &Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_Health_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The health this player has" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, Health), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_Health_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_Health_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerCharacter.h" },
		{ "ToolTip", "The max health this player has" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000025, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerCharacter, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_MaxHealth_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_MaxHealth_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_IsStunned,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeaponSocket,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeaponSocket,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_SecondaryWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_PrimaryWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultSecondaryWeaponClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_DefaultPrimaryWeaponClass,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastTakeHitInfo,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_LastBallPossessionTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_CurrentMovementSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_bIsDead,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_Health,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::NewProp_MaxHealth,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::ClassParams = {
		&AMagicBattleSoccerCharacter::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerCharacter, 3806607130);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerCharacter>()
	{
		return AMagicBattleSoccerCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerCharacter(Z_Construct_UClass_AMagicBattleSoccerCharacter, &AMagicBattleSoccerCharacter::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
