// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PrimaryCardDataAsset.generated.h"

UCLASS()
class CARDGAMETEMPLATE_API UPrimaryCardDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	class ACard* cardObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visuals")
	UTexture2D* texture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visuals")
	UMaterial* material;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	FName cardName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	bool cardUsable = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Health = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Attack = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Defense = 0;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
