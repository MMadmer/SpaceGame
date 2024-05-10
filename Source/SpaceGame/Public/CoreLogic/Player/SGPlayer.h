// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "Interfaces/SGPlayerControls.h"
#include "SGPlayer.generated.h"

class UBGCHealthComponent;
class UBGCStaminaComponent;

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASGPlayer : public APaperZDCharacter, public ISGPlayerControls
{
	GENERATED_BODY()

public:
	explicit ASGPlayer(const FObjectInitializer& ObjInit);

	virtual void TryMove_Implementation(const FVector2D Value) override;
	virtual void TryRun_Implementation(const bool Value) override;
	virtual void TryInteract_Implementation(const bool Value) override;
	virtual void TryAttack_Implementation(const bool Value) override;
	virtual void TryBlock_Implementation(const bool Value) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBGCHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBGCStaminaComponent* StaminaComponent;
};
