// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGamePawn.h"
#include "DeckZone.h"
#include "Card.h"
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>


ACardGamePawn::ACardGamePawn()
{
	//Create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACardGamePawn::BeginPlay()
{
	Super::BeginPlay();
	
	DrawCard();
}

// Called every frame
void ACardGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACardGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<ACard*> ACardGamePawn::GetDeck()
{
	return Deck->Deck;
}

void ACardGamePawn::DrawCard(int drawAmount)
{
	for (int i = 0; i < drawAmount; i++)
	{
		ACard* drawnCard = GetDeck()[0];

		Hand.Add(drawnCard);
		Deck->Deck.RemoveSingle(drawnCard);

		SortHandLocation();
	}
}

void ACardGamePawn::SortHandLocation()
{
	int handSize = Hand.Num();
	for (int i = 0; i < handSize; i++)
	{
		Hand[i]->SetActorScale3D({0.75f, 0.5f, 0.005f});
		Hand[i]->SetActorRotation({ 80.0f, 0.0f, 0.0f});
		
		float cardYLocation = (-75.0f + (handSize * 5)) + ((55.0f * handSize) / 2);
		cardYLocation -= (55.0f - (handSize * 0.25f)) * i;

		FVector forward = Camera->GetForwardVector() * FVector(200.0f, 0.0f, 450.0f);
		forward.Y = cardYLocation;
		Hand[i]->SetActorLocation(Camera->GetComponentLocation() + forward);
	}
}

