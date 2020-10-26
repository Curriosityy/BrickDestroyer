// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"


// Sets default values
ABall::ABall()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComponenet = CreateDefaultSubobject<UStaticMeshComponent>("ROOT");
	RootComponent = meshComponenet;
	meshComponenet->SetSimulatePhysics(false);
	meshComponenet->SetEnableGravity(false);
	meshComponenet->SetConstraintMode(EDOFMode::YZPlane);
	meshComponenet->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	meshComponenet->SetCollisionProfileName(TEXT("Ball"));

	Tags.Add(FName("Ball"));

	movement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	movement->Bounciness = 1.0005f;
	movement->ProjectileGravityScale = 0.0f;
	movement->bShouldBounce = true;
	movement->Friction = 0;
	movement->MaxSpeed = 4000.f;
	movement->Velocity = FVector(0, 0, 0);
	movement->bSnapToPlaneAtStart = true;
	movement->bConstrainToPlane = true;
	movement->SetPlaneConstraintAxisSetting(EPlaneConstraintAxisSetting::X);

	SetReplicates(true);
}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
}

void ABall::Launch()
{
	UE_LOG(LogTemp, Warning, TEXT("Launch"));
	movement->AddForce(FVector(0, 1300.0f, 1200.0f) * 50);
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	FVector vector = this->GetVelocity();
	Super::Tick(DeltaTime);
}

