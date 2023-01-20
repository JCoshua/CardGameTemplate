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
	mesh->SetRelativeScale3D({1.0f, 1.5f, 0.01f});
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
	if (CardHealth <= 0 && location == ECardLocation::Field)
	{
		CardOwner->DiscardZone->AddToPile(this);
		CardZone->Card = nullptr;
	}
}

void ACard::CardAdded()
{
	onCardAdded();
	CardData->CardAdded(this);

	location = ECardLocation::Hand;
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

	location = ECardLocation::DiscardPile;
}

void ACard::CardPlaced()
{
	onCardPlaced();
	CardData->CardPlaced(this);

	location = ECardLocation::Field;
}

void ACard::AttackCard(ACard* target)
{
	if (!target)
		return;

	if (!target->CardZone)
		return;

	onCardAttack(target);
	CardData->AttackCard(this, target);
	BattleCard(target);
	target->BattleCard(target);

	CardHealth -= target->CalculateDamage(this);
	target->CardHealth -= CalculateDamage(target);

	IsAttacking = false;
	CardOwner->SelectedCard = nullptr;
	CardOwner->readyForTurnEnd = true;

	CardData->ResetStats(this);
	target->CardData->ResetStats(target);
}

void ACard::BattleCard(ACard* target)
{
	onCardBattle(target);
	CardData->BattleCard(this, target);
}

void ACard::SetCardStats()
{
	CardHealth = CardData->Health;
	CardAttack = CardData->Attack;
	CardDefense = CardData->Defense;
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

void ACard::onCardAttack(ACard* target)
{
}

void ACard::onCardBattle(ACard* target)
{
}

int ACard::CalculateDamage(ACard* target)
{
	int damage = CardAttack - target->CardDefense;

	if (damage <= 0)
		damage = 1;

	return damage;
}
