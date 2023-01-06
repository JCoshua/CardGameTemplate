// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CardDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API UCardDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadOnly)
	bool cardUsable = true;
};
