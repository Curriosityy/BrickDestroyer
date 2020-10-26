// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeSpawner.h"

UpgradeSpawner::UpgradeSpawner(TArray<TSubclassOf<AUpgrade>>* upgrades, UWorld* world)
{
	this->upgrades = upgrades;
	this->world = world;
}

TSubclassOf<AUpgrade>* UpgradeSpawner::GetUpgradeToSpawn() const
{
	return &(*upgrades)[FMath::RandRange(0, (*upgrades).Num()-1)];
}

AUpgrade* UpgradeSpawner::SpawnUpgrade(FVector location,FRotator rotation)
{
	auto upgrade = world->SpawnActor<AUpgrade>((*GetUpgradeToSpawn()),location, rotation);
	return upgrade;
}

UpgradeSpawner::~UpgradeSpawner()
{
}
