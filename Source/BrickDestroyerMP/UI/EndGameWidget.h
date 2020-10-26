// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "EndGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API UEndGameWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* endText;
public:
	void ShowText();
	void HideText();
	void SetTextVisibility(ESlateVisibility visibility);
};
