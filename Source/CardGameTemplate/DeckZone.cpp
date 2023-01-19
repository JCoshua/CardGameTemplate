// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckZone.h"
#include "CardGamePawn.h"
#include "PlayerDeckComponent.h"
#include "PrimaryCardDataAsset.h"
#include "Card.h"

void ADeckZone::initDeck()
{
	if (!zoneOwner)
		return;

	UWorld* world = GetWorld();
	TArray<UPrimaryCardDataAsset*> ownerDeck = zoneOwner->DeckComponent->DeckArray;

	for (int i = 0; i < ownerDeck.Num(); i++)
	{
		ACard* newCard = world->SpawnActor<ACard>();
		newCard->cardData = ownerDeck[i];
		newCard->cardOwner = zoneOwner;
		Deck.Add(newCard);
	}

	Shuffle();
}

void ADeckZone::Shuffle()
{
	if (Deck.Num() <= 0)
		return;

	for (int i = 0; i < Deck.Num(); i++)
	{
		int index = i;
		while (i == index && Deck.Num() > 1)
			index = rand() % Deck.Num();

		Deck.Swap(i, index);
	}

	int j = 0;
	for (int i = Deck.Num() - 1; i >= 0; i--)
	{
		Deck[j]->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, (i * 1.0f) + 1.0));
		j++;
	}
}

void ADeckZone::BeginPlay()
{
	Super::BeginPlay();

	zoneOwner->DeckZone = this;
}
