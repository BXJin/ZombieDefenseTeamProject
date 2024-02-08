// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSPlayerState.h"
#include "Net/UnrealNetwork.h"
AFPSPlayerState::AFPSPlayerState() : m_CurHp(100), m_Ammo(30), m_Gold(1000)
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
void AFPSPlayerState::AddAmmo()
{
	// 안에 논리는 바뀔 수 있음
	m_Ammo = m_Ammo + 1; // 숫자는 바뀔 수 있음

	OnRep_Ammo();
}

void AFPSPlayerState::UseAmmo()
{
}

void AFPSPlayerState::AddGold()
{
	// 안에 논리는 바뀔 수 있음
	m_Gold = m_Gold + 100; // 숫자는 바뀔 수 있음

	OnRep_Gold();
}

void AFPSPlayerState::UseGold()
{
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
		m_Dele_UpdateAmmo.Broadcast(m_Gold);
}
