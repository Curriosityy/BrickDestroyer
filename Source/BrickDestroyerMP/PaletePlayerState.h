// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerState.h"
#include "Ball.h"

#include "PaletePlayerState.generated.h"
/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API APaletePlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<ABall*> myBalls;

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<ABall> ballBP;
	virtual void BeginPlay() override;


	UFUNCTION()
	void RemoveFromMyBalls(AActor* actor);

	void AttachBallToPawn(ABall* ball);
public:
	void DetachBall(ABall* ball);
	ABall* SpawnNewBall();
};
