// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayZone.h"
#include "FieldZone.generated.h"

class ACard;
UCLASS()
class CARDGAMETEMPLATE_API AFieldZone : public APlayZone
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// Places the card on this zone.
	/// </summary>
	/// <param name="cardToPlace">The card that will be placed.</param>
	bool PlaceCard(ACard* cardToPlace);

	/// <summary>
	/// The card on this zone.
	/// </summary>
	UPROPERTY(EditAnywhere)
	ACard* Card;
};
