// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayGameState.h"

void APlayGameState::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("APlayGameState BeginPlay"));
	

	auto state = (APaletePlayerState*)PlayerArray[0];
	auto ball = state->myBalls[0];
	state->DetachBall(ball);
	ball->Launch();

}