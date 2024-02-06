// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FPSCharacterWidget.generated.h"

/**
 * 
 */
class UProgressBar;
class UTextBlock;
UCLASS()
class TITLE2LOBBY_API UFPSCharacterWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	// UI 요소에 대한 참조
	UPROPERTY(meta = (BindWidget))
	UProgressBar* HealthProgressBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* AmmoText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GoldText;

public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateHealth(float Health);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateAmmos(int32 Bullets);

	UFUNCTION(BlueprintCallable, Category = "UI")
	void UpdateGold(int32 Gold);
};
