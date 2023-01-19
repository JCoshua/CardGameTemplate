// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryCardDataAsset.h"

FPrimaryAssetId UPrimaryCardDataAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("Cards", GetFName());
}

void UPrimaryCardDataAsset::BattleOpponent(UPrimaryCardDataAsset* target)
{
    Health -= (target->Attack - Defense);
    target->Health -= (Attack - target->Defense);
}
