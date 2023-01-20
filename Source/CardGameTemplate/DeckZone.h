// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayZone.h"
#include "DeckZone.generated.h"

/**
 * 
 */
UCLASS()
class CARDGAMETEMPLATE_API ADeckZone : public APlayZone
{
	GENERATED_BODY()
	
public:
	/// <summary>
	/// Initializes the owner's deck.
	/// </summary>
	void InitializeDeck();

	/// <summary>
	/// Shuffles the deck.
	/// </summary>
	void Shuffle();

	/// <summary>
	/// The array of cards located in the deck.
	/// </summary>
	UPROPERTY(EditAnywhere)
	TArray<class ACard*> Deck;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
