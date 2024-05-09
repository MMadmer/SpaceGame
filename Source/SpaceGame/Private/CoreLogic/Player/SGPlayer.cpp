// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreLogic/Player/SGPlayer.h"

#include "Components/BGCHealthComponent.h"
#include "Components/BGCStaminaComponent.h"
#include "Components/BGCCharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

ASGPlayer::ASGPlayer(const FObjectInitializer& ObjInit) : Super(
	ObjInit.SetDefaultSubobjectClass<UBGCCharacterMovementComponent>(CharacterMovementComponentName))
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

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

	if (!Controller) return;

	FVector CameraLocation{};
	FRotator CameraRotation{};

	Controller->GetPlayerViewPoint(CameraLocation, CameraRotation);
	CameraRotation.Pitch = 0.0f;
	CameraRotation.Roll = 0.0f;

	const FVector Movement = UKismetMathLibrary::Quat_RotateVector(UE::Math::TQuat(CameraRotation),
	                                                               FVector(Value.Y, Value.X, 0.0f));

	AddMovementInput(Movement);
}

void ASGPlayer::TryRun_Implementation(const bool Value)
{
	ISGPlayerControls::TryRun_Implementation(Value);

	if (const auto MovementComp = Cast<UBGCCharacterMovementComponent>(GetMovementComponent())) MovementComp->
		bWantsToRun = Value;
}

void ASGPlayer::TryInteract_Implementation(const bool Value)
{
	ISGPlayerControls::TryInteract_Implementation(Value);
}

void ASGPlayer::TryAttack_Implementation(const bool Value)
{
	ISGPlayerControls::TryAttack_Implementation(Value);
}
