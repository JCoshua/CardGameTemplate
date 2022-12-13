// Fill out your copyright notice in the Description page of Project Settings.


#include "FieldZone.h"

// Sets default values
AFieldZone::AFieldZone()
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
void AFieldZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFieldZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

