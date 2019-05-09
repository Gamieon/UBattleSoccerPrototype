// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/MagicBattleSoccerEngine.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerEngine() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerEngine_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerEngine();
	ENGINE_API UClass* Z_Construct_UClass_UGameEngine();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void UMagicBattleSoccerEngine::StaticRegisterNativesUMagicBattleSoccerEngine()
	{
	}
	UClass* Z_Construct_UClass_UMagicBattleSoccerEngine_NoRegister()
	{
		return UMagicBattleSoccerEngine::StaticClass();
	}
	struct Z_Construct_UClass_UMagicBattleSoccerEngine_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameEngine,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MagicBattleSoccerEngine.h" },
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerEngine.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMagicBattleSoccerEngine>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::ClassParams = {
		&UMagicBattleSoccerEngine::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000AEu,
		METADATA_PARAMS(Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMagicBattleSoccerEngine()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMagicBattleSoccerEngine_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMagicBattleSoccerEngine, 1323179369);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<UMagicBattleSoccerEngine>()
	{
		return UMagicBattleSoccerEngine::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMagicBattleSoccerEngine(Z_Construct_UClass_UMagicBattleSoccerEngine, &UMagicBattleSoccerEngine::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("UMagicBattleSoccerEngine"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMagicBattleSoccerEngine);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
