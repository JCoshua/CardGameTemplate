// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldZone.h"
#include "CardGamePawn.h"
#include "Card.h"

bool AFieldZone::PlaceCard(ACard* cardToPlace)
{
	//If the zone already owns a card, return.
	if (Card)
		return false;

	// If the card does not belong to this zone owner, return.
	if (!ZoneOwner->Hand.Contains(cardToPlace))
		return false;

	// Set this zone's card to the placed card...
	Card = cardToPlace;
	// Set the location of the card...
	Card->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 1.0f));
	// Reset the scale of the card...
	Card->SetActorScale3D(Card->GetActorScale3D() * 2);
	// Set the rotation of the card...
	Card->SetActorRotation({ 0.0f, 0.0f, 0.0f });

	return true;
}
