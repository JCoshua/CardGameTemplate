// Copyright Epic Games, Inc. All Rights Reserved.

#include "CardGameTemplateGameMode.h"
#include "CardGameTemplatePlayerController.h"
#include "CardGameTemplatePawn.h"

ACardGameTemplateGameMode::ACardGameTemplateGameMode()
{
	// no pawn by default
	DefaultPawnClass = ACardGameTemplatePawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ACardGameTemplatePlayerController::StaticClass();
}
