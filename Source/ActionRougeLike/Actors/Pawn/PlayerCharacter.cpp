// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "ActionRougeLike/MyUeLog.h"
#include "ActionRougeLike/Actors/SMagicProjectile.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComp->SetupAttachment(SpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;

	bUseControllerRotationYaw = false;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (const APlayerController* MyController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* LocalPlayer = ULocalPlayer::GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(MyController->GetLocalPlayer()))
		{
			LocalPlayer->ClearAllMappings();
			LocalPlayer->AddMappingContext(InputMapping, 0);
		}
		else
		{
			FErrorLog::MyLog("Error On LocalPlayer");
		}
	}
	else
	{
		FErrorLog::MyLog("Error On MyController");
	}

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(InputActions->Moving, ETriggerEvent::Triggered, this,
		                                   &APlayerCharacter::Moving);
		EnhancedInputComponent->BindAction(InputActions->Turn, ETriggerEvent::Triggered, this,
		                                   &APlayerCharacter::Turning);
		EnhancedInputComponent->BindAction(InputActions->Fire, ETriggerEvent::Triggered, this,
		                                   &APlayerCharacter::Fire);
	}
	else
	{
		FErrorLog::MyLog("Error On EnhancedInputComponent");
	}
}

void APlayerCharacter::Moving(const FInputActionInstance& Instance)
{
	const FVector2d MovingAxis = Instance.GetValue().Get<FVector2d>();

	const FRotator ControlRot{0.f, GetControlRotation().Yaw, 0.f};
	//Calculate right vector of controller rotation
	const FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(ControlRot.Vector(), MovingAxis.Y);
	AddMovementInput(RightVector, MovingAxis.X);
}

void APlayerCharacter::Turning(const FInputActionInstance& Instance)
{
	const FVector2d MovingAxis = Instance.GetValue().Get<FVector2d>();
	AddControllerYawInput(MovingAxis.X);
	AddControllerPitchInput(MovingAxis.Y * -1.0f);
}

void APlayerCharacter::Fire(const FInputActionInstance& Instance)
{
	const FVector SpawnLocation{GetMesh()->GetSocketLocation("Muzzle_01")};
	const FRotator SpawnRot{GetControlRotation()};
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<ASMagicProjectile>(ProjectileBP, SpawnLocation, SpawnRot, SpawnParameters);
}
