// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGamePawn.h"
#include "DeckZone.h"

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
		Hand.Add(GetDeck()[0]);
		GetDeck().RemoveSingle(GetDeck()[0]);
	}
}

