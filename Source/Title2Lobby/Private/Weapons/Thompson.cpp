// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Thompson.h"
#include "GameFramework/Character.h"

AThompson::AThompson()
{
	KindOfWeapon = EWeaponType::Thompson;
	m_Ammo = 30;
}

void AThompson::EventTrigger_Implementation(bool IsPress)
{
	if (IsPress)
	{
		LoopShootMontage();
		FTimerManager& timerManager = GetWorld()->GetTimerManager();
		timerManager.SetTimer(th_loopShoot, this, &AThompson::LoopShootMontage, 0.1f, true);
	}
	else
	{
		FTimerManager& timerManager = GetWorld()->GetTimerManager();
		timerManager.ClearTimer(th_loopShoot);
	}
}

void AThompson::LoopShootMontage()
{
	if (IsValid(ShootMontage) == false)
		return;

	m_pOwnChar->PlayAnimMontage(ShootMontage);
}
