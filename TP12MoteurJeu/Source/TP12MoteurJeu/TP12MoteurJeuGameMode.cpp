// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP12MoteurJeuGameMode.h"
#include "TP12MoteurJeuPlayerController.h"
#include "TP12MoteurJeuCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATP12MoteurJeuGameMode::ATP12MoteurJeuGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATP12MoteurJeuPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}