// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class UE5CPPNETWORKGAME_API ATestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 TestInt32 = 999;
	UPROPERTY(EditAnywhere)
	float Myfloat = 5.5f;
	UPROPERTY(EditAnywhere)
	bool MyBool = true;
	UPROPERTY(EditAnywhere)
	int32 Result;
};
