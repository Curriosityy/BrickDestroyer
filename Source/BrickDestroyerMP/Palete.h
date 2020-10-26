// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#include "PaleteMovementComponent.h"
#include "GameFramework/Pawn.h"

#include "Palete.generated.h"
UCLASS()
class BRICKDESTROYERMP_API APalete : public APawn
{
	GENERATED_BODY()

private:

	UPROPERTY(EditAnywhere)
		UMeshComponent* meshComponenet;

	UPROPERTY(EditAnywhere)
		UPaleteMovementComponent* movementComponent;

	UPROPERTY(EditAnywhere)
		float speed = 3;

public:
	// Sets default values for this pawn's properties
	APalete();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	virtual void Tick(float DeltaTime) override;
	virtual UPawnMovementComponent* GetMovementComponent() const override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void Move(float value);
	UFUNCTION()
	void OnUpgradeEnd(AActor* upgradeEnd);

};
