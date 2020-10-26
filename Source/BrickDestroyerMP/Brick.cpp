// Fill out your copyright notice in the Description page of Project Settings.

#include "Brick.h"

#include "BrickDestroyerMPGameModeBase.h"
#include "Upgrades\UpgradeSpawner.h"

// Sets default values
ABrick::ABrick()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root"));
	RootComponent = meshComponent;
	meshComponent->SetCollisionProfileName(TEXT("Brick"));
	meshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	meshComponent->SetNotifyRigidBodyCollision(true);
	meshComponent->SetGenerateOverlapEvents(true);
	SetReplicates(true);
}

void ABrick::Initialize(int ahits)
{
	hits = ahits;
	
	dynamicMaterial = UMaterialInstanceDynamic::Create(meshComponent->GetMaterial(0), nullptr);
	meshComponent->SetMaterial(0, dynamicMaterial);

	SetColor();

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	Subscrube();
}


void ABrick::Subscrube()
{
	meshComponent->OnComponentHit.AddDynamic(this, &ABrick::OnBrickHit);
}


void  ABrick::OnBrickHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

		if (OtherActor->ActorHasTag(FName("Ball")))
		{
			if (--hits <= 0)
			{
				this->Destroy();

				if (FMath::RandRange(0.0f, 1.0f) <= 0.3f)
				{
					auto gameModeBase = (ABrickDestroyerMPGameModeBase*)GetWorld()->GetAuthGameMode();
					if (gameModeBase)
						gameModeBase->upgradeSpawner->SpawnUpgrade(GetActorLocation(), FRotator());
				}
			}
			else
			{
				SetColor();
			}
		}
	

}

void ABrick::SetColor()
{
	dynamicMaterial->SetVectorParameterValue("Color", colors[FMath::Clamp<int>(hits - 1, 0, colors.Num()-1)]);
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}