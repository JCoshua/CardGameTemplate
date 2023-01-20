// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryCardDataAsset.h"
#include "Card.h"

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

void UPrimaryCardDataAsset::AttackCard(ACard* target1, ACard* target2)
{
    onCardAttack(target1, target2);
}

void UPrimaryCardDataAsset::BattleCard(ACard* target1, ACard* target2)
{
    onCardBattle(target1, target2);
}

void UPrimaryCardDataAsset::ResetStats(ACard* target)
{
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

void UPrimaryCardDataAsset::onCardAttack(ACard* target1, ACard* target2)
{
}

void UPrimaryCardDataAsset::onCardBattle(ACard* target1, ACard* target2)
{
}

FPrimaryAssetId UPrimaryCardDataAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("Cards", GetFName());
}
