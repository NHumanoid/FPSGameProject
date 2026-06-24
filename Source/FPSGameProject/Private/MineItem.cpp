#include "MineItem.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.0f; // 폭발유지 초기화
	ExplosionRadius = 300.0f; // 폭발범위
	ExplosionDamage = 30.0f; // 폭발 데미지
	ItemType = "Mine"; // 아이템 종류
}

void AMineItem::ActivateItem(AActor* Activator)
{
	
}
