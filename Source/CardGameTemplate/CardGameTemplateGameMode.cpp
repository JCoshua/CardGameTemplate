// Copyright Epic Games, Inc. All Rights Reserved.

#include "CardGameTemplateGameMode.h"
#include "CardGameTemplatePlayerController.h"
#include "CardGamePawn.h"

ACardGameTemplateGameMode::ACardGameTemplateGameMode()
{
	// no pawn by default
	DefaultPawnClass = ACardGamePawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ACardGameTemplatePlayerController::StaticClass();
}
