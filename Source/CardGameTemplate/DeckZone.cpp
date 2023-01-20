// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckZone.h"
#include "CardGamePawn.h"
#include "PlayerDeckComponent.h"
#include "PrimaryCardDataAsset.h"
#include "Card.h"

void ADeckZone::InitializeDeck()
{
	if (!ZoneOwner)
		return;

	UWorld* world = GetWorld();

	//Gets the owner's deck contents.
	TArray<UPrimaryCardDataAsset*> ownerDeck = ZoneOwner->DeckComponent->DeckArray;

	//For each card asset in the owner's deck...
	for (int i = 0; i < ownerDeck.Num(); i++)
	{
		//Create a new card...
		ACard* newCard = world->SpawnActor<ACard>();

		//Give the card reference to the asset...
		newCard->CardData = ownerDeck[i];

		//Sets the card's owner...
		newCard->CardOwner = ZoneOwner;

		//Adds the card to the deck.
		Deck.Add(newCard);
	}

	//Shuffles the deck afterwords.
	Shuffle();
}

void ADeckZone::Shuffle()
{
	//If their is no cards in the deck, don't shuffle.
	if (Deck.Num() <= 0)
		return;

	//For each card in the deck...
	for (int i = 0; i < Deck.Num(); i++)
	{
		int index = i;

		//While the card indexes are the same, and the deck contains more than one card, get a new index
		while (i == index && Deck.Num() > 1)
			index = rand() % Deck.Num();

		//When the indexes are different, swap the cards at those indexes.
		Deck.Swap(i, index);
	}


	int j = 0;
	for (int i = Deck.Num() - 1; i >= 0; i--)
	{
		//Set the cards to be placed in order in the deck.
		Deck[j]->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, (i * 1.0f) + 1.0));
		Deck[j]->SetActorRotation({ 0.0f, 90.0f, 0.0f });
		j++;
	}
}

void ADeckZone::BeginPlay()
{
	Super::BeginPlay();

	ZoneOwner->DeckZone = this;
}
