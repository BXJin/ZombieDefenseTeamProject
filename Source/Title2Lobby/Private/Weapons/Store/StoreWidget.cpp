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
	// WeaponBase�� ������ Ȯ���ϰ�, ��尡 ����ϸ� ����
	// Weaponbase ����.
	AWeaponBase* Weapon = GetWorld()->SpawnActor<AWeaponBase>(WeaponClass, FVector::ZeroVector, FRotator::ZeroRotator);
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());
	
	///
	Weapon->AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "WeaponSocket");
	
// ��尡 �����ϸ� ���� ���� �޽��� ���
// ���� ���� �޽����� HUD�� ���
// ���� ���� �޽����� HUD�� ���
// ���� ������, �������� ��ȯ
// ���� ������, ��带 ����

	// ��尡 ����ϸ� �������� �����ϰ�, �������� ��ȯ
}

