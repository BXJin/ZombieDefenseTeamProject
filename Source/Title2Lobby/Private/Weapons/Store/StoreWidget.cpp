// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Store/StoreWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Weapons/WeaponBase.h"
#include "Weapons/Beretta.h"
#include "Weapons/Thompson.h"
#include "Weapons/AK47.h"
#include "FP_FirstPerson/FPSCharacter.h"
#include "FP_FirstPerson/FPSPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "FP_FirstPerson/FPSHUD.h"
#include "Game/GamePlayPC.h"

void UStoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UStoreWidget::BuyButton_Pistol()
{
	ABeretta* Pistol = NewObject<ABeretta>(GetOwningPlayer()->GetWorld(), ABeretta::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

	// WeaponBase의 WeaponPrice를 가져와서 PlayerState의 Gold와 비교
	if (PlayerState->m_Gold < Pistol->WeaponPrice)
	{
		// 구매 실패 메세지와 사운드 출력
		//HUD->ShowMessage("Not enough gold", 2.0f);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Not enough gold"));
		UGameplayStatics::PlaySound2D(GetOwningPlayer()->GetWorld(), FailedSound);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Buy"));
		UGameplayStatics::PlaySound2D(GetOwningPlayer()->GetWorld(), BuySound);

		AGamePlayPC* PC = Cast<AGamePlayPC>(GetOwningPlayer());
		if (PC)
		{
			PC->ServerBuyPistol();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("PC is not valid"));
		}

		PlayerState->m_Gold -= Pistol->WeaponPrice;
		PlayerState->OnRep_Gold();
	}
}

void UStoreWidget::BuyButton_Thompson()
{
	AThompson* Thompson = NewObject<AThompson>(GetOwningPlayer()->GetWorld(), AThompson::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

	// WeaponBase의 WeaponPrice를 가져와서 PlayerState의 Gold와 비교
	if (PlayerState->m_Gold < Thompson->WeaponPrice)
	{
		// 구매 실패 메세지와 사운드 출력
		//HUD->ShowMessage("Not enough gold", 2.0f);
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Not enough gold"));
		UGameplayStatics::PlaySound2D(GetOwningPlayer()->GetWorld(), FailedSound);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("Buy"));
		UGameplayStatics::PlaySound2D(GetOwningPlayer()->GetWorld(), BuySound);

		AGamePlayPC* PC = Cast<AGamePlayPC>(GetOwningPlayer());
		if (PC)
		{
			PC->ServerBuyThompson();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("PC is not valid"));
		}

		PlayerState->m_Gold -= Thompson->WeaponPrice;
		PlayerState->OnRep_Gold();
	}
}

void UStoreWidget::BuyButton_AK47()
{
}

void UStoreWidget::BuyButton_M4()
{
}

