// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/GameModeBase.h"
#include "Math/UnrealMathUtility.h"

#include "BrickDestroyerMPGameModeBase.generated.h"

class ABrick;
class APalete;
class AUpgrade;
class UpgradeSpawner;
UCLASS()
class BRICKDESTROYERMP_API ABrickDestroyerMPGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<APalete> playerBP;
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABrick> brickBP;
	UPROPERTY(EditAnywhere)
	TArray<TSubclassOf<AUpgrade>> upgradeBPs;

	FVector brickSize;
	FVector firstBrickPosition;
	FVector2D mapSize;
	TArray<TArray<ABrick*>>* brickMap;
	UpgradeSpawner* upgradeSpawner;

	ABrickDestroyerMPGameModeBase();
	virtual void StartPlay() override;
	void GenerateMap(UWorld* world);
	virtual void BeginDestroy() override;

	void ChangeStateToPlay();
	void SetNewGameState(AGameStateBase* gamestate);
	void ChangeStateToGameOver();

};

