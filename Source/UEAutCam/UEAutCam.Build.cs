// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class UEAutCam : ModuleRules
	{
		public UEAutCam(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
            "UEAutCam/Public",
            "Runtime/Projects/Public"
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"UEAutCam/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
               "Engine",
               "Projects",
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

/*this needs to be resetup to use dynamic finding so that it is more portable at some point*/
                string torchpath = "/home/stephen-lilico/Torch/distro/";
                string ASMLuapath = "/home/stephen-lilico/CamContLua/ASMLua/";

                PrivateIncludePaths.AddRange(new string[] {ASMLuapath, Path.Combine(torchpath, "install","include"), "/home/stephen-lilico/ASM/TrackFusion/my_sleep"} );

                PublicIncludePaths.AddRange( new string[] { ASMLuapath, Path.Combine(torchpath, "install","include"), "/home/stephen-lilico/ASM/TrackFusion/my_sleep"} );
                //libraries have to be runtime rather than static so-     

                PublicLibraryPaths.AddRange(new string[] {Path.Combine(ASMLuapath, "build"),Path.Combine(torchpath, "install","lib"),Path.Combine(torchpath, "install","lib","lua","5.1")}); 

                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(ASMLuapath, "build","libASM_FFI.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","libluajit.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","ffi.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libpaths.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libtorch.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libsys.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libnnx.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libimage.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","lfs.so")));
                RuntimeDependencies.Add(new RuntimeDependency(Path.Combine(torchpath, "install","lib","lua","5.1","libppm.so")));
                //need the library as well


                PublicAdditionalLibraries.AddRange(new string[] {Path.Combine(ASMLuapath, "build","libASM_FFI.so"),Path.Combine(torchpath, "install","lib","libluajit.so"),Path.Combine(torchpath, "install","lib","lua","5.1","libpaths.so"),Path.Combine(torchpath, "install","lib","lua","5.1","ffi.so"),Path.Combine(torchpath, "install","lib","lua","5.1","libtorch.so"),Path.Combine(torchpath, "install","lib","lua","5.1","libsys.so"),Path.Combine(torchpath,"install","lib","lua","5.1","libnnx.so"),Path.Combine(torchpath,"install","lib","lua","5.1","lfs.so"),Path.Combine(torchpath,"install","lib","lua","5.1","libimage.so"),Path.Combine(torchpath,"install","lib","lua","5.1","libppm.so"),} );
                
		}
	}
}
