// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayZone.generated.h"

UCLASS()
class CARDGAMETEMPLATE_API APlayZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/// <summary>
	/// The player that owns this zone.
	/// </summary>
	UPROPERTY(EditAnywhere)
	class ACardGamePawn* ZoneOwner;

	/// <summary>
	/// The visible mesh of this zone.
	/// </summary>
	class UStaticMeshComponent* mesh;
};
