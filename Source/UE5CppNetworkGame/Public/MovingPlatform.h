// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UE5CPPNETWORKGAME_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector MyPoint = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere)
	FVector MoveVelocity = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere)
	FVector StartPoint = FVector(0, 0, 0); 
	UPROPERTY(EditAnywhere)
	FVector LocalEndPoint = FVector(0, 0, 0);
	UPROPERTY(EditAnywhere)
	float Speed = 10.0f;
	UPROPERTY(EditAnywhere)
	float CurrentTime = 0.0f;
	UPROPERTY(EditAnywhere)
	float TimeToMove = 5.0f;
};
