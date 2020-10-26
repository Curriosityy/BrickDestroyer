// Fill out your copyright notice in the Description page of Project Settings.


#include "BallDestroyer.h"

// Sets default values
ABallDestroyer::ABallDestroyer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComponent = CreateDefaultSubobject<UBoxComponent>(FName("RootBox"));
	RootComponent = boxComponent;
	boxComponent->SetCollisionProfileName("NonCollsion");
	boxComponent->SetSimulatePhysics(false);
	boxComponent->SetEnableGravity(false);
	boxComponent->SetGenerateOverlapEvents(true);

}

// Called when the game starts or when spawned
void ABallDestroyer::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorBeginOverlap.AddDynamic(this, &ABallDestroyer::OnOverlapBegin);
}
void ABallDestroyer::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor) {
	if (OtherActor->ActorHasTag("Ball") || OtherActor->ActorHasTag("Upgrade"))
	{
		OtherActor->Destroy();
	}

}
// Called every frame
void ABallDestroyer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

