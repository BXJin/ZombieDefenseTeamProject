// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Store/StoreWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Weapons/WeaponBase.h"
#include "FP_FirstPerson/FPSCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "FP_FirstPerson/FPSHUD.h"

void UStoreWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UStoreWidget::OnBuyButtonClicked()
{
	// WeaponBase의 가격을 확인하고, 골드가 충분하면 구매
	// Weaponbase 스폰.
	AWeaponBase* Weapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponClass, FVector::ZeroVector, FRotator::ZeroRotator);
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());
	
	///
	Weapon->AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "WeaponSocket");
	
// 골드가 부족하면 구매 실패 메시지 출력
// 구매 실패 메시지는 HUD에 출력
// 구매 성공 메시지는 HUD에 출력
// 구매 성공시, 아이템을 소환
// 구매 성공시, 골드를 차감

	// 골드가 충분하면 아이템을 구매하고, 아이템을 소환
}

