// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "PlayerGameMode.h"
#include "PawnPlayerController.h"

APlayerGameMode::APlayerGameMode()
{
	DefaultPawnClass = APlayerPawn::StaticClass();
	PlayerControllerClass = APawnPlayerController::StaticClass();
}
