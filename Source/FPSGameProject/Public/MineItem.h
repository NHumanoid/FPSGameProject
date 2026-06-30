
#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "MineItem.generated.h"

UCLASS()
class FPSGAMEPROJECT_API AMineItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	AMineItem();
	
	USphereComponent* ExplosionCollition;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionDelay;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionDamage; //폭발하면 체력을 깍는 변수
	
	FTimerHandle ExplosionTimerHandle; //5초 지나면 지뢰가 터지는 타이머 핸들러 선언을 해주면 됨
	
	virtual void ActivateItem(AActor* Activator) override;
	
	void Explode();
};
