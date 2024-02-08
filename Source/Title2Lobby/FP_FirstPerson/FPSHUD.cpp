// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSHUD.h"

#include "FPSPlayerState.h"
#include "Blueprint/UserWidget.h"
// 로직은 블루프린트에서 최대한 
void AFPSHUD::BeginPlay()
{
	Super::BeginPlay();
	check(HudWidgetClass);

	HudWidget = CreateWidget<UUserWidget>(GetWorld(), HudWidgetClass);
	HudWidget->AddToViewport();

	BindMyPlayerState();
}

void AFPSHUD::BindMyPlayerState()
{
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	if (IsValid(pc))
	{
		AFPSPlayerState* ps = Cast<AFPSPlayerState>(pc->PlayerState);
		if (IsValid(ps))
		{
			ps->m_Dele_UpdateHp.AddDynamic(this, &AFPSHUD::OnUpdateMyHp);
			OnUpdateMyHp(ps->m_CurHp, 100);

			
			ps->m_Dele_UpdateAmmo.AddDynamic(this, &AFPSHUD::OnUpdateMyAmmo);
			OnUpdateMyAmmo(ps->m_Ammo);
			
			ps->m_Dele_UpdateGold.AddDynamic(this, &AFPSHUD::OnUpdateMyGold);
			OnUpdateMyGold(ps->m_Gold);
			
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, TEXT("AShootingHUD Bind Success!"));
			return;
		}
	}

	FTimerManager& timerManger = GetWorld()->GetTimerManager();
	timerManger.SetTimer(th_BindMyPlayerState, this, &AFPSHUD::BindMyPlayerState, 0.01f, false);
}

void AFPSHUD::OnUpdateMyHp_Implementation(float CurHp, float MaxHp)
{
}

void AFPSHUD::OnUpdateMyAmmo_Implementation(int Ammo)
{
}

void AFPSHUD::OnUpdateMyGold_Implementation(int Gold)
{
}
