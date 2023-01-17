// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerDeckComponent.h"

// Sets default values for this component's properties
UPlayerDeckComponent::UPlayerDeckComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerDeckComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UPlayerDeckComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerDeckComponent::AddCardToDeck(UPrimaryCardDataAsset* card)
{
	DeckArray.Add(card);
}

void UPlayerDeckComponent::RemoveCardFromDeck(UPrimaryCardDataAsset* card)
{
	DeckArray.RemoveSingle(card);
}

