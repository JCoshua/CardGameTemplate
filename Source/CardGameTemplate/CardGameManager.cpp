// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameManager.h"
#include "CardGameTemplatePlayerController.h"
#include <Camera/CameraComponent.h>
#include "CardGameTemplatePawn.h"
#include "CardGamePawn.h"
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

	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	world->GetFirstPlayerController()->Possess(playerOne);
}


// Called every frame
void UCardGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!gameStart)
		return;

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

void UCardGameManager::InitializeGame()
{
	UWorld* world = GetWorld();
	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerTwo->AutoPossessPlayer = EAutoReceiveInput::Player1;
	InitializeDecks();

	playerOne->DrawCard(5);
	playerTwo->DrawCard(5);

	if (rand() % 2 == 0)
		currentPlayer = playerOne;
	else
		currentPlayer = playerTwo;
	world->GetFirstPlayerController()->Possess(currentPlayer);
	currentPlayer->isTurnPlayer = true;

	gameStart = true;
}

void UCardGameManager::InitializeDecks()
{
	playerOne->DeckZone->initDeck();
	playerTwo->DeckZone->initDeck();
}

