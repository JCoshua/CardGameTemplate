// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGamePawn.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "CardGameManager.h"
#include "DeckZone.h"
#include "FieldZone.h"
#include "Card.h"
#include <Camera/CameraComponent.h>
#include "DrawDebugHelpers.h"

ACardGamePawn::ACardGamePawn()
{
	//Create the camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACardGamePawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACardGamePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
		{
			if (UCameraComponent* OurCamera = PC->GetViewTarget()->FindComponentByClass<UCameraComponent>())
			{
				FVector Start = OurCamera->GetComponentLocation();
				FVector End = Start + (OurCamera->GetComponentRotation().Vector() * 8000.0f);
				TraceForActor(Start, End, true);
			}
		}
		else
		{
			FVector Start, Dir, End;
			PC->DeprojectMousePositionToWorld(Start, Dir);
			End = Start + (Dir * 8000.0f);
			TraceForActor(Start, End, false);
		}
	}

	if (SelectedCard || Hand.Contains(CurrentTracedActor))
	{
		for (int i = 0; i < Hand.Num(); i++)
		{
			if (Hand[i] != CurrentTracedActor && Hand[i] != SelectedCard)
			{
				Hand[i]->SetActorLocation(FVector(Hand[i]->GetActorLocation().X, Hand[i]->GetActorLocation().Y, 450.0f));
			}
			else
				Hand[i]->SetActorLocation(FVector(Hand[i]->GetActorLocation().X, Hand[i]->GetActorLocation().Y, 500.0f));
		}
	}
	else
		for (int i = 0; i < Hand.Num(); i++)
			Hand[i]->SetActorLocation(FVector(Hand[i]->GetActorLocation().X, Hand[i]->GetActorLocation().Y, 450.0f));
}

// Called to bind functionality to input
void ACardGamePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("TriggerClick", EInputEvent::IE_Pressed, this, &ACardGamePawn::OnMouseClick);
}

TArray<ACard*> ACardGamePawn::GetDeck()
{
	return Deck->Deck;
}

void ACardGamePawn::DrawCard(int drawAmount)
{
	if (GetDeck().Num() <= 0)
		return;

	for (int i = 0; i < drawAmount; i++)
	{
		ACard* drawnCard = GetDeck()[0];

		Hand.Add(drawnCard);
		Deck->Deck.RemoveSingle(drawnCard);

		SortHandLocation();
	}
}

void ACardGamePawn::SortHandLocation()
{
	int handSize = Hand.Num();
	for (int i = 0; i < handSize; i++)
	{
		Hand[i]->SetActorScale3D({0.75f, 0.5f, 0.005f});
		Hand[i]->SetActorRotation({ 90.0f, 0.0f, 0.0f}	);
		
		float cardYLocation = (-75.0f + (handSize * 5)) + ((55.0f * handSize) / 2);
		cardYLocation -= (55.0f - (handSize * 0.25f)) * i;

		FVector forward = Camera->GetForwardVector() * FVector(200.0f, 0.0f, 450.0f);
		forward.Y = cardYLocation;
		Hand[i]->SetActorLocation(Camera->GetComponentLocation() + forward);
	}
}

void ACardGamePawn::TraceForActor(const FVector & Start, const FVector & End, bool bDrawDebugHelpers)
{
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility);
	if (bDrawDebugHelpers)
	{
		DrawDebugLine(GetWorld(), Start, HitResult.Location, FColor::Red);
		DrawDebugSolidBox(GetWorld(), HitResult.Location, FVector(20.0f), FColor::Red);
	}
	if (HitResult.Actor.IsValid())
	{
		CurrentTracedActor = HitResult.Actor.Get();
	}
	else
		CurrentTracedActor = nullptr;
}

void ACardGamePawn::PlaceCard(AFieldZone* zone)
{
	if (!zone)
		return;

	if (zone->PlaceCard(SelectedCard))
	{
		Hand.RemoveSingle(SelectedCard);
		SelectedCard = nullptr;

		SortHandLocation();
		readyForTurnEnd = true;
	}
}

void ACardGamePawn::OnMouseClick()
{
	if (!isTurnPlayer)
		return;

	if (SelectedCard)
	{
		AFieldZone* tracedZone = Cast<AFieldZone>(CurrentTracedActor);

		if (tracedZone)
		{
			PlaceCard(tracedZone);
			return;
		}
	}

	ACard* tracedCard = Cast<ACard>(CurrentTracedActor);

	if (tracedCard && Hand.Contains(tracedCard))
		SelectedCard = tracedCard;
}
