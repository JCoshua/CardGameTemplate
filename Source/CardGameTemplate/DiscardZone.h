// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayZone.h"
#include "DiscardZone.generated.h"

class ACard;

UCLASS()
class CARDGAMETEMPLATE_API ADiscardZone : public APlayZone
{
	GENERATED_BODY()

public:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// <summary>
	/// Adds the card to the discard pile.
	/// </summary>
	void AddToPile(ACard* card);

	/// <summary>
	/// The Array of discarded cards.
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<ACard*> DiscardPile;
};
