// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemInterface.h"
#include "BaseItem.generated.h"

class USphereComponent;

UCLASS()
class FPSGAMEPROJECT_API ABaseItem : public AActor, public IItemInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();

protected:
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverLappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) override; //아이템을 먹으면(충돌) 실행하는 순수가상함수
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverLappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override; //아이템을 벋어 났을 떄에 실행하는 순수가상함수
	virtual void ActivateItem(AActor* Activator) override;
	virtual FName GetItemType() const override;
	
	virtual void DestroyItem(); //아이템을 먹으면 사리지게 하는 함수
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Component")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Component")
	USphereComponent* Collision;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Item|Component")
	UStaticMeshComponent* StaticMesh;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Item")
	FName ItemType;
};
