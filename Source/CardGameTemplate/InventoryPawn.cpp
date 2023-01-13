// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryPawn.h"

// Sets default values
AInventoryPawn::AInventoryPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventoryPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventoryPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AInventoryPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

