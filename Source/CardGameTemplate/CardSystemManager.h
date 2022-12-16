// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CardSystemManager.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API ACardSystemManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACardSystemManager();

	virtual void StartPlay() override;
};
