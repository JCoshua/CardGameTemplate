// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayZone.h"
#include "DiscardZone.generated.h"

class ACard;

UCLASS()
class CARDGAMETEMPLATE_API ADiscardZone : public APlayZone
{
	GENERATED_BODY()

public:
	void AddToPile(ACard* card);
	
	UPROPERTY(EditAnywhere)
	TArray<ACard*> DiscardPile;
};
