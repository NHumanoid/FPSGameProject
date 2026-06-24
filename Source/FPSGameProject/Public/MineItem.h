
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
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionDelay;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionRadius;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="MineItem")
	float ExplosionDamage;
	virtual void ActivateItem(AActor* Activator) override;
};
