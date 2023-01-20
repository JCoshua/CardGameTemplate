// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimaryCardDataAsset.h"
#include "AttackReducedWithHPCardAsset.generated.h"

UCLASS()
class CARDGAMETEMPLATE_API UAttackReducedWithHPCardAsset : public UPrimaryCardDataAsset
{
	GENERATED_BODY()
public:
	void onCardBattle(ACard* target1, ACard* target2) override;
};
