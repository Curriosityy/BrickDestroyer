// Fill out your copyright notice in the Description page of Project Settings.


#include "PrepareGameState.h"

APrepareGameState::APrepareGameState()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APrepareGameState::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	timer -= deltaTime;
	inGameHud->TickerTick(FMath::CeilToInt(timer));
	if (timer <= 0)
	{
		auto gameModeBase = ((ABrickDestroyerMPGameModeBase*)GetWorld()->GetAuthGameMode());
		if(gameModeBase)
			gameModeBase->ChangeStateToPlay();
	}
}

void APrepareGameState::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("APrepareGameState BeginPlay"));
	timer = 3;
	inGameHud = Cast<AInGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}
