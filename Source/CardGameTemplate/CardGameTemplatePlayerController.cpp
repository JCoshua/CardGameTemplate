// Copyright Epic Games, Inc. All Rights Reserved.

#include "CardGameTemplatePlayerController.h"

ACardGameTemplatePlayerController::ACardGameTemplatePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
