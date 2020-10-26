// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGameWidget.h"

void UEndGameWidget::ShowText()
{
	endText->SetVisibility(ESlateVisibility::Visible);
}

void UEndGameWidget::HideText()
{
	endText->SetVisibility(ESlateVisibility::Hidden);
}

void UEndGameWidget::SetTextVisibility(ESlateVisibility visibility)
{
	endText->SetVisibility(visibility);
}
