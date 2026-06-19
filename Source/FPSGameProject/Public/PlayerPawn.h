// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class FPSGAMEPROJECT_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	UCameraComponent* CameraComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
