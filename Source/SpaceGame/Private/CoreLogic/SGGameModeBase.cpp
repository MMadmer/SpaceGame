// Fill out your copyright notice in the Description page of Project Settings.


#include "CoreLogic/SGGameModeBase.h"

#include "CoreLogic/Player/SGPlayer.h"
#include "CoreLogic/Player/SGPlayerController.h"
#include "CoreLogic/Player/SGPlayerState.h"
#include "UI/SGHUD.h"

ASGGameModeBase::ASGGameModeBase()
{
	DefaultPawnClass = ASGPlayer::StaticClass();
	PlayerControllerClass = ASGPlayerController::StaticClass();
	PlayerStateClass = ASGPlayerState::StaticClass();
	HUDClass = ASGHUD::StaticClass();
}
