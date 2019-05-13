// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Private/UI/Style/MenuBackgroundWidgetStyle.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuBackgroundWidgetStyle() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FMenuBackgroundStyle();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateWidgetStyle();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMenuBackgroundWidgetStyle_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMenuBackgroundWidgetStyle();
	SLATECORE_API UClass* Z_Construct_UClass_USlateWidgetStyleContainerBase();
// End Cross Module References
class UScriptStruct* FMenuBackgroundStyle::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FMenuBackgroundStyle_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMenuBackgroundStyle, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("MenuBackgroundStyle"), sizeof(FMenuBackgroundStyle), Get_Z_Construct_UScriptStruct_FMenuBackgroundStyle_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FMenuBackgroundStyle>()
{
	return FMenuBackgroundStyle::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMenuBackgroundStyle(FMenuBackgroundStyle::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("MenuBackgroundStyle"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuBackgroundStyle
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuBackgroundStyle()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MenuBackgroundStyle")),new UScriptStruct::TCppStructOps<FMenuBackgroundStyle>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuBackgroundStyle;
	struct Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackgroundBrush_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BackgroundBrush;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/UI/Style/MenuBackgroundWidgetStyle.h" },
		{ "ToolTip", "Represents the appearance of an FMenuItem" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMenuBackgroundStyle>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewProp_BackgroundBrush_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuBackgroundWidgetStyle.h" },
		{ "ToolTip", "The brush used for the menu background" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewProp_BackgroundBrush = { "BackgroundBrush", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMenuBackgroundStyle, BackgroundBrush), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewProp_BackgroundBrush_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewProp_BackgroundBrush_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::NewProp_BackgroundBrush,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		Z_Construct_UScriptStruct_FSlateWidgetStyle,
		&NewStructOps,
		"MenuBackgroundStyle",
		sizeof(FMenuBackgroundStyle),
		alignof(FMenuBackgroundStyle),
		Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMenuBackgroundStyle()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMenuBackgroundStyle_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MenuBackgroundStyle"), sizeof(FMenuBackgroundStyle), Get_Z_Construct_UScriptStruct_FMenuBackgroundStyle_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMenuBackgroundStyle_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMenuBackgroundStyle_Hash() { return 1718024952U; }
	void UMenuBackgroundWidgetStyle::StaticRegisterNativesUMenuBackgroundWidgetStyle()
	{
	}
	UClass* Z_Construct_UClass_UMenuBackgroundWidgetStyle_NoRegister()
	{
		return UMenuBackgroundWidgetStyle::StaticClass();
	}
	struct Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BackgroundStyle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_BackgroundStyle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlateWidgetStyleContainerBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Object" },
		{ "IncludePath", "UI/Style/MenuBackgroundWidgetStyle.h" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuBackgroundWidgetStyle.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuBackgroundWidgetStyle.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "The actual data describing the menu's appearance." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::NewProp_BackgroundStyle = { "BackgroundStyle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuBackgroundWidgetStyle, BackgroundStyle), Z_Construct_UScriptStruct_FMenuBackgroundStyle, METADATA_PARAMS(Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::NewProp_BackgroundStyle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMenuBackgroundWidgetStyle>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::ClassParams = {
		&UMenuBackgroundWidgetStyle::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::PropPointers),
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMenuBackgroundWidgetStyle()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMenuBackgroundWidgetStyle_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMenuBackgroundWidgetStyle, 4061022365);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<UMenuBackgroundWidgetStyle>()
	{
		return UMenuBackgroundWidgetStyle::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMenuBackgroundWidgetStyle(Z_Construct_UClass_UMenuBackgroundWidgetStyle, &UMenuBackgroundWidgetStyle::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("UMenuBackgroundWidgetStyle"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMenuBackgroundWidgetStyle);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
