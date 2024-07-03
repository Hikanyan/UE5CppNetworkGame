// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AInputActor.generated.h"

UCLASS()
class UE5CPPNETWORKGAME_API AAInputActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAInputActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Function to handle game session creation
	UFUNCTION(BlueprintCallable, Category="Session")
	void CreateGameSession();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
