// Fill out your copyright notice in the Description page of Project Settings.

#include "Palete.h"

#include "Upgrades/Upgrade.h"

// Sets default values
APalete::APalete()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	meshComponenet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	RootComponent = meshComponenet;
	meshComponenet->SetCollisionProfileName(TEXT("Palete"));
	meshComponenet->SetGenerateOverlapEvents(true);

	movementComponent = CreateDefaultSubobject<UPaleteMovementComponent>(TEXT("MovementComponent"));
	movementComponent->UpdatedComponent = RootComponent;
	movementComponent->Init(&speed);	
	Tags.Add(FName("Palete"));
	SetReplicates(true);

}

// Called when the game starts or when spawned
void APalete::BeginPlay()
{
	Super::BeginPlay();
	//meshComponenet->OnComponentBeginOverlap.AddDynamic(this, &APalete::OnOverlap);
	OnActorBeginOverlap.AddDynamic(this, &APalete::OnOverlap);

}
void APalete::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor->ActorHasTag("Upgrade"))
	{
		auto upgrade = (AUpgrade*)OtherActor;

		upgrade->UpgradeStart(this);
		upgrade->SetLifeSpan(upgrade->GetLifespan());
		upgrade->SetActorHiddenInGame(true);
		upgrade->OnDestroyed.AddDynamic(this, &APalete::OnUpgradeEnd);
	}
}
// Called every frame
void APalete::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UPawnMovementComponent* APalete::GetMovementComponent() const
{
	return movementComponent;
}

// Called to bind functionality to input
void APalete::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &APalete::Move);
}

void APalete::Move(float value)
{
	if (movementComponent && (movementComponent->UpdatedComponent == RootComponent))
	{
		movementComponent->AddInputVector(GetActorRightVector() * value);
	}
}

void APalete::OnUpgradeEnd(AActor* upgradeEnd)
{
	 ((AUpgrade*)upgradeEnd) -> UpgradeEnd(this);
}

