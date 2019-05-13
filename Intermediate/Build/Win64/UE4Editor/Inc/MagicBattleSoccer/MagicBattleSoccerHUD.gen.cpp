// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MagicBattleSoccer/Classes/UI/MagicBattleSoccerHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMagicBattleSoccerHUD() {}
// Cross Module References
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerHUD_NoRegister();
	MAGICBATTLESOCCER_API UClass* Z_Construct_UClass_AMagicBattleSoccerHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_MagicBattleSoccer();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor();
	MAGICBATTLESOCCER_API UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas();
// End Cross Module References
	void AMagicBattleSoccerHUD::StaticRegisterNativesAMagicBattleSoccerHUD()
	{
		UClass* Class = AMagicBattleSoccerHUD::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ClipPointToCanvas", &AMagicBattleSoccerHUD::execClipPointToCanvas },
			{ "ConvertXYToDegrees", &AMagicBattleSoccerHUD::execConvertXYToDegrees },
			{ "DrawFrame", &AMagicBattleSoccerHUD::execDrawFrame },
			{ "IsPointOnCanvas", &AMagicBattleSoccerHUD::execIsPointOnCanvas },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics
	{
		struct MagicBattleSoccerHUD_eventClipPointToCanvas_Parms
		{
			FVector2D Point;
			float Thickness;
			FVector2D ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Thickness;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventClipPointToCanvas_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventClipPointToCanvas_Parms, Thickness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventClipPointToCanvas_Parms, Point), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_Thickness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::NewProp_Point,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ToolTip", "clips a point to the canvas" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerHUD, nullptr, "ClipPointToCanvas", sizeof(MagicBattleSoccerHUD_eventClipPointToCanvas_Parms), Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics
	{
		struct MagicBattleSoccerHUD_eventConvertXYToDegrees_Parms
		{
			FVector2D Origin;
			FVector2D Point;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Origin;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventConvertXYToDegrees_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventConvertXYToDegrees_Parms, Point), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_Origin = { "Origin", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventConvertXYToDegrees_Parms, Origin), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_Point,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::NewProp_Origin,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ToolTip", "converts an XY position to degree angle" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerHUD, nullptr, "ConvertXYToDegrees", sizeof(MagicBattleSoccerHUD_eventConvertXYToDegrees_Parms), Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics
	{
		struct MagicBattleSoccerHUD_eventDrawFrame_Parms
		{
			FLinearColor FrameColor;
			float X;
			float Y;
			float Width;
			float Height;
			float Thickness;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Thickness;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Height;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Width;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Y;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_X;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_FrameColor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Thickness = { "Thickness", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, Thickness), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Height = { "Height", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, Height), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Width = { "Width", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, Width), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Y = { "Y", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, Y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_X = { "X", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, X), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_FrameColor = { "FrameColor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventDrawFrame_Parms, FrameColor), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Thickness,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Width,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_Y,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_X,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::NewProp_FrameColor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ToolTip", "draws a frame" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerHUD, nullptr, "DrawFrame", sizeof(MagicBattleSoccerHUD_eventDrawFrame_Parms), Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics
	{
		struct MagicBattleSoccerHUD_eventIsPointOnCanvas_Parms
		{
			FVector2D Point;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Point;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MagicBattleSoccerHUD_eventIsPointOnCanvas_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MagicBattleSoccerHUD_eventIsPointOnCanvas_Parms), &Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_Point = { "Point", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MagicBattleSoccerHUD_eventIsPointOnCanvas_Parms, Point), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::NewProp_Point,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::Function_MetaDataParams[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ToolTip", "determines if a point is on the visible canvas" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMagicBattleSoccerHUD, nullptr, "IsPointOnCanvas", sizeof(MagicBattleSoccerHUD_eventIsPointOnCanvas_Parms), Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMagicBattleSoccerHUD_NoRegister()
	{
		return AMagicBattleSoccerHUD::StaticClass();
	}
	struct Z_Construct_UClass_AMagicBattleSoccerHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsDebugMode_MetaData[];
#endif
		static void NewProp_IsDebugMode_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsDebugMode;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_MagicBattleSoccer,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMagicBattleSoccerHUD_ClipPointToCanvas, "ClipPointToCanvas" }, // 2263742448
		{ &Z_Construct_UFunction_AMagicBattleSoccerHUD_ConvertXYToDegrees, "ConvertXYToDegrees" }, // 2290852227
		{ &Z_Construct_UFunction_AMagicBattleSoccerHUD_DrawFrame, "DrawFrame" }, // 357583091
		{ &Z_Construct_UFunction_AMagicBattleSoccerHUD_IsPointOnCanvas, "IsPointOnCanvas" }, // 1746559095
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "UI/MagicBattleSoccerHUD.h" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
		{ "ToolTip", "The root HUD from which to derive all actual HUD's to be instantiated." },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode_MetaData[] = {
		{ "Category", "HUD" },
		{ "ModuleRelativePath", "Classes/UI/MagicBattleSoccerHUD.h" },
		{ "ToolTip", "determines whether we're in debug mode" },
	};
#endif
	void Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode_SetBit(void* Obj)
	{
		((AMagicBattleSoccerHUD*)Obj)->IsDebugMode = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode = { "IsDebugMode", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMagicBattleSoccerHUD), &Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode_MetaData, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::NewProp_IsDebugMode,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMagicBattleSoccerHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::ClassParams = {
		&AMagicBattleSoccerHUD::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::PropPointers),
		0,
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMagicBattleSoccerHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMagicBattleSoccerHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMagicBattleSoccerHUD, 597385167);
	template<> MAGICBATTLESOCCER_API UClass* StaticClass<AMagicBattleSoccerHUD>()
	{
		return AMagicBattleSoccerHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMagicBattleSoccerHUD(Z_Construct_UClass_AMagicBattleSoccerHUD, &AMagicBattleSoccerHUD::StaticClass, TEXT("/Script/MagicBattleSoccer"), TEXT("AMagicBattleSoccerHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMagicBattleSoccerHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
