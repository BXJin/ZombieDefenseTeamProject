// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Store/StoreWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Weapons/WeaponBase.h"
#include "Weapons/Beretta.h"
#include "Weapons/Thompson.h"
#include "Weapons/AK47.h"
#include "Items/ItemBase.h"
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

	// WeaponBase�� WeaponPrice�� �����ͼ� PlayerState�� Gold�� ��
	if (PlayerState->m_Gold < Pistol->WeaponPrice)
	{
		// ���� ���� �޼����� ���� ���
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

	// WeaponBase�� WeaponPrice�� �����ͼ� PlayerState�� Gold�� ��
	if (PlayerState->m_Gold < Thompson->WeaponPrice)
	{
		// ���� ���� �޼����� ���� ���
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
	AAK47* AK47 = NewObject<AAK47>(GetOwningPlayer()->GetWorld(), AAK47::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

	// WeaponBase�� WeaponPrice�� �����ͼ� PlayerState�� Gold�� ��
	if (PlayerState->m_Gold < AK47->WeaponPrice)
	{
		// ���� ���� �޼����� ���� ���
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
			PC->ServerBuyAK47();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("PC is not valid"));
		}

		PlayerState->m_Gold -= AK47->WeaponPrice;
		PlayerState->OnRep_Gold();
	}
}

void UStoreWidget::BuyButton_M4()
{
}

void UStoreWidget::BuyButton_Med()
{
	AItemBase* Medipack = NewObject<AItemBase>(GetOwningPlayer()->GetWorld(), AItemBase::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

	// WeaponBase�� WeaponPrice�� �����ͼ� PlayerState�� Gold�� ��
	if (PlayerState->m_Gold < Medipack->MedItemPrice)
	{
		// ���� ���� �޼����� ���� ���
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
			PC->ServerBuyMedItem();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("PC is not valid"));
		}

		PlayerState->m_Gold -= Medipack->MedItemPrice;
		PlayerState->OnRep_Gold();
	}
}

void UStoreWidget::BuyButton_Ammo()
{
	AItemBase* Ammopack = NewObject<AItemBase>(GetOwningPlayer()->GetWorld(), AItemBase::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

	// WeaponBase�� WeaponPrice�� �����ͼ� PlayerState�� Gold�� ��
	if (PlayerState->m_Gold < Ammopack->MedItemPrice)
	{
		// ���� ���� �޼����� ���� ���
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
			PC->ServerBuyMag();
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("PC is not valid"));
		}

		PlayerState->m_Gold -= Ammopack->MedItemPrice;
		PlayerState->OnRep_Gold();
	}
}

