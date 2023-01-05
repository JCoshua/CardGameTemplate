// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameManager.h"
#include "CardGameTemplatePlayerController.h"
#include <Camera/CameraComponent.h>
#include "CardGameTemplatePawn.h"
#include "CardGamePawn.h"
#include "FieldZone.h"
#include "DeckZone.h"
#include "Card.h"


// Sets default values for this component's properties
UCardGameManager::UCardGameManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCardGameManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	UWorld* world = GetWorld();


	playerOne = world->SpawnActor<ACardGamePawn>();
	playerTwo = world->SpawnActor<ACardGamePawn>();
	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerTwo->AutoPossessPlayer = EAutoReceiveInput::Player1;
	InitField();
	CreateDecks();
	InitCamera();

	playerOne->DrawCard(5);
	playerTwo->DrawCard(5);

	if (rand() % 2 == 0)
		currentPlayer = playerOne;
	else
		currentPlayer = playerTwo;
	world->GetFirstPlayerController()->Possess(currentPlayer);
	currentPlayer->isTurnPlayer = true;
}


// Called every frame
void UCardGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	UWorld* world = GetWorld();

	// ...
	switch (currentPhase)
	{
	case UTurnPhases::DRAWPHASE:
		currentPlayer->DrawCard(cardDrawnPerTurn);
		currentPhase = UTurnPhases::MAINPHASE;
		break;
	case UTurnPhases::MAINPHASE:
		if (currentPlayer->readyForTurnEnd)
		{
			currentPhase = UTurnPhases::ENDPHASE;
			currentPlayer->readyForTurnEnd = false;
		}
		break;
	case UTurnPhases::ENDPHASE:
		currentPlayer->isTurnPlayer = false;
		if (currentPlayer == playerOne)
			currentPlayer = playerTwo;
		else
			currentPlayer = playerOne;
		currentPlayer->isTurnPlayer = true;

		world->GetFirstPlayerController()->UnPossess();
		world->GetFirstPlayerController()->Possess(currentPlayer);
		currentPhase = UTurnPhases::DRAWPHASE;
		break;
	default:
		break;
	}
}

void UCardGameManager::InitField()
{
	/// <summary>
	/// A 2D Map for the game field as viewed from Player 2's perspective.
	/// 
	/// Key:
	/// 0 - Inaccessable Zone
	/// 1 - Player 1's Zone
	/// 2 - Player 2's Zone
	/// </summary>
	TArray<TArray<int>> grid =
	{
		{1,1,1,1,1},
		{1,1,1,1,1},
		{0,0,0,0,0},
		{2,2,2,2,2},
		{2,2,2,2,2}
	};

	UWorld* world = GetWorld();

	ADeckZone* playerOneDeck = world->SpawnActor<ADeckZone>();
	playerOne->Deck = playerOneDeck;

	for (int x = 0; x < grid.Num(); x++)
	{
		TArray<AFieldZone*> row;

		for (int y = 0; y < grid[0].Num(); y++)
		{
			if (grid[x][y] == 1)
			{
				AFieldZone* zone = world->SpawnActor<AFieldZone>();
				zone->zoneOwner = playerOne;
				float xPos = x * 150.0f;
				float yPos = -150.0f + (y * -150.0f);
				zone->SetActorLocation(FVector(xPos, yPos, 0));
				row.Add(zone);
			}

			else if (grid[x][y] == 2)
			{
				AFieldZone* zone = world->SpawnActor<AFieldZone>();
				zone->zoneOwner = playerTwo;
				float xPos = x * 150.0f;
				float yPos = -150.0f + (y * -150.0f);
				zone->SetActorLocation(FVector(xPos, yPos, 0));
				row.Add(zone);
			}
		}
		fieldMap.Add(row);
	}


	ADeckZone* playerTwoDeck = world->SpawnActor<ADeckZone>();
	playerTwoDeck->SetActorLocation(FVector((fieldMap.Num() - 1.0f) * 150.0f, -150.0f + (fieldMap[0].Num() * -150.0f), 0));
	playerTwo->Deck = playerTwoDeck;
}

void UCardGameManager::InitCamera()
{
	playerOne->SetActorLocation(FVector(-750.0f, -50.0f + (fieldMap[0].Num() / 2.0f) * -150.0f, 700));
	playerOne->SetActorRotation(FRotator(330.0f, 0.0f, 0.0f));

	playerTwo->SetActorLocation(FVector(fieldMap.Num() * 150.0f + 500.0f, -50.0f + (fieldMap[0].Num() / 2.0f) * -150.0f, 700));
	playerTwo->SetActorRotation(FRotator(330.0f, 180.0f, 0.0f));
}

void UCardGameManager::CreateDecks()
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

