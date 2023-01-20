// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameManager.h"
#include "CardGameTemplatePlayerController.h"
#include <Camera/CameraComponent.h>
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

	//Possesses player 1
	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	world->GetFirstPlayerController()->Possess(playerOne);
}


// Called every frame
void UCardGameManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Do nothing if the game hasn't started
	if (!gameStart)
		return;

	UWorld* world = GetWorld();

	switch (currentPhase)
	{
	//During the Draw Phase...
	case UTurnPhases::DRAWPHASE:
		//The current player draws their card...
		currentPlayer->DrawCard(cardDrawnPerTurn);

		//Switch to the main phase.
		currentPhase = UTurnPhases::MAINPHASE;
		break;

	//During the Main Phase
	case UTurnPhases::MAINPHASE:

		//When the player is ready to end their turn...
		if (currentPlayer->readyForTurnEnd)
		{
			//Switch to the end phase...
			currentPhase = UTurnPhases::ENDPHASE;

			//Reset the variable.
			currentPlayer->readyForTurnEnd = false;
		}
		break;

	//During the End Phase
	case UTurnPhases::ENDPHASE:

		//Switch the turn player...
		currentPlayer->isTurnPlayer = false;
		if (currentPlayer == playerOne)
			currentPlayer = playerTwo;
		else
			currentPlayer = playerOne;
		currentPlayer->isTurnPlayer = true;

		//Possess the new turn player (for testing purposes)...
		world->GetFirstPlayerController()->UnPossess();
		world->GetFirstPlayerController()->Possess(currentPlayer);

		//Return to the Draw Phase.
		currentPhase = UTurnPhases::DRAWPHASE;
		break;

	default:
		break;
	}
}

void UCardGameManager::InitializeGame()
{
	//Give the players possession of their pawns...
	UWorld* world = GetWorld();
	playerOne->AutoPossessPlayer = EAutoReceiveInput::Player0;
	playerTwo->AutoPossessPlayer = EAutoReceiveInput::Player1;

	//Initialize their decks...
	InitializeDecks();

	//Each player Draws their opening hand...
	playerOne->DrawCard(5);
	playerTwo->DrawCard(5);

	//The first turn player is randomly decided...
	if (rand() % 2 == 0)
		currentPlayer = playerOne;
	else
		currentPlayer = playerTwo;
	world->GetFirstPlayerController()->Possess(currentPlayer);
	currentPlayer->isTurnPlayer = true;

	//The game starts
	gameStart = true;
}

void UCardGameManager::InitializeDecks()
{
	playerOne->DeckZone->InitializeDeck();
	playerTwo->DeckZone->InitializeDeck();
}

