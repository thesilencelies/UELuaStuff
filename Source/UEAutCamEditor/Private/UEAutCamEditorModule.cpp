// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "UEAutCamEditorPCH.h"
#include "ModuleInterface.h"


/**
 * Implements the UEAutCamEditor module.
 */
class FUEAutCamEditorModule
	: public IModuleInterface
{
public:

	//~ IModuleInterface interface

	virtual void StartupModule() override { }
	virtual void ShutdownModule() override { }
};


IMPLEMENT_MODULE(FUEAutCamEditorModule, UEAutCamEditor);
