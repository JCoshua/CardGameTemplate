// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldZone.h"
#include "CardGamePawn.h"
#include "Card.h"

bool AFieldZone::PlaceCard(ACard* cardToPlace)
{
	if (Card)
		return false;

	if (!zoneOwner->Hand.Contains(cardToPlace))
		return false;

	Card = cardToPlace;
	Card->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 1.0f));
	Card->SetActorScale3D(Card->GetActorScale3D() * 2);
	Card->SetActorRotation({ 0.0f, 90.0f, 0.0f });
	Card->CardZone = this;

	return true;
}
