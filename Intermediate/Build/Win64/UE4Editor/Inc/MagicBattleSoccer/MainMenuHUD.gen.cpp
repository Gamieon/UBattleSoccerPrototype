// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/UI/MainMenuHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuHUD() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMainMenuHUD_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMainMenuHUD();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerHUD();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void AMainMenuHUD::StaticRegisterNativesAMainMenuHUD()
	{
	}
	UClass* Z_Construct_UClass_AMainMenuHUD_NoRegister()
	{
		return AMainMenuHUD::StaticClass();
	}
	struct Z_Construct_UClass_AMainMenuHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMainMenuHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainMenuHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "UI/MainMenuHUD.h" },
		{ "ModuleRelativePath", "Classes/UI/MainMenuHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "Provides an implementation of the game's Main Menu HUD, which will embed and respond to events triggered\nwithin SMainMenuUI." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMainMenuHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuHUD_Statics::ClassParams = {
		&AMainMenuHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMainMenuHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMainMenuHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMainMenuHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMainMenuHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMainMenuHUD, 3310569931);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMainMenuHUD>()
	{
		return AMainMenuHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMainMenuHUD(Z_Construct_UClass_AMainMenuHUD, &AMainMenuHUD::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMainMenuHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
