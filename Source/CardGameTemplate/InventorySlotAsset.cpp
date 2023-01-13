// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotAsset.h"

FPrimaryAssetId UInventorySlotAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("InventorySlots", GetFName());
}
