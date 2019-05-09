// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Player/MagicBattleSoccerPlayerController_Menu.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerPlayerController_Menu() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void AMagicBattleSoccerPlayerController_Menu::StaticRegisterNativesAMagicBattleSoccerPlayerController_Menu()
	{
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_NoRegister()
	{
		return AMagicBattleSoccerPlayerController_Menu::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Player/MagicBattleSoccerPlayerController_Menu.h" },
		{ "ModuleRelativePath", "Classes/Player/MagicBattleSoccerPlayerController_Menu.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerPlayerController_Menu>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::ClassParams = {
		&AMagicBattleSoccerPlayerController_Menu::StaticClass,
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
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerPlayerController_Menu, 3626523193);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerPlayerController_Menu>()
	{
		return AMagicBattleSoccerPlayerController_Menu::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerPlayerController_Menu(Z_Construct_UClass_AMagicBattleSoccerPlayerController_Menu, &AMagicBattleSoccerPlayerController_Menu::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerPlayerController_Menu"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerPlayerController_Menu);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
