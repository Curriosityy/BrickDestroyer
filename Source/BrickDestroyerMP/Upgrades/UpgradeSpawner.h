// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Upgrade.h"
#include "Engine/World.h"
/**
 * 
 */
class AUpgrade;
class BRICKDESTROYERMP_API UpgradeSpawner
{
private:
	TArray<TSubclassOf<AUpgrade>>* upgrades;
	UWorld* world;
public:
	UpgradeSpawner(TArray<TSubclassOf<AUpgrade>>* upgrades, UWorld* world);
	TSubclassOf<AUpgrade>* GetUpgradeToSpawn() const;
	AUpgrade* SpawnUpgrade(FVector location, FRotator rotation);
	~UpgradeSpawner();

};
