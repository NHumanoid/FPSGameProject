#include "MineItem.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"

AMineItem::AMineItem()
{
	
	ExplosionDelay = 5.0f; // 폭발유지 초기화
	ExplosionDamage = 30.0f; // 폭발 데미지
	ExplosionRadius = 300.0f; 
	ItemType = "Mine"; // 아이템 종류
	
	ExplosionCollition = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollition->InitSphereRadius(ExplosionRadius);
	ExplosionCollition->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollition->SetupAttachment(Scene);
	
}

void AMineItem::ActivateItem(AActor* Activator)
{
	//타이머 핸들러 - 타이머 핸들러는 게임월드에서 여러개의 타이머 핸들러가 존재한다 이를 관리하는 것이 타이머 매니저이다.
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle,this,&AMineItem::Explode,ExplosionDelay,false);
	// GetWorld->GetTimeManager().SetTimer(타이머핸들러의 이름, 자신의,MineItem에 있는 폭발함수를, 5초 이내에 폭발시켜라!!!, 한번실행);
}

void AMineItem::Explode()
{
	TArray<AActor*> OverlappingActors;
	ExplosionCollition->GetOverlappingActors(OverlappingActors);
	
	for(AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag(TEXT("Player")))
		{
			UGameplayStatics::ApplyDamage(Actor,ExplosionDamage,nullptr,this,UDamageType::StaticClass());
		}
	}
	DestroyItem();
}
