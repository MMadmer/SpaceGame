// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SGPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASGPlayerController();

protected:
	// Input
	// ------------------------------------------------------------
	/** Main player mapping context with all supported actions.*/
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TSet<UInputMappingContext*> PlayerMappings;

	UPROPERTY(EditDefaultsOnly, Category="Input|Supported Actions")
	UInputAction* MoveAction;

	UPROPERTY(EditDefaultsOnly, Category="Input|Supported Actions")
	UInputAction* RunAction;

	UPROPERTY(EditDefaultsOnly, Category="Input|Supported Actions")
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, Category="Input|Supported Actions")
	UInputAction* AttackAction;

	UPROPERTY(EditDefaultsOnly, Category="Input|Supported Actions")
	UInputAction* BlockAction;
	// ------------------------------------------------------------

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	void TryMove(const FInputActionValue& Value);
	void TryRun(const FInputActionValue& Value);
	void TryInteract(const FInputActionValue& Value);
	void TryAttack(const FInputActionValue& Value);
	void TryBlock(const FInputActionValue& Value);
};
