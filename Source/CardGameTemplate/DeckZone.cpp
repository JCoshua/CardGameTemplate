// Fill out your copyright notice in the Description page of Project Settings.


#include "DeckZone.h"
#include "Card.h"
#include <Components/StaticMeshComponent.h>

// Sets default values
ADeckZone::ADeckZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetStaticMesh(Asset);
	mesh->SetRelativeScale3D({ 1.5f, 1.5f, 0.01f });
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ADeckZone::BeginPlay()
{
	Super::BeginPlay();

	Shuffle();
}

// Called every frame
void ADeckZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADeckZone::Shuffle()
{
	if (Deck.Num() <= 0)
		return;

	for (int i = 0; i < Deck.Num(); i++)
	{
		int index = i;
		while (i == index)
			index = rand() % Deck.Num();

		Deck.Swap(i, index);
	}

	int j = 0;
	for (int i = Deck.Num() - 1; i >= 0; i--)
	{
		Deck[j]->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, (i * 1.0f) + 1.0));
		j++;
	}
}

