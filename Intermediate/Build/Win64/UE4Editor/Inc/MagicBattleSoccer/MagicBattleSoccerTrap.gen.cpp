// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Traps/MagicBattleSoccerTrap.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerTrap() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerTrap_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerTrap();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
// End Cross Module References
	void AMagicBattleSoccerTrap::StaticRegisterNativesAMagicBattleSoccerTrap()
	{
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerTrap_NoRegister()
	{
		return AMagicBattleSoccerTrap::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerTrap_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "Traps/MagicBattleSoccerTrap.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Classes/Traps/MagicBattleSoccerTrap.h" },
		{ "ToolTip", "Actor is the base class for an Object that can be placed or spawned in a level.\nActors may contain a collection of ActorComponents, which can be used to control how actors move, how they are rendered, etc.\nThe other main function of an Actor is the replication of properties and function calls across the network during play." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerTrap>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::ClassParams = {
		&AMagicBattleSoccerTrap::StaticClass,
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
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerTrap()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerTrap_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerTrap, 1405531803);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerTrap>()
	{
		return AMagicBattleSoccerTrap::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerTrap(Z_Construct_UClass_AMagicBattleSoccerTrap, &AMagicBattleSoccerTrap::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerTrap"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerTrap);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
