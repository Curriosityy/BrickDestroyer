// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameState.h"
#include "UI/InGameHUD.h"

void AEndGameState::BeginPlay()
{
    Super::BeginPlay();
	inGameHud = Cast<AInGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    SetGamePause(true);
	inGameHud->ShowEndGameText();
}

void AEndGameState::SetGamePause(bool pause)
{
	auto world = GetWorld();
	if (world)
	{
		APlayerController* const MyPlayer = Cast<APlayerController>(GEngine->GetFirstLocalPlayerController(world));
		if (MyPlayer != NULL)
		{
			MyPlayer->SetPause(pause);
		}
	}


}

void AEndGameState::BeginDestroy() {
    Super::BeginDestroy();
    SetGamePause(false);
	inGameHud->HideEndGameText();
}
