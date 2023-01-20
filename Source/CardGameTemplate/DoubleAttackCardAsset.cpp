// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleAttackCardAsset.h"
#include "Card.h"

void UDoubleAttackCardAsset::onCardAttack(ACard* target1, ACard* target2)
{
	target1->CardAttack *= 2;
	statsChanged = true;
}

void UDoubleAttackCardAsset::ResetStats(ACard* target)
{
	if (!statsChanged)
		return;

	target->CardAttack /= 2;
	statsChanged = false;
}
