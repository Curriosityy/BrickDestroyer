// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaletePlayerState.h"
#include "GameFramework/GameStateBase.h"
#include "PlayGameState.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API APlayGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
};
