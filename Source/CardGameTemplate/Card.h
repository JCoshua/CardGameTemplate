// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

UENUM(BlueprintType)
enum class ECardLocation : uint8
{
	Deck,
	Hand,
	Field,
	DiscardPile
};


UCLASS()
class CARDGAMETEMPLATE_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
	/// <summary>
	/// Actions all cards perform when they are added to the hand.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardAdded();
	/// <summary>
	/// Actions all cards performed when they are 'used'.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardUsed();
	/// <summary>
	/// Actions all cards perform when they are removed from the field/discarded.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardRemoved();
	/// <summary>
	/// Actions all cards perform when they are placed on the field.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardPlaced();
	/// <summary>
	/// Actions all cards perform when they attack a target.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardAttack(ACard* target);

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* mesh;

	UPROPERTY()
	class ACardGamePawn* cardOwner;

	UPROPERTY(BlueprintReadOnly)
	ECardLocation location;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UPrimaryCardDataAsset* cardData;
private:
	/// <summary>
	/// Actions performed when this card is added to the hand.
	/// </summary>
	virtual void onCardAdded();
	/// <summary>
	/// Actions performed when this card is 'used'.
	/// </summary>
	virtual void onCardUsed();
	/// <summary>
	/// Actions performed when this card is removed from the field/discarded.
	/// </summary>
	virtual void onCardRemoved();
	/// <summary>
	/// Actions performed when this card is placed on the field.
	/// </summary>
	virtual void onCardPlaced();
	/// <summary>
	/// Actions performed when this card attacks a target.
	/// </summary>
	virtual void onCardAttack();
};
