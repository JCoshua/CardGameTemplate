// Fill out your copyright notice in the Description page of Project Settings.


#include "PrimaryCardDataAsset.h"

FPrimaryAssetId UPrimaryCardDataAsset::GetPrimaryAssetId() const
{
    return FPrimaryAssetId("Cards", GetFName());
}
