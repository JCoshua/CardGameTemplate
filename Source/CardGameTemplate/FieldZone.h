// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayZone.h"
#include "FieldZone.generated.h"

class ACard;
UCLASS()
class CARDGAMETEMPLATE_API AFieldZone : public APlayZone
{
	GENERATED_BODY()
	
public:
	bool PlaceCard(ACard* cardToPlace);

	UPROPERTY(EditAnywhere)
	ACard* Card;
};
