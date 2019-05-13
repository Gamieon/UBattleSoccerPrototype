// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/Weapons/MagicBattleSoccerWeapon_Bow.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerWeapon_Bow() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	static FName NAME_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent = FName(TEXT("UpdateDrawnArrowComponent"));
	void AMagicBattleSoccerWeapon_Bow::UpdateDrawnArrowComponent()
	{
		ProcessEvent(FindFunctionChecked(NAME_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent),NULL);
	}
	void AMagicBattleSoccerWeapon_Bow::StaticRegisterNativesAMagicBattleSoccerWeapon_Bow()
	{
		UClass* Class = AMagicBattleSoccerWeapon_Bow::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "UpdateDrawnArrowComponent", &AMagicBattleSoccerWeapon_Bow::execUpdateDrawnArrowComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Bow.h" },
		{ "ToolTip", "when equipping a bow, the instigator needs to have an arrow mesh in their hand so it looks like they're drawing an arrow from their\n      quiver before firing. This should be called whenever the weapon is equipped or unequipped to update the state of the arrow mesh." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow, nullptr, "UpdateDrawnArrowComponent", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_NoRegister()
	{
		return AMagicBattleSoccerWeapon_Bow::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawnArrowComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DrawnArrowComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DrawnArrowMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DrawnArrowMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMagicBattleSoccerWeapon_Projectile,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerWeapon_Bow_UpdateDrawnArrowComponent, "UpdateDrawnArrowComponent" }, // 1701659265
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Weapons/MagicBattleSoccerWeapon_Bow.h" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Bow.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowComponent_MetaData[] = {
		{ "Category", "Soccer" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Bow.h" },
		{ "ToolTip", "when this bow is equipped, this component contains the drawn arrow mesh that the instigator pulls from their quiver" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowComponent = { "DrawnArrowComponent", nullptr, (EPropertyFlags)0x001000000008000c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon_Bow, DrawnArrowComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowComponent_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowMesh_MetaData[] = {
		{ "Category", "Soccer" },
		{ "ModuleRelativePath", "Classes/Weapons/MagicBattleSoccerWeapon_Bow.h" },
		{ "ToolTip", "mesh for the arrow to be drawn when firing (I preferred to get this from the projectile data in the blueprint editor but couldn't figure out how" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowMesh = { "DrawnArrowMesh", nullptr, (EPropertyFlags)0x0010000000010015, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMagicBattleSoccerWeapon_Bow, DrawnArrowMesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowMesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::NewProp_DrawnArrowMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerWeapon_Bow>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::ClassParams = {
		&AMagicBattleSoccerWeapon_Bow::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::PropPointers),
		0,
		0x009000A1u,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerWeapon_Bow, 1038318936);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerWeapon_Bow>()
	{
		return AMagicBattleSoccerWeapon_Bow::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerWeapon_Bow(Z_Construct_UClass_AMagicBattleSoccerWeapon_Bow, &AMagicBattleSoccerWeapon_Bow::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerWeapon_Bow"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerWeapon_Bow);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
