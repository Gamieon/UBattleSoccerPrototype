// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Player/MainMenuPawn.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMainMenuPawn() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMainMenuPawn_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMainMenuPawn();
	ENGINE_API UClass* Z_Construct_UClass_ADefaultPawn();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void AMainMenuPawn::StaticRegisterNativesAMainMenuPawn()
	{
	}
	UClass* Z_Construct_UClass_AMainMenuPawn_NoRegister()
	{
		return AMainMenuPawn::StaticClass();
	}
	struct Z_Construct_UClass_AMainMenuPawn_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMainMenuPawn_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ADefaultPawn,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMainMenuPawn_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Player/MainMenuPawn.h" },
		{ "ModuleRelativePath", "Classes/Player/MainMenuPawn.h" },
		{ "ToolTip", "The pawn for the main menu. Allows for menu navigation but not world movement." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMainMenuPawn_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMainMenuPawn>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMainMenuPawn_Statics::ClassParams = {
		&AMainMenuPawn::StaticClass,
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
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_AMainMenuPawn_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMainMenuPawn_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMainMenuPawn()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMainMenuPawn_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMainMenuPawn, 2351510981);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMainMenuPawn>()
	{
		return AMainMenuPawn::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMainMenuPawn(Z_Construct_UClass_AMainMenuPawn, &AMainMenuPawn::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMainMenuPawn"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMainMenuPawn);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
