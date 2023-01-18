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
	void initDeck();
	void Shuffle();

	UPROPERTY(EditAnywhere)
	TArray<class ACard*> Deck;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
