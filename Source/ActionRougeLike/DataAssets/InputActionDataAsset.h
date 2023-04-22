// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "Engine/DataAsset.h"
#include "InputActionDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROUGELIKE_API UInputActionDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Moving;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Turn;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UInputAction* Fire;
};
