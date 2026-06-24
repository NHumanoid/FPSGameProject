// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoinItem.h"
#include "SmailCoinItem.generated.h"

UCLASS()
class FPSGAMEPROJECT_API ASmailCoinItem : public ACoinItem
{
	GENERATED_BODY()
	
public:
	
	ASmailCoinItem();
	
	virtual void ActivateItem(AActor* Activator) override;
};
