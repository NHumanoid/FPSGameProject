
#include "PlayerPawn.h"
#include "PlayerGameMode.h"
#include "PawnPlayerController.h"

APlayerGameMode::APlayerGameMode()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = APawnPlayerController::StaticClass();
}
