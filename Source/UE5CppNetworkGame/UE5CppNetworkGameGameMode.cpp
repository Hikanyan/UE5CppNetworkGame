// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5CppNetworkGameGameMode.h"
#include "UE5CppNetworkGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5CppNetworkGameGameMode::AUE5CppNetworkGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
