// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PrimaryCardDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API UPrimaryCardDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	class ACard* cardObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	UTexture2D* texture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	FName cardName;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
