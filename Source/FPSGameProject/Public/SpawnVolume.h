#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class FPSGAMEPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
protected:
	
	virtual void BeginPlay() override;
	
public:	

	ASpawnVolume();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Spawning")
	USceneComponent* Scene; //씬 컴포먼트 추가
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Spawning")
	UBoxComponent* SpawningBox; //박스 컴포넌트 추가
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Spawning")
	UDataTable* ItemDataTable;
	
	UFUNCTION(BlueprintCallable, Category ="Spawning")
	void SpawnRandomItem();
	
	FItemSpawnRow* GetRandomItem() const;
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnItem(TSubclassOf<AActor> ItemClass); //하위 클레스는 엑터 클라스로 안전하게 지정을 해줌
	
	FVector GetRandomPointInVolume() const;
};
