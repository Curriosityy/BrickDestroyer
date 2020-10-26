// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "PaleteMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API UPaleteMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()
private:
	float* speed;
public:
	void Init(float* speed);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
