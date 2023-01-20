// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UPrimaryCardDataAsset;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARDGAMETEMPLATE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/// <summary>
	/// Adds the card to the inventory.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void AddCardToInventory(UPrimaryCardDataAsset* card, int cardCount = 1);

	/// <summary>
	/// Removes the card from the inventory.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void RemoveCardFromInventory(UPrimaryCardDataAsset* card);

	/// <summary>
	/// The array of cards in the inventory.
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UPrimaryCardDataAsset*> inventoryArray;

	/// <summary>
	/// Tells the Menu to update the Inventory UI
	/// </summary>
	UPROPERTY(BlueprintReadWrite)
	bool updateInventory;
};
