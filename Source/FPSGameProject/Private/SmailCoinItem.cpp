
#include "SmailCoinItem.h"

ASmailCoinItem::ASmailCoinItem()
{
	PointValue = 10;
	ItemType = "SmailCoin";
}

void ASmailCoinItem::ActivateItem(AActor* Activator)
{
	Destroy();
}
