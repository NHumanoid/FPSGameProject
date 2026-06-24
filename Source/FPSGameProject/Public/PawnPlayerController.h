// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PawnPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class FPSGAMEPROJECT_API APawnPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	APawnPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* StopJumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	UInputAction* SprintAction;

protected:

	virtual void BeginPlay() override;
	
};