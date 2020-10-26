// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
/**
 * 
 */
class ABrick;
class BRICKDESTROYERMP_API BricksGenerator
{
public:
	BricksGenerator(TSubclassOf<ABrick>* brick, UWorld* world);
	~BricksGenerator();
	TArray<TArray<ABrick*>>* GenerateMap(TArray<TArray<int>>* map);

protected:
	TSubclassOf<ABrick>* brickBP;
	UWorld* world;

};
