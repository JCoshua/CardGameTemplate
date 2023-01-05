// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FieldZone.generated.h"

class ACard;

UCLASS()
class CARDGAMETEMPLATE_API AFieldZone : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFieldZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool PlaceCard(ACard* cardToPlace);

	UPROPERTY(EditAnywhere)
	ACard* Card;

	UPROPERTY(EditAnywhere)
	class ACardGamePawn* zoneOwner;
	class UStaticMeshComponent* mesh;
};
