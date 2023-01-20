// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CardGamePawn.generated.h"

class ACard;
class APlayZone;

UCLASS()
class CARDGAMETEMPLATE_API ACardGamePawn : public APawn
{
	GENERATED_BODY()

public:
	ACardGamePawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Called to get a reference to the actual deck
	TArray<ACard*> GetDeck();

	/// <summary>
	/// Draws a card from the player's deck.
	/// </summary>
	/// <param name="drawAmount">The amount of cards to draw</param>
	void DrawCard(int drawAmount = 1);

	/// <summary>
	/// Sorts and moves the cards in their hand to the right location.
	/// </summary>
	void SortHandLocation();

	/// <summary>
	/// Traces the screen for an actor.
	/// </summary>
	/// <param name="Start">Where the line starts.</param>
	/// <param name="End">Where the line ends.</param>
	/// <param name="bDrawDebugHelpers">Whether the line should be drawn to the screen.</param>
	void TraceForActor(const FVector& Start, const FVector& End, bool bDrawDebugHelpers);

	/// <summary>
	/// Places a card on the field.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void PlaceCard(class AFieldZone* zone);

	/// <summary>
	/// Actions performed when the left mouse button is clicked.
	/// </summary>
	void OnMouseClick();

	/// <summary>
	/// Interactions performed when interacting with a card.
	/// </summary>
	/// <param name="tracedCard">The card being interacted with.</param>
	void InteractWithTracedCard(ACard* tracedCard);

	/// <summary>
	/// Interaction performed when interacting with a zone.
	/// </summary>
	/// <param name="tracedZone">The zone being interacted with.</param>
	void InteractWithTracedZone(APlayZone* tracedZone);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* Camera;

	/// <summary>
	/// The cards in the player's hand.
	/// </summary>
	TArray<ACard*> Hand;

	/// <summary>
	/// The cards on the player's field.
	/// </summary>
	TArray<ACard*> CardsOnField;

	/// <summary>
	/// The zone the player's deck is located at.
	/// </summary>
	class ADeckZone* DeckZone;

	/// <summary>
	/// The zone the player's discard pile is located at.
	/// </summary>
	class ADiscardZone* DiscardZone;

	/// <summary>
	/// The actor the player's mouse is currently hovering over.
	/// </summary>
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	AActor* CurrentTracedActor;

	/// <summary>
	/// The card the player last clicked on.
	/// </summary>
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	ACard* SelectedCard;

	/// <summary>
	/// The zone the player last clicked on.
	/// </summary>
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	APlayZone* SelectedZone;

	/// <summary>
	/// The inventory of all cards the player owns that are not in the deck.
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventoryComponent* CardInventory;

	/// <summary>
	/// The players inventory of all the cards the player will bring into the deck.
	/// </summary>
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UPlayerDeckComponent* DeckComponent;
	
	// Tells the pawn if it can play
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	bool isTurnPlayer = false;
	// Tells the Manager to end turn
	bool readyForTurnEnd = false;
};
