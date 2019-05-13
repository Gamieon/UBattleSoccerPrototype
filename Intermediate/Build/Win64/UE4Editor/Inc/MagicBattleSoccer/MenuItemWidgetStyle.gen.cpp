// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Private/UI/Style/MenuItemWidgetStyle.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMenuItemWidgetStyle() {}
// Cross Module References
	MAGICBATTLESOCCER_API UScriptStruct* Z_Construct_UScriptStruct_FMenuItemStyle();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateWidgetStyle();
	SLATECORE_API UScriptStruct* Z_Construct_UScriptStruct_FSlateBrush();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMenuItemWidgetStyle_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_UMenuItemWidgetStyle();
	SLATECORE_API UClass* Z_Construct_UClass_USlateWidgetStyleContainerBase();
// End Cross Module References
class UScriptStruct* FMenuItemStyle::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern MAGICBATTLESOCCER_API uint32 Get_Z_Construct_UScriptStruct_FMenuItemStyle_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMenuItemStyle, Z_Construct_UPackage__Script_MagicBattleSoccer(), TEXT("MenuItemStyle"), sizeof(FMenuItemStyle), Get_Z_Construct_UScriptStruct_FMenuItemStyle_Hash());
	}
	return Singleton;
}
template<> MAGICBATTLESOCCER_API UScriptStruct* StaticStruct<FMenuItemStyle>()
{
	return FMenuItemStyle::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMenuItemStyle(FMenuItemStyle::StaticStruct, TEXT("/Script/MagicBattleSoccer"), TEXT("MenuItemStyle"), false, nullptr, nullptr);
static struct FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuItemStyle
{
	FScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuItemStyle()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MenuItemStyle")),new UScriptStruct::TCppStructOps<FMenuItemStyle>);
	}
} ScriptStruct_MagicBattleSoccer_StaticRegisterNativesFMenuItemStyle;
	struct Z_Construct_UScriptStruct_FMenuItemStyle_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightArrowImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_RightArrowImage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftArrowImage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_LeftArrowImage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMenuItemStyle_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/UI/Style/MenuItemWidgetStyle.h" },
		{ "ToolTip", "Represents the appearance of an FMenuItem" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMenuItemStyle>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_RightArrowImage_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuItemWidgetStyle.h" },
		{ "ToolTip", "The image used for the right arrow" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_RightArrowImage = { "RightArrowImage", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMenuItemStyle, RightArrowImage), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_RightArrowImage_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_RightArrowImage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_LeftArrowImage_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuItemWidgetStyle.h" },
		{ "ToolTip", "The image used for the left arrow" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_LeftArrowImage = { "LeftArrowImage", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMenuItemStyle, LeftArrowImage), Z_Construct_UScriptStruct_FSlateBrush, METADATA_PARAMS(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_LeftArrowImage_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_LeftArrowImage_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMenuItemStyle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_RightArrowImage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMenuItemStyle_Statics::NewProp_LeftArrowImage,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMenuItemStyle_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
		Z_Construct_UScriptStruct_FSlateWidgetStyle,
		&NewStructOps,
		"MenuItemStyle",
		sizeof(FMenuItemStyle),
		alignof(FMenuItemStyle),
		Z_Construct_UScriptStruct_FMenuItemStyle_Statics::PropPointers,
		ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FMenuItemStyle_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMenuItemStyle()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMenuItemStyle_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_MagicBattleSoccer();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MenuItemStyle"), sizeof(FMenuItemStyle), Get_Z_Construct_UScriptStruct_FMenuItemStyle_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMenuItemStyle_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMenuItemStyle_Hash() { return 923795824U; }
	void UMenuItemWidgetStyle::StaticRegisterNativesUMenuItemWidgetStyle()
	{
	}
	UClass* Z_Construct_UClass_UMenuItemWidgetStyle_NoRegister()
	{
		return UMenuItemWidgetStyle::StaticClass();
	}
	struct Z_Construct_UClass_UMenuItemWidgetStyle_Statics
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
	UObject* (*const Z_Construct_UClass_UMenuItemWidgetStyle_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USlateWidgetStyleContainerBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuItemWidgetStyle_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Object Object" },
		{ "IncludePath", "UI/Style/MenuItemWidgetStyle.h" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuItemWidgetStyle.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMenuItemWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData[] = {
		{ "Category", "Appearance" },
		{ "ModuleRelativePath", "Private/UI/Style/MenuItemWidgetStyle.h" },
		{ "ShowOnlyInnerProperties", "" },
		{ "ToolTip", "The actual data describing the menu's appearance." },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UMenuItemWidgetStyle_Statics::NewProp_BackgroundStyle = { "BackgroundStyle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UMenuItemWidgetStyle, BackgroundStyle), Z_Construct_UScriptStruct_FMenuItemStyle, METADATA_PARAMS(Z_Construct_UClass_UMenuItemWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData, ARRAY_COUNT(Z_Construct_UClass_UMenuItemWidgetStyle_Statics::NewProp_BackgroundStyle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UMenuItemWidgetStyle_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UMenuItemWidgetStyle_Statics::NewProp_BackgroundStyle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMenuItemWidgetStyle_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMenuItemWidgetStyle>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UMenuItemWidgetStyle_Statics::ClassParams = {
		&UMenuItemWidgetStyle::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UMenuItemWidgetStyle_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		ARRAY_COUNT(Z_Construct_UClass_UMenuItemWidgetStyle_Statics::PropPointers),
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UMenuItemWidgetStyle_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UMenuItemWidgetStyle_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UMenuItemWidgetStyle()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UMenuItemWidgetStyle_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UMenuItemWidgetStyle, 179706176);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<UMenuItemWidgetStyle>()
	{
		return UMenuItemWidgetStyle::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UMenuItemWidgetStyle(Z_Construct_UClass_UMenuItemWidgetStyle, &UMenuItemWidgetStyle::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("UMenuItemWidgetStyle"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMenuItemWidgetStyle);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
