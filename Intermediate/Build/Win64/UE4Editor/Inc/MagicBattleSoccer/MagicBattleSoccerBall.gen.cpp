// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Soccer/MagicBattleSoccerBall.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerBall() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerBall_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerBall();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted();
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FSmoothPhysicsState();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerBall_CharacterHasDestroyed = FName(TEXT("CharacterHasDestroyed"));
	void AMagicBattleSoccerBall::CharacterHasDestroyed(AMagicBattleSoccerCharacter* Character)
	{
		MagicBattleSoccerBall_eventCharacterHasDestroyed_Parms Parms;
		Parms.Character=Character;
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerBall_CharacterHasDestroyed),&Parms);
	}
	static FName NAME_AMagicBattleSoccerBall_RoundHasStarted = FName(TEXT("RoundHasStarted"));
	void AMagicBattleSoccerBall::RoundHasStarted()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerBall_RoundHasStarted),NULL);
	}
	void AMagicBattleSoccerBall::StaticRegisterNativesAMagicBattleSoccerBall()
	{
		UClass* Class = AMagicBattleSoccerBall::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CharacterHasDestroyed", &AMagicBattleSoccerBall::execCharacterHasDestroyed },
			{ "IsFree", &AMagicBattleSoccerBall::execIsFree },
			{ "OnRep_ServerPhysicsState", &AMagicBattleSoccerBall::execOnRep_ServerPhysicsState },
			{ "RoundHasStarted", &AMagicBattleSoccerBall::execRoundHasStarted },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Character;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::NewProp_Character = { "Character", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerBall_eventCharacterHasDestroyed_Parms, Character), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::NewProp_Character,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "Called by a AMagicBattleSoccerCharacter object when it has been destroyed" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerBall, nullptr, "CharacterHasDestroyed", sizeof(MagicBattleSoccerBall_eventCharacterHasDestroyed_Parms), Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics
	{
		struct MagicBattleSoccerBall_eventIsFree_Parms
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
	void Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerBall_eventIsFree_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerBall_eventIsFree_Parms), &Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "True if the ball has no possessor and is not in a goal. Should only be called by the authority entity." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerBall, nullptr, "IsFree", sizeof(MagicBattleSoccerBall_eventIsFree_Parms), Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerBall, nullptr, "OnRep_ServerPhysicsState", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "Called by the GameMode object when the next round has begun" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerBall, nullptr, "RoundHasStarted", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerBall_NoRegister()
	{
		return AMagicBattleSoccerBall::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerBall_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsCharging_MetaData[];
#endif
		static void NewProp_IsCharging_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsCharging;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerPhysicsState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ServerPhysicsState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LastPossessor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LastPossessor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Possessor_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Possessor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerBall_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerBall_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerBall_CharacterHasDestroyed, "CharacterHasDestroyed" }, // 3823874084
		{ &Z_Construct_UFunction_AMagicBattleSoccerBall_IsFree, "IsFree" }, // 3010344950
		{ &Z_Construct_UFunction_AMagicBattleSoccerBall_OnRep_ServerPhysicsState, "OnRep_ServerPhysicsState" }, // 3365092016
		{ &Z_Construct_UFunction_AMagicBattleSoccerBall_RoundHasStarted, "RoundHasStarted" }, // 411672515
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerBall_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Soccer/MagicBattleSoccerBall.h" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "[server + local] True if the ball is charging" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging_SetBit(void* Obj)
	{
		((AMagicBattleSoccerBall*)Obj)->IsCharging = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging = { "IsCharging", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerBall), &Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_ServerPhysicsState_MetaData[] = {
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "The soccer ball orientation on the server" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_ServerPhysicsState = { "ServerPhysicsState", "OnRep_ServerPhysicsState", (EPropertyFlags)0x0010000100000020, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerBall, ServerPhysicsState), Z_Construct_UScriptStruct_FSmoothPhysicsState, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_ServerPhysicsState_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_ServerPhysicsState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_LastPossessor_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "The player who last possessed this soccer ball" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_LastPossessor = { "LastPossessor", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerBall, LastPossessor), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_LastPossessor_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_LastPossessor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_Possessor_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Soccer/MagicBattleSoccerBall.h" },
		{ "ToolTip", "The player that possesses this soccer ball" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_Possessor = { "Possessor", nullptr, (EPropertyFlags)0x0010000000020035, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerBall, Possessor), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_Possessor_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_Possessor_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerBall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_IsCharging,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_ServerPhysicsState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_LastPossessor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerBall_Statics::NewProp_Possessor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerBall_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerBall>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerBall_Statics::ClassParams = {
		&AMagicBattleSoccerBall::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerBall_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerBall_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerBall()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerBall_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerBall, 3985465997);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerBall>()
	{
		return AMagicBattleSoccerBall::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerBall(Z_Construct_UClass_AMagicBattleSoccerBall, &AMagicBattleSoccerBall::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerBall"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerBall);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
