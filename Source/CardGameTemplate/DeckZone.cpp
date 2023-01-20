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

	//For each card asset in the owner's deck
	for (int i = 0; i < ownerDeck.Num(); i++)
	{
		//Create a new card
		ACard* newCard = world->SpawnActor<ACard>();

		//Give the card the deck's asset
		newCard->CardData = ownerDeck[i];

		//Sets the card's owner
		newCard->CardOwner = zoneOwner;

		//Set the material on the card.
		newCard->mesh->SetMaterial(0, ownerDeck[i]->material);

		//Set the new card's stats.
		newCard->SetCardStats();

		ownerDeck[i]->cardObject = newCard;

		//Add the card to the deck.
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
		Deck[j]->SetActorRotation({ 0.0f, 90.0f, 0.0f });


		if (zoneOwner->GetActorLocation().X > 0)
			Deck[j]->SetActorRotation({ 0.0f, 270.0f, 0.0f });
		j++;
	}
}

void ADeckZone::BeginPlay()
{
	Super::BeginPlay();

	zoneOwner->DeckZone = this;
}
