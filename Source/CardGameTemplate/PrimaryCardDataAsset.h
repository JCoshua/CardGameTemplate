// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PrimaryCardDataAsset.generated.h"

class ACard;

UCLASS()
class CARDGAMETEMPLATE_API UPrimaryCardDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	/// <summary>
	/// Actions all cards perform when they are added to the hand.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardAdded(ACard* target);
	/// <summary>
	/// Actions all cards performed when they are 'used'.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardUsed(ACard* target);
	/// <summary>
	/// Actions all cards perform when they are removed from the field/discarded.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardRemoved(ACard* target);
	/// <summary>
	/// Actions all cards perform when they are placed on the field.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void CardPlaced(ACard* target);
	/// <summary>
	/// Actions all cards perform when they attack a target.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void AttackCard(ACard* target1, ACard* target2);
	/// <summary>
	/// Actions all cards perform when they battle an opposing card.
	/// </summary>
	UFUNCTION(BlueprintCallable)
	void BattleCard(ACard* target1, ACard* target2);

	/// <summary>
	/// Resets the changed stats of a card (if neccasary).
	/// </summary>
	virtual void ResetStats(ACard* target);
private:
	/// <summary>
	/// Actions performed when this card is added to the hand.
	/// </summary>
	virtual void onCardAdded(ACard* target);
	/// <summary>
	/// Actions performed when this card is 'used'.
	/// </summary>
	virtual void onCardUsed(ACard* target);
	/// <summary>
	/// Actions performed when this card is removed from the field/discarded.
	/// </summary>
	virtual void onCardRemoved(ACard* target);
	/// <summary>
	/// Actions performed when this card is placed on the field.
	/// </summary>
	virtual void onCardPlaced(ACard* target);
	/// <summary>
	/// Actions performed when this card attacks a target.
	/// </summary>
	virtual void onCardAttack(ACard* target1, ACard* target2);
	/// <summary>
	/// Actions performed when this card battles an opposing card.
	/// </summary>
	virtual void onCardBattle(ACard* target1, ACard* target2);
public:
	UPROPERTY(BlueprintReadOnly, Category = "Card Data Info")
	class ACard* cardObject;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visuals")
	UTexture2D* texture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Visuals")
	UMaterial* material;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	FName cardName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	FString cardDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	bool cardUsable = true;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Health = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Attack = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Card Data Info")
	int Defense = 0;

	FPrimaryAssetId GetPrimaryAssetId() const override;
};
