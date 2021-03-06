// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Boilerplate C++ definitions for a single module.
	This is automatically generated by UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "Private/UEAutCamEditorPCH.h"
#include "GeneratedCppIncludes.h"
#include "UEAutCamEditor.generated.dep.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCode1UEAutCamEditor() {}
	void UUEAutCamSourceFactory::StaticRegisterNativesUUEAutCamSourceFactory()
	{
	}
	IMPLEMENT_CLASS(UUEAutCamSourceFactory, 3781655634);
#if USE_COMPILED_IN_NATIVES
// Cross Module References
	UNREALED_API class UClass* Z_Construct_UClass_UFactory();

	UEAUTCAMEDITOR_API class UClass* Z_Construct_UClass_UUEAutCamSourceFactory_NoRegister();
	UEAUTCAMEDITOR_API class UClass* Z_Construct_UClass_UUEAutCamSourceFactory();
	UEAUTCAMEDITOR_API class UPackage* Z_Construct_UPackage__Script_UEAutCamEditor();
	UClass* Z_Construct_UClass_UUEAutCamSourceFactory_NoRegister()
	{
		return UUEAutCamSourceFactory::StaticClass();
	}
	UClass* Z_Construct_UClass_UUEAutCamSourceFactory()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_UFactory();
			Z_Construct_UPackage__Script_UEAutCamEditor();
			OuterClass = UUEAutCamSourceFactory::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= 0x20000080;


				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Object"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("UEAutCamSourceFactory.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("Private/UEAutCamSourceFactory.h"));
				MetaData->SetValue(OuterClass, TEXT("ToolTip"), TEXT("Implements a factory for UFileMediaSource objects."));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUEAutCamSourceFactory(Z_Construct_UClass_UUEAutCamSourceFactory, &UUEAutCamSourceFactory::StaticClass, TEXT("UUEAutCamSourceFactory"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUEAutCamSourceFactory);
	UPackage* Z_Construct_UPackage__Script_UEAutCamEditor()
	{
		static UPackage* ReturnPackage = NULL;
		if (!ReturnPackage)
		{
			ReturnPackage = CastChecked<UPackage>(StaticFindObjectFast(UPackage::StaticClass(), NULL, FName(TEXT("/Script/UEAutCamEditor")), false, false));
			ReturnPackage->SetPackageFlags(PKG_CompiledIn | 0x00000040);
			FGuid Guid;
			Guid.A = 0x24D40645;
			Guid.B = 0x9A1B7490;
			Guid.C = 0x00000000;
			Guid.D = 0x00000000;
			ReturnPackage->SetGuid(Guid);

		}
		return ReturnPackage;
	}
#endif

PRAGMA_ENABLE_DEPRECATION_WARNINGS
