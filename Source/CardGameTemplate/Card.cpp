// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include <Components/StaticMeshComponent.h>
#include "PrimaryCardDataAsset.h"
#include "CardGamePawn.h"
#include "DiscardZone.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetStaticMesh(Asset);
	mesh->SetRelativeScale3D({ 1.5f, 1.0f, 0.01f });
	mesh->SetupAttachment(RootComponent);
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
	if (cardData->Health <= 0)
		cardOwner->DiscardZone->AddToPile(this);
}

void ACard::CardAdded()
{
	onCardAdded();

	location = ECardLocation::Hand;
}

void ACard::CardUsed()
{
	onCardUsed();
}

void ACard::CardRemoved()
{
	onCardRemoved();

	location = ECardLocation::DiscardPile;
}

void ACard::CardPlaced()
{
	onCardPlaced();

	location = ECardLocation::Field;
}

void ACard::CardAttack(ACard* target)
{
	if (!target)
		return;

	cardData->BattleOpponent(target->cardData);
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

void ACard::onCardAttack()
{
}


