// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "UEAutCamPrivatePCH.h"


#define NAUTCAMHANDLE 8

class FUEAutCam : public IUEAutCam
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
    static bool Initialize();
    const static int nhandles = NAUTCAMHANDLE;
protected:
/*helper functions*/
    static void FreeDependency(void*& Handle);
    static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);

    static void * handles[NAUTCAMHANDLE];
    static void * asmhandle;
    static FString handlenames[NAUTCAMHANDLE];
};

IMPLEMENT_MODULE( FUEAutCam, UEAutCam )

/*initialise the statics*/
void * FUEAutCam::handles [NAUTCAMHANDLE]= {nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr,nullptr};
void * FUEAutCam::asmhandle = nullptr;
FString FUEAutCam::handlenames[NAUTCAMHANDLE] = {"ffi","libpaths","libluajit","libtorch","libsys","libnnx","libimage","lfs"};

void FUEAutCam::StartupModule()
{
	// This code will execute after your module is loaded into memory (but after global variables are initialized, of course.)
}


void FUEAutCam::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
    for(int i = 0; i < nhandles; i++)
    {
        FreeDependency(handles[i]);
    }
    FreeDependency(asmhandle);
}

bool FUEAutCam::Initialize()
{
	// determine directory paths

	const FString LibDir = FPaths::Combine(TEXT("/home/stephen-lilico/Torch/distro/"), TEXT("install"), TEXT("lib"));
	const FString LLibDir = FPaths::Combine(*LibDir,TEXT("lua"),TEXT("5.1"));

	// load required libraries in the correct order
    for(int i = 0; i < NAUTCAMHANDLE; i++)
    {	
        if (!LoadDependency((i==2)? LibDir : LLibDir, handlenames[i],handles[i] ))
	    {
            for(int j = i; j > 0; j--)
            {
                FreeDependency(handles[j-1]);
            }
		    return false;
	    }
    }
   //ASMFFI loading
   if(!LoadDependency(FPaths::Combine(TEXT("/home/stephen-lilico/CamContLua/ASMLua/"),TEXT("build")),TEXT("libASM_FFI"),asmhandle))
   {
      for(int j = 0; j < NAUTCAMHANDLE; j++)
            {
                FreeDependency(handles[j]);
            }
		    return false;
   }
	
    return true;
}

void FUEAutCam::FreeDependency(void*& Handle)
{
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
}


bool FUEAutCam::LoadDependency(const FString& Dir, const FString& Name, void*& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		GLog->Logf(ELogVerbosity::Warning, TEXT("UEAutCam: Failed to load required library %s. Plug-in will not be functional."), *Lib);
		return false;
	}

	return true;
}


