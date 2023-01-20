// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimaryCardDataAsset.h"
#include "UseToHealCardAsset.generated.h"

UCLASS()
class CARDGAMETEMPLATE_API UUseToHealCardAsset : public UPrimaryCardDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int healAmount = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	bool removeOnUse = false;

	void onCardUsed(ACard* target) override;
	void onCardPlaced(ACard* target) override;
	void onCardRemoved(ACard* target) override;
};
