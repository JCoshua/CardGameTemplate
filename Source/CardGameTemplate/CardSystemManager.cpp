// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSystemManager.h"
#include "CardGameTemplatePlayerController.h"
#include <Camera/CameraComponent.h>
#include "CardGameTemplatePawn.h"
#include "CardGamePawn.h"
#include "FieldZone.h"
#include "DeckZone.h"
#include "Card.h"

ACardSystemManager::ACardSystemManager()
{
	// no pawn by default
	DefaultPawnClass = ACardGameTemplatePawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = ACardGameTemplatePlayerController::StaticClass();
}

void ACardSystemManager::StartPlay()
{
	UWorld* world = GetWorld();


	playerOne = world->SpawnActor<ACardGamePawn>();
	playerTwo = world->SpawnActor<ACardGamePawn>();
	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerTwo->AutoPossessPlayer = EAutoReceiveInput::Player1;
	world->GetFirstPlayerController()->Possess(playerOne);
	InitField();
	CreateDecks();
	InitCamera();

	playerOne->DrawCard(5);
	playerTwo->DrawCard(5);

	Super::StartPlay();
}

void ACardSystemManager::InitField()
{
	/// <summary>
	/// A 2D Map for the game field as viewed from Player 1's perspective.
	/// 
	/// Key:
	/// 0 - Inaccessable Zone
	/// 1 - Player 1's Zone
	/// 2 - Player 2's Zone
	/// </summary>
	/*gridMap =
	{
		{2,2,2,2,2},
		{2,2,2,2,2},
		{0,0,0,0,0},
		{1,1,1,1,1},
		{1,1,1,1,1}
	};*/

	TArray<TArray<int>> grid =
	{
		{1,1,1},
		{1,1,1},
		{1,1,1}
	};

	UWorld* world = GetWorld();

	ADeckZone* playerOneDeck = world->SpawnActor<ADeckZone>();
	playerOne->Deck = playerOneDeck;

	for (int x = 0; x < grid.Num(); x++)
	{
		TArray<AFieldZone*> row;

		for (int y = 0; y < grid[0].Num(); y++)
		{
			if (grid[x][y] > 0)
			{
				AFieldZone* zone = world->SpawnActor<AFieldZone>();
				row.Add(zone);
				float xPos = x * 150.0f;
				float yPos = -150.0f + (y * -150.0f);
				zone->SetActorLocation(FVector(xPos, yPos, 0));
			}
		}
		fieldMap.Add(row);
	}
		
	
	ADeckZone* playerTwoDeck = world->SpawnActor<ADeckZone>();
	playerTwoDeck->SetActorLocation(FVector((fieldMap.Num() - 1.0f) * 150.0f, -150.0f + (fieldMap[0].Num() * -150.0f), 0));
	playerTwo->Deck = playerTwoDeck;
}

void ACardSystemManager::InitCamera()
{
	playerOne->SetActorLocation(FVector(-750.0f, -50.0f + (fieldMap[0].Num() / 2.0f) * -150.0f, 700));
	playerOne->SetActorRotation(FRotator(330.0f, 0.0f, 0.0f));

	playerTwo->SetActorLocation(FVector(fieldMap.Num() * 150.0f + 500.0f, -50.0f + (fieldMap[0].Num() / 2.0f) * -150.0f, 700));
	playerTwo->SetActorRotation(FRotator(330.0f, 180.0f, 0.0f));
}

void ACardSystemManager::CreateDecks()
{
	UWorld* world = GetWorld();

	for (int i = 0; i < 10; i++)
	{
		ACard* playerOneCard = world->SpawnActor<ACard>();
		playerOne->Deck->Deck.Add(playerOneCard);

		ACard* playerTwoCard = world->SpawnActor<ACard>();
		playerTwo->Deck->Deck.Add(playerTwoCard);
	}

	playerOne->Deck->Shuffle();
	playerTwo->Deck->Shuffle();
}
