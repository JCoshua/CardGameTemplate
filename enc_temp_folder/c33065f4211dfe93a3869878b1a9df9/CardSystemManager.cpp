// Fill out your copyright notice in the Description page of Project Settings.


#include "CardSystemManager.h"
#include "FieldZone.h"
#include "DeckZone.h"

ACardSystemManager::ACardSystemManager()
{

}

void ACardSystemManager::StartPlay()
{
	/// <summary>
	/// A 2D Map for the game field.
	/// 
	/// Key:
	/// 0 - Inaccessable Zone
	/// 1 - Player 1's Zone
	/// 2 - Player 2's Zone
	/// </summary>
	TArray<TArray<int>> gridMap =
	{
		{2,2,2,2,2},
		{2,2,2,2,2},
		{0,0,0,0,0},
		{1,1,1,1,1},
		{1,1,1,1,1}
	};

	UWorld* world = GetWorld();
	for(int y = 0; y < 5;y++)
		for (int x = 0; x < 5; x++)
		{
			if (gridMap[y][x] > 0)
			{
				AFieldZone* zone = world->SpawnActor<AFieldZone>();
				float xPos = x * 150.0f;
				float yPos = 150.0f + (y * -150.0f);
				zone->SetActorLocation(FVector(xPos, yPos, 0));
			}
			
		}

	Super::StartPlay();
}
