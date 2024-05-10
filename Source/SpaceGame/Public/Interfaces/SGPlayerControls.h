// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SGPlayerControls.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USGPlayerControls : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACEGAME_API ISGPlayerControls
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(Blueprintable, BlueprintNativeEvent, Category="Player Controls")
	void TryMove(const FVector2D Value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Player Controls")
	void TryRun(const bool Value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Player Controls")
	void TryInteract(const bool Value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Player Controls")
	void TryAttack(const bool Value);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Player Controls")
	void TryBlock(const bool Value);
};
