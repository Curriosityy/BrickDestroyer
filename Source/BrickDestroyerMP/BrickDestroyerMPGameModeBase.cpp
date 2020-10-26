// Copyright Epic Games, Inc. All Rights Reserved.

#include "BrickDestroyerMPGameModeBase.h"

#include "Palete.h"
#include "Brick.h"
#include "Upgrades/UpgradeSpawner.h"
#include "Ball.h"
#include "BricksGenerator.h"
#include "PrepareGameState.h"
#include "PlayGameState.h"
#include "EndGameState.h"


ABrickDestroyerMPGameModeBase::ABrickDestroyerMPGameModeBase()
{
	GameStateClass = APrepareGameState::StaticClass();
	brickSize = FVector(0, 300, 100);
	firstBrickPosition = FVector(0, -1650, 2000);
	mapSize = FVector2D(12, 12);
}


void ABrickDestroyerMPGameModeBase::StartPlay() {

	Super::StartPlay();

	UWorld* world = GetWorld();
	upgradeSpawner = new UpgradeSpawner(&upgradeBPs, world);
	GenerateMap(world);
}

void ABrickDestroyerMPGameModeBase::GenerateMap(UWorld* world)
{
	BricksGenerator bg = BricksGenerator(&brickBP, world);
	TArray<TArray<int>> map = TArray<TArray<int>>();
	FMath::RandInit(FMath::GetRandSeed());
	for (int i = 0; i < mapSize.X; i++)
	{
		map.Add(TArray<int>());
		for (int j = 0; j < mapSize.Y; j++)
		{
			map[i].Add(FMath::RandRange(0, 5));
		}
	}
	brickMap = bg.GenerateMap(&map);
}

void ABrickDestroyerMPGameModeBase::BeginDestroy()
{
	Super::BeginDestroy();
	if (brickMap != nullptr)
	{
		brickMap->~TArray();
	}
	if (upgradeSpawner != nullptr)
	{
		upgradeSpawner->~UpgradeSpawner();
	}
}

void ABrickDestroyerMPGameModeBase::ChangeStateToPlay()
{
	auto gamestate = GetWorld()->SpawnActor<APlayGameState>();
	SetNewGameState(gamestate);
}

void ABrickDestroyerMPGameModeBase::SetNewGameState(AGameStateBase* gamestate)
{
	GameState->Destroy();
	GetWorld()->SetGameState(gamestate);
	GameState = gamestate;
}

void ABrickDestroyerMPGameModeBase::ChangeStateToGameOver()
{
	auto gamestate = GetWorld()->SpawnActor<AEndGameState>();
	SetNewGameState(gamestate);
}
