// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/MagicBattleSoccerInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerInstance() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerInstance_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void UMagicBattleSoccerInstance::StaticRegisterNativesUMagicBattleSoccerInstance()
	{
	}
	UClass* Z_Construct_UClass_UMagicBattleSoccerInstance_NoRegister()
	{
		return UMagicBattleSoccerInstance::StaticClass();
	}
	struct Z_Construct_UClass_UMagicBattleSoccerInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MagicBattleSoccerInstance.h" },
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMagicBattleSoccerInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::ClassParams = {
		&UMagicBattleSoccerInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x000000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMagicBattleSoccerInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMagicBattleSoccerInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMagicBattleSoccerInstance, 534615244);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<UMagicBattleSoccerInstance>()
	{
		return UMagicBattleSoccerInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMagicBattleSoccerInstance(Z_Construct_UClass_UMagicBattleSoccerInstance, &UMagicBattleSoccerInstance::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("UMagicBattleSoccerInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMagicBattleSoccerInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
