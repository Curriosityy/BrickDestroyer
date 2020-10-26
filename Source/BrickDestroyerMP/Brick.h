// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

#include "Brick.generated.h"

UCLASS()
class BRICKDESTROYERMP_API ABrick : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* meshComponent;
	UPROPERTY(EditAnywhere)
	TArray<FLinearColor> colors;

	int hits=0;
	class UMaterialInstanceDynamic* dynamicMaterial;


public:
	// Sets default values for this actor's properties
	ABrick();
	void Initialize(int hits);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Subscrube();
	UFUNCTION()
	void OnBrickHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void SetColor();



public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
