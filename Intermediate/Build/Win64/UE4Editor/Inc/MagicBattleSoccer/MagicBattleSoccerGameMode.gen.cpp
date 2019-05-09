// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Online/MagicBattleSoccerGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerGameMode() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
// End Cross Module References
	void AMagicBattleSoccerGameMode::StaticRegisterNativesAMagicBattleSoccerGameMode()
	{
		UClass* Class = AMagicBattleSoccerGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanBePursued", &AMagicBattleSoccerGameMode::execCanBePursued },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics
	{
		struct MagicBattleSoccerGameMode_eventCanBePursued_Parms
		{
			AMagicBattleSoccerCharacter* Player;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Player;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerGameMode_eventCanBePursued_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerGameMode_eventCanBePursued_Parms), &Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_Player = { "Player", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerGameMode_eventCanBePursued_Parms, Player), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::NewProp_Player,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameMode.h" },
		{ "ToolTip", "Determines whether a soccer player can be pursued by a bot" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerGameMode, nullptr, "CanBePursued", sizeof(MagicBattleSoccerGameMode_eventCanBePursued_Parms), Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_NoRegister()
	{
		return AMagicBattleSoccerGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerGameMode_CanBePursued, "CanBePursued" }, // 2112992097
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Online/MagicBattleSoccerGameMode.h" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The GameMode defines the game being played. It governs the game rules, scoring, what actors\nare allowed to exist in this game type, and who may enter the game.\nA GameMode actor is instantiated when the level is initialized for gameplay in\nC++ UGameEngine::LoadMap().  The class of this GameMode actor is determined by\n(in order) either the URL ?game=xxx, or the\nDefaultGameMode entry in the game's .ini file (in the /Script/Engine.Engine section).\nThe GameMode used can be overridden in the GameMode function GetGameModeClass(), called\non the game class picked by the above process." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::ClassParams = {
		&AMagicBattleSoccerGameMode::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerGameMode, 464087107);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerGameMode>()
	{
		return AMagicBattleSoccerGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerGameMode(Z_Construct_UClass_AMagicBattleSoccerGameMode, &AMagicBattleSoccerGameMode::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
