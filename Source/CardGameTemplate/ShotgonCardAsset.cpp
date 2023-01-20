// Fill out your copyright notice in the Description page of Project Settings.


#include "ShotgonCardAsset.h"
#include "Card.h"
#include "CardGamePawn.h"

void UShotgonCardAsset::onCardAttack(ACard* target1, ACard* target2)
{
	TArray<ACard*> opposingCards = target2->CardOwner->CardsOnField;

	for (int i = 0; i < opposingCards.Num(); i++)
	{
		if (opposingCards[i] != target2)
		{
			opposingCards[i]->CardHealth -= damageAmount;
		}
	}
}