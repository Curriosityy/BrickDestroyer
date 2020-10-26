// Fill out your copyright notice in the Description page of Project Settings.


#include "TickerWidget.h"
UTickerWidget::UTickerWidget(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}


void UTickerWidget::Tick(int32 tick)
{
	if (tickText)
	{
		if (tick > 0)
		{
			tickText->SetVisibility(ESlateVisibility::Visible);
			tickText->SetText(FText(FText::AsNumber(tick)));
		}
		else {
			HideTicker();
		}
	}
}

void UTickerWidget::HideTicker()
{
	tickText->SetVisibility(ESlateVisibility::Hidden);
}
