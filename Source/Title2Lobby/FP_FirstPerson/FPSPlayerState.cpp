// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerState.h"

#include "FPSHUD.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"
#include "Weapons/WeaponBase.h"

void AFPSPlayerState::BeginPlay()
{
	Super::BeginPlay();
	OnRep_CurHp();
}

AFPSPlayerState::AFPSPlayerState() : m_CurHp(100)
{
}
void AFPSPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFPSPlayerState, m_CurHp);
	DOREPLIFETIME(AFPSPlayerState, m_Ammo);
	DOREPLIFETIME(AFPSPlayerState, m_Gold);
}
//////////////////////////////////////////////////////////////
// 게임 규칙에 따라서 바꿀 수 있는 부분
void AFPSPlayerState::AddDamage(float Damage)
{
	m_CurHp = m_CurHp - Damage;

	OnRep_CurHp();
}
void AFPSPlayerState::AddHeal(float Heal)
{
}

void AFPSPlayerState::SetAmmo(int32 _Ammo)
{
	m_Ammo = _Ammo;
	OnRep_Ammo();
}


void AFPSPlayerState::UseAmmo(int32 _Ammo)
{
	
}

void AFPSPlayerState::SetGold(int32 _Gold)
{
	// 안에 논리는 바뀔 수 있음
	m_Gold += _Gold; // 숫자는 바뀔 수 있음
	
	// 몬스터 잡았을 때 
	OnRep_Gold();
	
}



//////////////////////////////////////////////////////////////////////////////////////
// 다른 시스템과 공유
void AFPSPlayerState::OnRep_CurHp()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("OnRep_CurHp = %f"), m_CurHp));

	if(m_Dele_UpdateHp.IsBound())
		m_Dele_UpdateHp.Broadcast(m_CurHp, 100);
}

void AFPSPlayerState::OnRep_Ammo()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("OnRep_Ammo = %d"), m_Ammo));

	if (m_Dele_UpdateAmmo.IsBound())
		m_Dele_UpdateAmmo.Broadcast(m_Ammo);
}

void AFPSPlayerState::OnRep_Gold()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("OnRep_Gold = %d"), m_Gold));

	if (m_Dele_UpdateGold.IsBound())
		m_Dele_UpdateGold.Broadcast(m_Gold); // 이전에는 m_Dele_UpdateAmmo.Broadcast(m_Gold);
}
