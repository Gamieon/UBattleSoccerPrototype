// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Online/MagicBattleSoccerGameMode_Menu.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerGameMode_Menu() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu();
	ENGINE_API UClass* Z_Construct_UClass_AGameMode();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void AMagicBattleSoccerGameMode_Menu::StaticRegisterNativesAMagicBattleSoccerGameMode_Menu()
	{
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_NoRegister()
	{
		return AMagicBattleSoccerGameMode_Menu::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameMode,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Online/MagicBattleSoccerGameMode_Menu.h" },
		{ "ModuleRelativePath", "Classes/Online/MagicBattleSoccerGameMode_Menu.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerGameMode_Menu>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::ClassParams = {
		&AMagicBattleSoccerGameMode_Menu::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerGameMode_Menu, 344525806);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerGameMode_Menu>()
	{
		return AMagicBattleSoccerGameMode_Menu::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerGameMode_Menu(Z_Construct_UClass_AMagicBattleSoccerGameMode_Menu, &AMagicBattleSoccerGameMode_Menu::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerGameMode_Menu"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerGameMode_Menu);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
