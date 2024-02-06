// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacterWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
void UFPSCharacterWidget::UpdateHealth(float Health)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Health / 100.0f); // Health가 0에서 100 사이의 값이라고 가정
	}
}

void UFPSCharacterWidget::UpdateAmmos(int32 Ammo)
{
	if (AmmoText)
	{
		AmmoText->SetText(FText::AsNumber(Ammo));
	}	
}

void UFPSCharacterWidget::UpdateGold(int32 Gold)
{
	if (GoldText)
	{
		GoldText->SetText(FText::AsNumber(Gold));
	}
}