// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h" //GetCharacterMovemont 들어가 있는 헤더파일
#include "PawnPlayerController.h"
#include "EnhancedInputComponent.h"
#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	PrimaryActorTick.bCanEverTick = false;
	// APlayerPawn::APlayerPawn() 생성자 내부
	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = false; // 1인칭이면 true, 3인칭이면 보통 false
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = true;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp,USpringArmComponent::SocketName);
	CameraComp->bUsePawnControlRotation = false;
	
	NormalSpeed = 600.0f;
	SprintSpeedMutiltiplier = 1.7f;
	SprintSpeed = NormalSpeed * SprintSpeedMutiltiplier;
	
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
	
	MaxHealth = 100.0f;
	Health = MaxHealth;
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (APawnPlayerController* PlayerController = Cast<APawnPlayerController>(GetController())) 
		{
			if(PlayerController -> MoveAction)
			{
				EnhancedInput->BindAction(PlayerController->MoveAction, ETriggerEvent::Triggered, this, &APlayerPawn::Move);
			}
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(PlayerController->JumpAction, ETriggerEvent::Triggered, this, &APlayerPawn::StartJump);
			}
			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(PlayerController->LookAction, ETriggerEvent::Triggered, this, &APlayerPawn::Look);
			}
			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(PlayerController->SprintAction, ETriggerEvent::Triggered, this, &APlayerPawn::StartSprint);
			}
			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(PlayerController->SprintAction, ETriggerEvent::Triggered, this, &APlayerPawn::StopSprint);
			}
		}
	}
}
void APlayerPawn::Move(const FInputActionValue& value)
{
	if(!Controller) return;

	const FVector2D MoveInput = value.Get<FVector2D>();

	if (!FMath::IsNearlyZero(MoveInput.X)) 
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);

	}
	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);

	}
}

void APlayerPawn::StartJump(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		Jump();	
	}
}
void APlayerPawn::StopJump(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		StopJumping();
	}
}

void APlayerPawn::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();
	
	AddControllerYawInput(LookInput.X); //좌,우
	AddControllerPitchInput(LookInput.Y); //위,아래
}

void APlayerPawn::StartSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement()) //만약 캐릭터 이동을 가져오면
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}
void APlayerPawn::StopSprint(const FInputActionValue& value)
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

float APlayerPawn::GetHealth() const
{
	return Health;
}

void APlayerPawn::AddHealth(float Amount)
{
	Health += FMath::Clamp(Health+Amount,0.0f,MaxHealth);
	UE_LOG(LogTemp,Warning,TEXT("Health: %f"),Health);
}

float APlayerPawn::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount,DamageEvent,EventInstigator,DamageCauser);
	
	Health = FMath::Clamp(Health - DamageAmount,0.0f,MaxHealth);
	UE_LOG(LogTemp,Log,TEXT("Health: %f"),Health);

	if (Health < 0.0f)
	{
		OnDeath();
	}
	return ActualDamage;
}

void APlayerPawn::OnDeath()
{
	
}
