// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscardZone.h"
#include "Card.h"

void ADiscardZone::AddToPile(ACard* card)
{
	DiscardPile.Add(card);

	for (int i = 0; i < DiscardPile.Num(); i++)
	{
		DiscardPile[i]->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, (i * 1.0f) + 1.0));
	}
}