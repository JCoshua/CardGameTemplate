// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimaryCardDataAsset.h"
#include "DoubleAttackCardAsset.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API UDoubleAttackCardAsset : public UPrimaryCardDataAsset
{
	GENERATED_BODY()
	
public:
	void onCardAttack(ACard* target1, ACard* target2) override;
	void ResetStats(ACard* target) override;

private:
	bool statsChanged = false;
};
