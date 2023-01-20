// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackReducedWithHPCardAsset.h"
#include "Card.h"

void UAttackReducedWithHPCardAsset::onCardBattle(ACard* target1, ACard* target2)
{
	target1->CardAttack = Attack - (Health - target1->CardHealth);
}