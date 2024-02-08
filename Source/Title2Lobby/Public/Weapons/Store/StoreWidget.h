// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class TITLE2LOBBY_API UStoreWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UButton* BuyButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UTextBlock* BuyButtonText;

public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void OnBuyButtonClicked();

public:
	// 소환될 무기 클래스
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<class AWeaponBase> WeaponClass;
};
