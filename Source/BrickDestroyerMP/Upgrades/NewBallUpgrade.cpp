// Fill out your copyright notice in the Description page of Project Settings.


#include "NewBallUpgrade.h"
void ANewBallUpgrade::UpgradeStart(APalete* actor)
{
	auto ball = ((APaletePlayerState*)actor->GetPlayerState())->SpawnNewBall();
	ball->Launch();
}

void ANewBallUpgrade::UpgradeEnd(APalete* actor)
{

}