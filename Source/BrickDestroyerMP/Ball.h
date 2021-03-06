// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Ball.generated.h"

UCLASS()
class BRICKDESTROYERMP_API ABall : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	void Launch();
	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* meshComponenet;
	UPROPERTY(EditAnywhere)
		UProjectileMovementComponent* movement;

};
