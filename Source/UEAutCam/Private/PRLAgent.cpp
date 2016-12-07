// Fill out your copyright notice in the Description page of Project Settings.

#include "UEAutCamPrivatePCH.h"
#include "PRLAgent.h"


// Sets default values
APRLAgent::APRLAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APRLAgent::BeginPlay()
{
	Super::BeginPlay();
	ffi.trainStartClassNN("/home/stephen-lilico/CamContLua/Lua/LidarDetector.lua",1);
}

// Called every frame
void APRLAgent::Tick( float DeltaTime )
{
   Super::Tick( DeltaTime );
   std::vector<float> ffrew(1), nninput, rvals;
   ffrew.push_back(totalreward);
   //UE_LOG(LogTemp,Log,TEXT("giving fake output"));
   ffi.giveClassNNresult(ffrew);
   totalreward = 0;
   //setup the input appropriately
   nninput.push_back(1); //dummy variable for now to test
   nninput.push_back(2);
   //UE_LOG(LogTemp,Log,TEXT("giving fake input"));
   ffi.runClassifierNN(nninput, rvals);
}

// Called to bind functionality to input
void APRLAgent::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

//receieve reward function
void APRLAgent::recieveReward(float reward)
{
   totalreward+= reward;
}
