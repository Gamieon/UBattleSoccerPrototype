// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/UI/SoccerGameHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoccerGameHUD() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_ASoccerGameHUD_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_ASoccerGameHUD();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerHUD();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void ASoccerGameHUD::StaticRegisterNativesASoccerGameHUD()
	{
	}
	UClass* Z_Construct_UClass_ASoccerGameHUD_NoRegister()
	{
		return ASoccerGameHUD::StaticClass();
	}
	struct Z_Construct_UClass_ASoccerGameHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoccerGameHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoccerGameHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "UI/SoccerGameHUD.h" },
		{ "ModuleRelativePath", "Classes/UI/SoccerGameHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoccerGameHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoccerGameHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASoccerGameHUD_Statics::ClassParams = {
		&ASoccerGameHUD::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ASoccerGameHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ASoccerGameHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASoccerGameHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASoccerGameHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASoccerGameHUD, 3901002010);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<ASoccerGameHUD>()
	{
		return ASoccerGameHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASoccerGameHUD(Z_Construct_UClass_ASoccerGameHUD, &ASoccerGameHUD::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("ASoccerGameHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoccerGameHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
