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
	StartPoint = GetActorLocation();
	MyPoint = GetActorLocation();
	LocalEndPoint = StartPoint + GetTransform().TransformVector(LocalEndPoint); 
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// TODO:5秒たったら進む方向を反転する
	// if (CurrentTime >= TimeToMove)
	// {
	// 	Speed *= -1;
	// 	CurrentTime = 0.0f;
	// }


	// TODO:スタート地点とそこまで到達するまでの時間を指定して、その時間で移動する
	if (LocalEndPoint != FVector(0, 0, 0))
	{
		CurrentTime += DeltaTime;

		float Alpha = FMath::Clamp(CurrentTime / TimeToMove, 0.0f, 1.0f);
		MyPoint = FMath::Lerp(StartPoint, LocalEndPoint, Alpha);

		SetActorLocation(MyPoint);

		if (CurrentTime >= TimeToMove)
		{
			CurrentTime = 0.0f;
			FVector Temp = StartPoint;
			StartPoint = LocalEndPoint;
			LocalEndPoint = Temp;
		}
	}
}
