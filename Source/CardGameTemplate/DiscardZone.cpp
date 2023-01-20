// Fill out your copyright notice in the Description page of Project Settings.


#include "DiscardZone.h"
#include "CardGamePawn.h"
#include "Card.h"

void ADiscardZone::BeginPlay()
{
	Super::BeginPlay();

	zoneOwner->DiscardZone = this;
}

void ADiscardZone::AddToPile(ACard* card)
{
	DiscardPile.Add(card);
	card->CardRemoved();

	if (zoneOwner->CardsOnField.Contains(card))
		zoneOwner->CardsOnField.RemoveSingle(card);

	for (int i = 0; i < DiscardPile.Num(); i++)
	{
		DiscardPile[i]->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, (i * 1.0f) + 1.0));
		DiscardPile[i]->SetActorRotation({ 0.0f, 90.0f, 0.0f });
		card->location = ECardLocation::DiscardPile;
	}
}

