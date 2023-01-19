// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include <Components/StaticMeshComponent.h>
#include "PrimaryCardDataAsset.h"
#include "CardGamePawn.h"
#include "DiscardZone.h"
#include "FieldZone.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	UStaticMesh* Asset = MeshAsset.Object;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetStaticMesh(Asset);
	mesh->SetRelativeScale3D({ 1.0f, 1.5f, 0.01f });
	mesh->AddWorldRotation({ 90.0f,90.0f,00.0f });
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
	if (CardData->Health <= 0 && location == ECardLocation::Field)
	{
		cardOwner->DiscardZone->AddToPile(this);
		CardZone->Card = nullptr;
	}
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

	CardStats->BattleOpponent(target->CardStats);
	IsAttacking = false;
}

void ACard::SetCardStats()
{
	CardStats = &FCardStats(CardData->Health, CardData->Attack, CardData->Defense);
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

FCardStats::FCardStats(int Health, int Attack, int Defense)
{
	cardHealth = Health;
	cardAttack = Attack;
	cardDefense = Defense;
}

void FCardStats::BattleOpponent(FCardStats* target)
{
	int damage = (target->cardAttack - cardDefense);

	if (damage < 0)
		damage = 0;
	cardHealth -= damage;

	damage = (cardAttack - target->cardDefense);

	if (damage < 0)
		damage = 0;
	target->cardHealth -= damage;
}
