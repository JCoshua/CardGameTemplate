// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "InventorySlotAsset.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API UInventorySlotAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadOnly)
	class UPrimaryCardDataAsset* cardData;
	int cardCount;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
