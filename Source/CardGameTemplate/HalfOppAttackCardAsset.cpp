// Fill out your copyright notice in the Description page of Project Settings.


#include "HalfOppAttackCardAsset.h"
#include "Card.h"

void UHalfOppAttackCardAsset::onCardAttack(ACard* target1, ACard* target2)
{
	target1->CardAttack = 1;
}

void UHalfOppAttackCardAsset::ResetStats(ACard* target)
{
	if (!statsChanged)
		return;

	target->CardAttack = Attack;
}

void UHalfOppAttackCardAsset::onCardBattle(ACard* target1, ACard* target2)
{
	target2->CardAttack /= 2;
}
