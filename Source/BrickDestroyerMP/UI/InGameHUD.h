// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/HUD.h"
#include "Blueprint/UserWidget.h"

#include "InGameHUD.generated.h"

/**
 * 
 */
class UEndGameWidget;
class UTickerWidget;
UCLASS()
class BRICKDESTROYERMP_API AInGameHUD : public AHUD
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> tickerWidgetBP;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> endGameWidgetBP;

	UTickerWidget* tickerWidget;
	AInGameHUD* inGameHud;
	UEndGameWidget* endGameWidget;
public:
	virtual void BeginPlay() override;
	void TickerTick(int32 tick);
	void HideTicker();
	void ShowEndGameText();
	void HideEndGameText();
};
