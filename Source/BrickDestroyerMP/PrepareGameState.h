// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameStateBase.h"
#include "UI/InGameHUD.h"
#include "BrickDestroyerMPGameModeBase.h"

#include "PrepareGameState.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API APrepareGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	APrepareGameState();
	virtual void Tick(float deltaTime) override;
	virtual void BeginPlay() override;
private:
	float timer;
	AInGameHUD* inGameHud;
};
