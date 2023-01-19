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

	void DrawCard(int drawAmount = 1);

	void SortHandLocation();

	void TraceForActor(const FVector& Start, const FVector& End, bool bDrawDebugHelpers);

	UFUNCTION(BlueprintCallable)
	void PlaceCard(class AFieldZone* zone);

	void OnMouseClick();

	void InteractWithTracedCard(ACard* tracedCard);
	void InteractWithTracedZone(APlayZone* tracedZone);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* Camera;

	TArray<ACard*> Hand;
	class ADeckZone* DeckZone;
	class ADiscardZone* DiscardZone;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	AActor* CurrentTracedActor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	ACard* SelectedCard;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	APlayZone* SelectedZone;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UInventoryComponent* CardInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UPlayerDeckComponent* DeckComponent;
	
	// Tells the pawn if it can play
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	bool isTurnPlayer = false;
	// Tells the Manager to end turn
	bool readyForTurnEnd = false;
};
