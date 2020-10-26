#include "Upgrade.h"

// Sets default values
AUpgrade::AUpgrade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	meshComponenet = CreateDefaultSubobject<UStaticMeshComponent>("ROOT");
	RootComponent = meshComponenet;
	meshComponenet->SetSimulatePhysics(false);
	meshComponenet->SetEnableGravity(false);
	meshComponenet->SetGenerateOverlapEvents(true);
	meshComponenet->SetCollisionProfileName(FName("Upgrade"));
	Tags.Add(FName("Upgrade"));

}

// Called when the game starts or when spawned
void AUpgrade::BeginPlay()
{
	Super::BeginPlay();

}



// Called every frame
void AUpgrade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector loc = GetActorLocation();
	loc.Z += (-600.0 * DeltaTime);
	SetActorLocation(loc);
}

float AUpgrade::GetLifespan()
{
	return lifeSpan;
}

void AUpgrade::UpgradeEnd(APalete* actor)
{
	check(0 && "You must override this");
}
void AUpgrade::UpgradeStart(APalete* actor)
{
	check(0 && "You must override this");
}



