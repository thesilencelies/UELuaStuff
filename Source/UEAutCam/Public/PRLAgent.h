// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "ASMFFI.h"

#include "PRLAgent.generated.h"

UCLASS()
class APRLAgent : public ACharacter
{
	GENERATED_BODY()
   //ASMFFI object to interface with the lua
   ASMFFI ffi;
  
public:
	// Sets default values for this character's properties
	APRLAgent();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//the total reward the agent has experienced this timestep
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RLVariables")
    float totalreward = 0;

    //incriments total reward for this step
    UFUNCTION(BlueprintCallable, Category="RLFunctions")
    void recieveReward(float reward); 
	
   // void recieveReward_Implementation(float reward);
};
