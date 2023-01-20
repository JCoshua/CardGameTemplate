// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryCardDataAsset.h"
#include "Card.h"

FPrimaryAssetId UPrimaryCardDataAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("Cards", GetFName());
}

void UPrimaryCardDataAsset::CardAdded(ACard* target)
{
    onCardAdded(target);
}

void UPrimaryCardDataAsset::CardUsed(ACard* target)
{
    onCardUsed(target);
}

void UPrimaryCardDataAsset::CardRemoved(ACard* target)
{
    onCardRemoved(target);
}

void UPrimaryCardDataAsset::CardPlaced(ACard* target)
{
    onCardPlaced(target);
}

void UPrimaryCardDataAsset::onCardAdded(ACard* target)
{
}

void UPrimaryCardDataAsset::onCardUsed(ACard* target)
{
}

void UPrimaryCardDataAsset::onCardRemoved(ACard* target)
{
}

void UPrimaryCardDataAsset::onCardPlaced(ACard* target)
{
}
