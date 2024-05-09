// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreLogic/Player/SGPlayer.h"

#include "Components/BGCHealthComponent.h"
#include "Components/BGCStaminaComponent.h"

ASGPlayer::ASGPlayer(const FObjectInitializer& ObjInit)
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	bWantsToRun = false;
	bIsMovingForward = false;

	HealthComponent = CreateDefaultSubobject<UBGCHealthComponent>("HealthComponent");
	StaminaComponent = CreateDefaultSubobject<UBGCStaminaComponent>("StaminaComponent");
}

void ASGPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void ASGPlayer::TryMove_Implementation(const FVector2D Value)
{
	ISGPlayerControls::TryMove_Implementation(Value);
}

void ASGPlayer::TryRun_Implementation(const bool Value)
{
	ISGPlayerControls::TryRun_Implementation(Value);
}

void ASGPlayer::TryInteract_Implementation(const bool Value)
{
	ISGPlayerControls::TryInteract_Implementation(Value);
}

void ASGPlayer::TryAttack_Implementation(const bool Value)
{
	ISGPlayerControls::TryAttack_Implementation(Value);
}
