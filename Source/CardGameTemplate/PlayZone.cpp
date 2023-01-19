// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayZone.h"

// Sets default values
APlayZone::APlayZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("Material'/Game/Geometry/Meshes/CubeMaterial.CubeMaterial'"));

	UStaticMesh* Asset = MeshAsset.Object;
	UMaterial* Material = MaterialAsset.Object;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	mesh->SetStaticMesh(Asset);
	mesh->SetMaterial(0, Material);
	mesh->SetRelativeScale3D({ 1.5f, 1.5f, 0.01f });
	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayZone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

