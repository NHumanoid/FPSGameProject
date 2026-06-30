// Fill out your copyright notice in the Description page of Project Settings.


#include "HealingItem.h"
#include "PlayerPawn.h"

AHealingItem::AHealingItem()
{
	HealAmount = 20.0f;
	ItemType = "Heling";
}

void AHealingItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if(APlayerPawn* Playercharacter = Cast<APlayerPawn>(Activator))
		{
			Playercharacter->AddHealth(HealAmount);
		}
		DestroyItem();
	}
}

