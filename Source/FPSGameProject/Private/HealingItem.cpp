// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Heling";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	Destroy();
}

