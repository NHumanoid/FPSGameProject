
#include "SpawnVolume.h"
#include "Components/BoxComponent.h" // 상자 컴포먼트를 가져오는 헤더파일

// Sets default values
ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);
	
	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);
	
	SpawningBox->SetBoxExtent(FVector(300.0f,300.0f,100.0f));
	
	ItemDataTable = nullptr;
}

void ASpawnVolume::SpawnRandomItem()
{
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		if (UClass* ActualClass = SelectedRow->ItemClass.Get())
		{
			SpawnItem(ActualClass);
		}
	}
}

FItemSpawnRow* ASpawnVolume::GetRandomItem() const
{
	if (!ItemDataTable)return nullptr;
	
	TArray<FItemSpawnRow*> AllRows;
	static const FString ContentString(TEXT("ItemSpawnContant"));
	ItemDataTable->GetAllRows(ContentString,AllRows);
	
	if (AllRows.IsEmpty())return nullptr;
	
	float TotalChance = 0.0f;
	for (const FItemSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance += Row->Spawnchance;
		}
	}
	
	const float RandValue = FMath::FRandRange(0.0f,TotalChance);
	float AccumulateChance = 0.0f;
	
	for (FItemSpawnRow* Row : AllRows)
	{
		AccumulateChance += Row->Spawnchance;
		if (RandValue <= AccumulateChance)
		{
			return Row;
		}
	}
	return nullptr;
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent(); // GetScaledBoxExtent 박스 컴포먼트의 크기 값을 가져오는 함수 (중심에서 끝에서)
	FVector BoxOrigin = SpawningBox->GetComponentLocation(); // GetComponentLocation 박스의 중심좌표값을 가져오는 함수
	
	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X,BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y,BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z,BoxExtent.Z)); // FMath::FRandRange -> 처음값과 끝값중에 랜덤값을 가져오는 함수
}

void ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass) 
{
	if (!ItemClass) return;
	
	GetWorld()->SpawnActor<AActor>(
		ItemClass,
		GetRandomPointInVolume(),
		FRotator::ZeroRotator);
}

void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	SpawnRandomItem();
}
