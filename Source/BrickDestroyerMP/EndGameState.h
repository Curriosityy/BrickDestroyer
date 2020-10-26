// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EndGameState.generated.h"

/**
 * 
 */
class AInGameHUD;
UCLASS()
class BRICKDESTROYERMP_API AEndGameState : public AGameStateBase
{
	GENERATED_BODY()
private:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
	AInGameHUD* inGameHud;
	void SetGamePause(bool pause);
};