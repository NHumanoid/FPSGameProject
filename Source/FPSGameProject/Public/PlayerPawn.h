// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "PlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class FPSGAMEPROJECT_API APlayerPawn : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Camera")
	UCameraComponent* CameraComp;
	
	UFUNCTION(BlueprintPure,Category="Health")
	float GetHealth() const;
	UFUNCTION(BlueprintCallable, Category="Health")
	void AddHealth(float Amount);

private:
	
	float NormalSpeed;
	float SprintSpeedMutiltiplier;
	float SprintSpeed;

protected:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		class AController* EventInstigator,
		AActor* DamageCauser) override; //데미지 어카운트 : 얼마나 데미지를 입었나, 데미지이벤트 : 누가 입었나?

	UFUNCTION()
	void Move(const FInputActionValue& value);
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);
	
	void OnDeath();
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float MaxHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Health")
	float Health;

};
