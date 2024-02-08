// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/Store/StoreWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Weapons/WeaponBase.h"
#include "Weapons/Beretta.h"
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
	// pistol ����.
	ABeretta* Pistol = NewObject<ABeretta>(GetOwningPlayer()->GetWorld(), ABeretta::StaticClass());
	AFPSCharacter* Player = Cast<AFPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetOwningPlayer()->GetWorld(), 0));
	AFPSHUD* HUD = Cast<AFPSHUD>(GetOwningPlayer()->GetWorld()->GetFirstPlayerController()->GetHUD());
	// ��尡 ����ϸ� �������� �����ϰ�, �������� ��ȯ
	// �÷��̾� �տ� ������Ű�� 
	FVector SpawnLocation = Player->GetActorLocation() + Player->GetActorForwardVector() * 400.0f; // 100 units in front of the player
	FRotator SpawnRotation = Player->GetActorRotation();
	GetWorld()->SpawnActor<ABeretta>(WeaponClass, SpawnLocation, SpawnRotation);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Pistol Spawned"));
}

