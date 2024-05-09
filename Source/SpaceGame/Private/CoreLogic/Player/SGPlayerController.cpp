// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreLogic/Player/SGPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interfaces/SGPlayerControls.h"

ASGPlayerController::ASGPlayerController(): MoveAction(nullptr), RunAction(nullptr), InteractAction(nullptr),
                                            AttackAction(nullptr)
{
}

void ASGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (const ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
		// Setup control mappings
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = LocalPlayer->GetSubsystem<
			UEnhancedInputLocalPlayerSubsystem>(); InputSubsystem && PlayerMappings.Num() > 0)
		{
			InputSubsystem->ClearAllMappings();
			for (const auto& PlayerMapping : PlayerMappings)
			{
				InputSubsystem->AddMappingContext(PlayerMapping, 0);
			}
		}
		else
		{
			UE_LOG(LogPlayerController, Warning, TEXT("Can't bind controls! Check PlayerMappings Set."));
		}
	}
}

void ASGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::TryMove);
		EnhancedInputComponent->BindAction(RunAction, ETriggerEvent::Triggered, this, &ThisClass::TryRun);
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ThisClass::TryInteract);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &ThisClass::TryAttack);
	}
	else
	{
		UE_LOG(LogPlayerController, Warning, TEXT("Input component not enhanced. Controls will not working."));
	}
}

void ASGPlayerController::TryMove(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	if (!ControlledPawn->Implements<USGPlayerControls>()) return;

	ISGPlayerControls::Execute_TryMove(ControlledPawn, Value.Get<FVector2D>());
}

void ASGPlayerController::TryRun(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	if (!ControlledPawn->Implements<USGPlayerControls>()) return;

	ISGPlayerControls::Execute_TryRun(ControlledPawn, Value.Get<bool>());
}

void ASGPlayerController::TryInteract(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	if (!ControlledPawn->Implements<USGPlayerControls>()) return;

	ISGPlayerControls::Execute_TryInteract(ControlledPawn, Value.Get<bool>());
}

void ASGPlayerController::TryAttack(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	if (!ControlledPawn->Implements<USGPlayerControls>()) return;

	ISGPlayerControls::Execute_TryAttack(ControlledPawn, Value.Get<bool>());
}
