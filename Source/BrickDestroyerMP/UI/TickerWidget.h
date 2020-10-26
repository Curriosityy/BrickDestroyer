// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "TickerWidget.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API UTickerWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void Tick(int32 tick);
	void HideTicker();
	UTickerWidget(const FObjectInitializer& ObjectInitializer);
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,meta = (BindWidget))
	UTextBlock* tickText;

	
};
