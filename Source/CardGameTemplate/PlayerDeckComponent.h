// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerDeckComponent.generated.h"

class UPrimaryCardDataAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARDGAMETEMPLATE_API UPlayerDeckComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerDeckComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>
	/// Adds the card asset to the deck.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void AddCardToDeck(class UPrimaryCardDataAsset* card);

	/// <summary>
	/// Removes the card asset from the deck.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void RemoveCardFromDeck(class UPrimaryCardDataAsset* card);

	/// <summary>
	/// The array of cards in the deck.
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UPrimaryCardDataAsset*> DeckArray;

	/// <summary>
	/// Tells the Menu to update the Deck UI
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	bool updateDeck;
};
