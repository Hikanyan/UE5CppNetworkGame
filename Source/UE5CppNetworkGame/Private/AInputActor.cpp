// Fill out your copyright notice in the Description page of Project Settings.


#include "AInputActor.h"
#include "Kismet/GameplayStatics.h" 
#include "../UE5CppNetworkGameCharacter.h"

// Sets default values
AAInputActor::AAInputActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAInputActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAInputActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AAInputActor::CreateGameSession()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("CreateGameSession triggered!"));
	}

	if (AUE5CppNetworkGameCharacter* Character = Cast<AUE5CppNetworkGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		Character->OnCreateSessionComplete(NAME_GameSession, true);
	}
}
