// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <BrickDestroyerMP\Palete.h>
#include "Upgrade.generated.h"

UCLASS(Abstract)
class BRICKDESTROYERMP_API AUpgrade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUpgrade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* meshComponenet;
	UPROPERTY(EditAnywhere)
		float lifeSpan=0;

public:	
	float GetLifespan();
	//AFTER TEST MAKE THIS ABSTRACT
	UFUNCTION()
	virtual void UpgradeStart(APalete* actor);
	UFUNCTION()
	virtual void UpgradeEnd(APalete* actor);
	virtual void Tick(float DeltaTime) override;

};
