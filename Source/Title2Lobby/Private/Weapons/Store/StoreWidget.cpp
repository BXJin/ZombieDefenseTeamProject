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

void UStoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UStoreWidget::BuyButton_Pistol_Implementation()
{
	ABeretta* Pistol = NewObject<ABeretta>(GetOwningPlayer()->GetWorld(), ABeretta::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

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
		FVector SpawnLocation = Player->GetActorLocation() + Player->GetActorForwardVector() * 200.0f; // 100 units in front of the player
		FRotator SpawnRotation = Player->GetActorRotation();

		GetWorld()->SpawnActor<ABeretta>(PistolClass, SpawnLocation, SpawnRotation);

		PlayerState->m_Gold -= Pistol->WeaponPrice;
		PlayerState->OnRep_Gold();
	}
}


void UStoreWidget::BuyButton_Pistol_Client_Implementation()
{

}

void UStoreWidget::BuyButton_Thompson()
{
	AThompson* Thompson = NewObject<AThompson>(GetOwningPlayer()->GetWorld(), AThompson::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSPlayerState* PlayerState = Cast<AFPSPlayerState>(Player->GetPlayerState());
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());

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
		FVector SpawnLocation = Player->GetActorLocation() + Player->GetActorForwardVector() * 200.0f; // 100 units in front of the player
		FRotator SpawnRotation = Player->GetActorRotation();

		GetWorld()->SpawnActor<AThompson>(ThompsonClass, SpawnLocation, SpawnRotation);

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

