// Fill out your copyright notice in the Description page of Project Settings.


#include "BricksGenerator.h"

#include "Brick.h"
#include "BrickDestroyerMPGameModeBase.h"

BricksGenerator::BricksGenerator(TSubclassOf<ABrick>* brick,UWorld* world)
{
	brickBP = brick;
	this->world = world;
}

BricksGenerator::~BricksGenerator()
{
}

TArray<TArray<ABrick*>>* BricksGenerator::GenerateMap(TArray<TArray<int>>* map)
{
	TArray<TArray<ABrick*>>* brickMap =new TArray<TArray<ABrick*>>();
	ABrickDestroyerMPGameModeBase* base =  (ABrickDestroyerMPGameModeBase*)world->GetAuthGameMode();
	FVector fbp = base->firstBrickPosition;
	FVector bs = base->brickSize;
	(*brickMap).AddDefaulted(base->mapSize.X);
	ABrick* generatedBrick = nullptr;
	for (int i = 0; i < base->mapSize.X;i++)
	{
		for (int j = 0; j < base->mapSize.Y; j++)
		{
			if ((*map)[i][j] > 0)
			{
				FActorSpawnParameters para;
				FVector position = fbp + FVector(0, bs.Y*j, (-bs.Z)* i);
				generatedBrick=world->SpawnActor<ABrick>((*brickBP), position,FRotator(),FActorSpawnParameters());
				generatedBrick->SetFolderPath("/Bricks");
				generatedBrick->Initialize((*map)[i][j]);
			}
			(*brickMap)[i].Add(generatedBrick);
		}
	}
	return brickMap;
}
