// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActionRougeLike/DataAssets/InputActionDataAsset.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

class ASMagicProjectile;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ACTIONROUGELIKE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	//Move Character Forward/Backward
	void Moving(const FInputActionInstance& Instance);
	//Turn Character Controller Yaw
	void Turning(const FInputActionInstance& Instance);
	void Fire(const FInputActionInstance& Instance);
	//SpringArm For 3Person Camera Control
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;
	//Camera Attached To SpringArm
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	//Data Asset With InputAction (Moving,Turn...)
	UPROPERTY(EditAnywhere, Category="Properties|Input")
	UInputActionDataAsset* InputActions;
	UPROPERTY(EditAnywhere, Category="Properties|Input")
	UInputMappingContext* InputMapping;
	UPROPERTY(EditAnywhere, Category="Properties|Gameplay")
	TSubclassOf<ASMagicProjectile> ProjectileBP;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
