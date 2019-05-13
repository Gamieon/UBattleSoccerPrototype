// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/MagicBattleSoccerUserSettings.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerUserSettings() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerUserSettings_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMagicBattleSoccerUserSettings();
	ENGINE_API UClass* Z_Construct_UClass_UGameUserSettings();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void UMagicBattleSoccerUserSettings::StaticRegisterNativesUMagicBattleSoccerUserSettings()
	{
	}
	UClass* Z_Construct_UClass_UMagicBattleSoccerUserSettings_NoRegister()
	{
		return UMagicBattleSoccerUserSettings::StaticClass();
	}
	struct Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PlayerName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameUserSettings,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MagicBattleSoccerUserSettings.h" },
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerUserSettings.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::NewProp_PlayerName_MetaData[] = {
		{ "ModuleRelativePath", "Classes/MagicBattleSoccerUserSettings.h" },
		{ "ToolTip", "The player name" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::NewProp_PlayerName = { "PlayerName", nullptr, (EPropertyFlags)0x0010000000004000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMagicBattleSoccerUserSettings, PlayerName), METADATA_PARAMS(Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::NewProp_PlayerName_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::NewProp_PlayerName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::NewProp_PlayerName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMagicBattleSoccerUserSettings>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::ClassParams = {
		&UMagicBattleSoccerUserSettings::StaticClass,
		"GameUserSettings",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::PropPointers),
		0,
		0x408000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMagicBattleSoccerUserSettings()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMagicBattleSoccerUserSettings_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMagicBattleSoccerUserSettings, 544130426);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<UMagicBattleSoccerUserSettings>()
	{
		return UMagicBattleSoccerUserSettings::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMagicBattleSoccerUserSettings(Z_Construct_UClass_UMagicBattleSoccerUserSettings, &UMagicBattleSoccerUserSettings::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("UMagicBattleSoccerUserSettings"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMagicBattleSoccerUserSettings);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
