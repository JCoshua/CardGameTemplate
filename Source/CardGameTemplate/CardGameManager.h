// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "CardGameManager.generated.h"

class ACardGamePawn;
class AFieldZone;


UENUM()
enum class UTurnPhases
{
	DRAWPHASE,
	MAINPHASE,
	ENDPHASE

};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARDGAMETEMPLATE_API UCardGameManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCardGameManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitField();
	void InitCamera();
	void CreateDecks();

	ACardGamePawn* playerOne;
	ACardGamePawn* playerTwo;
	TArray<TArray<AFieldZone*>> fieldMap;
	UTurnPhases currentPhase;

	ACardGamePawn* currentPlayer;

	/// <summary>
	/// The number of cards drawn during the designated draw phase.
	/// </summary>
	UPROPERTY(EditAnywhere)
	int cardDrawnPerTurn = 1;
};
