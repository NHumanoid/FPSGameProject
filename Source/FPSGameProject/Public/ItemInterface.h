// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPSGAMEPROJECT_API IItemInterface
{
	GENERATED_BODY()
	
public:
	
	virtual void OnItemOverlap(AActor* OverlapActor) = 0; //아이템을 먹으면(충돌) 실행하는 순수가상함수
	virtual void OnItemEndOverlap(AActor* OverlapActor) = 0; //아이템을 벋어 났을 떄에 실행하는 순수가상함수
	virtual void ActivateItem(AActor* Activator) = 0;
	virtual FName GetItemType() const = 0;
	//지뢰 - 장애물, 코인 - 아이템,힐링
};
