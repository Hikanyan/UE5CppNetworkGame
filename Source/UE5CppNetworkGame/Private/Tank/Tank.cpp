// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank/Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include <EnhancedInputSubsystems.h>
#include "InputAction.h"
#include <Kismet/KismetSystemLibrary.h>

#include "Kismet/GameplayStatics.h"


ATank::ATank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(SpringArm);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::PressedAxis(const FInputActionValue& Value)
{
	FVector2D v = Value.Get<FVector2D>();
	FVector DeltaLocation = FVector::ZeroVector;
	DeltaLocation.X = v.Y * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorLocalOffset(DeltaLocation, true);
	FVector DeltaRotaion = FVector::ZeroVector;
	DeltaRotaion.Y = v.X * Speed * UGameplayStatics::GetWorldDeltaSeconds(this);;
	AddActorLocalOffset(DeltaRotaion, true);
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("X:%f Y:%f"), v.X, v.Y), true, true,
	                                  FColor::Cyan, 10.0f, TEXT("None"));
}

void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent)
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::PressedAxis);
	}
	if (GetOwner()->InputComponent)
	{
		if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
		{
			// Input Mapping Contextを登録する
			if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
				ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
			{
				Subsystem->AddMappingContext(InputMapping.LoadSynchronous(), 0);
			}
		}
	}
}
