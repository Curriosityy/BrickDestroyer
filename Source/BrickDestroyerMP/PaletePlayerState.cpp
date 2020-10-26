// Fill out your copyright notice in the Description page of Project Settings.


#include "PaletePlayerState.h"
#include "BrickDestroyerMPGameModeBase.h"

void APaletePlayerState::BeginPlay()
{
	auto spawnedBall = SpawnNewBall();
	AttachBallToPawn(spawnedBall);
}

ABall* APaletePlayerState::SpawnNewBall()
{
	auto myPawn = GetPawn();
	auto spawnBallPosition = myPawn->GetTransform().GetLocation() + FVector(0, 0, 250.f);
	auto spawnedBall = GetWorld()->SpawnActor<ABall>(ballBP, spawnBallPosition, FRotator(), FActorSpawnParameters());
	myBalls.Add(spawnedBall);
	spawnedBall->OnDestroyed.AddDynamic(this, &APaletePlayerState::RemoveFromMyBalls);
	return spawnedBall;
}

void APaletePlayerState::RemoveFromMyBalls(AActor* actor)
{
	myBalls.Remove((ABall*)actor);
	if (myBalls.Num() <= 0)
	{
		auto gameModeBase= (ABrickDestroyerMPGameModeBase*)GetWorld()->GetAuthGameMode();
		if (gameModeBase)
			gameModeBase->ChangeStateToGameOver();
	}
}

void APaletePlayerState::AttachBallToPawn(ABall* ball)
{
	auto rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true);
	ball->AttachToActor(GetPawn(), rules);
}

void APaletePlayerState::DetachBall(ABall* ball)
{
	//auto rules = FDetachmentTransformRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, true);
	ball->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
}