// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CardGamePawn.generated.h"

class ACard;

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

	void PlaceCard(class AFieldZone* zone);

	void OnMouseClick();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere)
	TArray<ACard*> Hand;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	AActor* CurrentTracedActor;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite)
	ACard* SelectedCard;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* Camera;
	
	UPROPERTY(EditAnywhere)
	class ADeckZone* Deck;
};
