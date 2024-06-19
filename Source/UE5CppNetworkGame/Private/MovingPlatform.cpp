// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	MyPoint = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 5秒たったら進む方向を反転する
	if (CurrentTime >= TimeToMove)
	{
		Speed *= -1;
		CurrentTime = 0.0f;
	}
	CurrentTime += DeltaTime;
	MyPoint += MoveVelocity * Speed * DeltaTime;
	SetActorLocation(MyPoint);
}
