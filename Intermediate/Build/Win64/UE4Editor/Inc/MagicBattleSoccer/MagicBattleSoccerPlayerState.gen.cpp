// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Online/MagicBattleSoccerPlayerState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerPlayerState() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerState();
	ENGINE_API UClass* Z_Construct_UClass_APlayerState();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister();
// End Cross Module References
	void AMagicBattleSoccerPlayerState::StaticRegisterNativesAMagicBattleSoccerPlayerState()
	{
		UClass* Class = AMagicBattleSoccerPlayerState::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AssignBotName", &AMagicBattleSoccerPlayerState::execAssignBotName },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics::Function_MetaDataParams[] = {
		{ "Category", "PlayerState" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerPlayerState.h" },
		{ "ToolTip", "Assigns a unique bot name to the player" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerPlayerState, nullptr, "AssignBotName", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerState_NoRegister()
	{
		return AMagicBattleSoccerPlayerState::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TeamNumber_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_TeamNumber;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterIcon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CharacterIcon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CharacterClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_CharacterClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerState,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerPlayerState_AssignBotName, "AssignBotName" }, // 3539620141
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Online/MagicBattleSoccerPlayerState.h" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerPlayerState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "A PlayerState is created for every player on a server (or in a standalone game).\n PlayerStates are replicated to all clients, and contain network game relevant information about the player,\n as playername, score, etc." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_TeamNumber_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerPlayerState.h" },
		{ "ToolTip", "The team number" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_TeamNumber = { "TeamNumber", nullptr, (EPropertyFlags)0x0010000000002025, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerPlayerState, TeamNumber), METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_TeamNumber_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_TeamNumber_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterIcon_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerPlayerState.h" },
		{ "ToolTip", "the icon of the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterIcon = { "CharacterIcon", nullptr, (EPropertyFlags)0x0010000000002025, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerPlayerState, CharacterIcon), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterIcon_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterIcon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterClass_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerPlayerState.h" },
		{ "ToolTip", "the character class to spawn" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterClass = { "CharacterClass", nullptr, (EPropertyFlags)0x0014000000002025, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerPlayerState, CharacterClass), Z_Construct_UClass_AMagicBattleSoccerCharacter_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterClass_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_TeamNumber,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterIcon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::NewProp_CharacterClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerPlayerState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::ClassParams = {
		&AMagicBattleSoccerPlayerState::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::PropPointers),
		0,
		0x009002A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerPlayerState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerPlayerState, 4144102631);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerPlayerState>()
	{
		return AMagicBattleSoccerPlayerState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerPlayerState(Z_Construct_UClass_AMagicBattleSoccerPlayerState, &AMagicBattleSoccerPlayerState::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerPlayerState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerPlayerState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
