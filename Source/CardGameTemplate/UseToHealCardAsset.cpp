// Fill out your copyright notice in the Description page of Project Settings.


#include "UseToHealCardAsset.h"
#include "Card.h"
#include "CardGamePawn.h"
#include "DiscardZone.h"

void UUseToHealCardAsset::onCardUsed(ACard* target)
{
	TArray<ACard*> allyCard = target->CardOwner->CardsOnField;

	for (int i = 0; i < allyCard.Num(); i++)
	{
		allyCard[i]->CardHealth += 3;

		if (allyCard[i]->CardData->Health < allyCard[i]->CardHealth)
			allyCard[i]->CardHealth = allyCard[i]->CardData->Health;
	}

	target->CardOwner->DiscardZone->AddToPile(target);
}

void UUseToHealCardAsset::onCardPlaced(ACard* target)
{
	cardUsable = true;
}

void UUseToHealCardAsset::onCardRemoved(ACard* target)
{
	cardUsable = false;
}
