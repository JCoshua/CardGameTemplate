// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include <Components/StaticMeshComponent.h>
#include "PrimaryCardDataAsset.h"
#include "FieldZone.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	CardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	CardMesh->SetStaticMesh(Asset);
	CardMesh->SetRelativeScale3D({ 1.0f, 1.5f, 0.01f });
	CardMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CardZone->Card = nullptr;
}

void ACard::CardAdded()
{
	onCardAdded();
	CardData->CardAdded(this);

	Location = ECardLocation::Hand;
}

void ACard::CardUsed()
{
	onCardUsed();
	CardData->CardUsed(this);
}

void ACard::CardRemoved()
{
	onCardRemoved();
	CardData->CardRemoved(this);

	Location = ECardLocation::DiscardPile;
}

void ACard::CardPlaced()
{
	onCardPlaced();
	CardData->CardPlaced(this);

	Location = ECardLocation::Field;
}

void ACard::onCardAdded()
{
}

void ACard::onCardUsed()
{
}

void ACard::onCardRemoved()
{
}

void ACard::onCardPlaced()
{
}


