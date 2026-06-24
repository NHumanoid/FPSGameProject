// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnPlayerController.h"
#include "EnhancedInputSubsystems.h"

APawnPlayerController::APawnPlayerController() : InputMappingContext(nullptr), MoveAction(nullptr), JumpAction(nullptr), LookAction(nullptr), SprintAction(nullptr)
{

}

void APawnPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if(InputMappingContext)
			{
				Subsystem->AddMappingContext(InputMappingContext, 0);
			}
		}
	}
}