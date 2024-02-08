// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "FPSPlayerState.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDele_UpdateHp, float, CurHp, float, MaxHp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_UpdateAmmo, int, Ammo);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDele_UpdateGold, int, Gold);
UCLASS()
class TITLE2LOBBY_API AFPSPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AFPSPlayerState();
public:
	UFUNCTION()
	void AddDamage(float Damage);

	UFUNCTION()
	void AddHeal(float Heal);

	UFUNCTION()
	void AddAmmo();

	UFUNCTION()
	void UseAmmo();
	
	UFUNCTION()
	void AddGold();

	UFUNCTION()
	void UseGold();

public:
	UFUNCTION()
	void OnRep_CurHp();

	UFUNCTION()
	void OnRep_Ammo();

	UFUNCTION()
	void OnRep_Gold();
public:
	UPROPERTY(ReplicatedUsing = OnRep_CurHp)
	float m_CurHp;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateHp m_Dele_UpdateHp;

	UPROPERTY(ReplicatedUsing = OnRep_Ammo)
	float m_Ammo;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateAmmo m_Dele_UpdateAmmo;

	UPROPERTY(ReplicatedUsing = OnRep_Gold)
	float m_Gold;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateGold m_Dele_UpdateGold;
};
