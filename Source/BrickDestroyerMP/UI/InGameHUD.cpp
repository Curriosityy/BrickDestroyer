// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHUD.h"
#include "TickerWidget.h"
#include "EndGameWidget.h"

void AInGameHUD::BeginPlay()
{
	Super::BeginPlay();
	if (tickerWidgetBP)
	{
		auto world = GetWorld();
		tickerWidget = CreateWidget<UTickerWidget>(world, tickerWidgetBP);
		if (tickerWidget)
		{
			tickerWidget->AddToViewport();
		}
		endGameWidget = CreateWidget<UEndGameWidget>(world, endGameWidgetBP);
		if (endGameWidget)
		{
			endGameWidget->AddToViewport();
			HideEndGameText();
		}
	}
}

void AInGameHUD::TickerTick(int32 tick)
{
	if (tickerWidget)
		tickerWidget->Tick(tick);
}

void AInGameHUD::HideTicker()
{
	if (tickerWidget)
		tickerWidget->HideTicker();
}

void AInGameHUD::ShowEndGameText()
{
	if (endGameWidget)
		endGameWidget->ShowText();
}

void AInGameHUD::HideEndGameText()
{
	if (endGameWidget!=nullptr)
		endGameWidget->HideText();
}
