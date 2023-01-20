// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimaryCardDataAsset.h"
#include "ShotgonCardAsset.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API UShotgonCardAsset : public UPrimaryCardDataAsset
{
	GENERATED_BODY()
	
public:
	void onCardAttack(ACard* target1, ACard* target2) override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int damageAmount = 0;
};
