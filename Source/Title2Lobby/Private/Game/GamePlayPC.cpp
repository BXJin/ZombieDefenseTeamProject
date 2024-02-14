// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/GamePlayPC.h"
#include "Weapons/WeaponBase.h"
#include "Weapons/Beretta.h"
#include "Weapons/Thompson.h"
#include "Weapons/AK47.h"
#include "Items/ItemBase.h"
#include "FP_FirstPerson/FPSCharacter.h"
#include "FP_FirstPerson/FPSPlayerState.h"
#include "Kismet/GameplayStatics.h"

void AGamePlayPC::ServerBuyPistol_Implementation()
{
	AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	if (pCharacter)
	{
		// 스폰시키기
		// 스폰위치
		FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;

		// pCharacter의 회전 값을 가져옵니다.
		FRotator SpawnedRotation = pCharacter->GetActorRotation();

		ABeretta* PCPistol = GetWorld()->SpawnActor<ABeretta>(PistolClass, SpawnedLocation, SpawnedRotation);

	}
}

void AGamePlayPC::ServerBuyThompson_Implementation()
{
	AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	if (pCharacter)
	{
		// 스폰시키기
		// 스폰위치
		FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;

		// pCharacter의 회전 값을 가져옵니다.
		FRotator SpawnedRotation = pCharacter->GetActorRotation();

		AThompson* PCThompson = GetWorld()->SpawnActor<AThompson>(ThompsonClass, SpawnedLocation, SpawnedRotation);

	}
}

void AGamePlayPC::ServerBuyAK47_Implementation()
{
	AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	if (pCharacter)
	{
		// 스폰시키기
		// 스폰위치
		FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;

		// pCharacter의 회전 값을 가져옵니다.
		FRotator SpawnedRotation = pCharacter->GetActorRotation();

		AAK47* PCAK47 = GetWorld()->SpawnActor<AAK47>(AK47Class, SpawnedLocation, SpawnedRotation);

	}
}

void AGamePlayPC::ServerBuyM4_Implementation()
{
	//AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	//if (pCharacter)
	//{
	//	// 스폰시키기
	//	// 스폰위치
	//	FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;
	//
	//	// pCharacter의 회전 값을 가져옵니다.
	//	FRotator SpawnedRotation = pCharacter->GetActorRotation();
	//
	//	ABeretta* PCPistol = GetWorld()->SpawnActor<ABeretta>(PistolClass, SpawnedLocation, SpawnedRotation);
	//
	//}
}

void AGamePlayPC::ServerBuyMag_Implementation()
{
	AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	if (pCharacter)
	{
		// 스폰시키기
		// 스폰위치
		FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;

		// pCharacter의 회전 값을 가져옵니다.
		FRotator SpawnedRotation = pCharacter->GetActorRotation();

		AItemBase* PCMag = GetWorld()->SpawnActor<AItemBase>(MagClass, SpawnedLocation, SpawnedRotation);

	}
}

void AGamePlayPC::ServerBuyMedItem_Implementation()
{
	AFPSCharacter* pCharacter = Cast<AFPSCharacter>(GetPawn());
	if (pCharacter)
	{
		// 스폰시키기
		// 스폰위치
		FVector SpawnedLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 100;

		// pCharacter의 회전 값을 가져옵니다.
		FRotator SpawnedRotation = pCharacter->GetActorRotation();

		//AItemBase* PCMedItem = GetWorld()->SpawnActor<AItemBase>(MedItemClass, SpawnedLocation, SpawnedRotation);

		// 만약 앞에 스폰된 아이템이 있다면 옆에서 스폰

		FVector CheckLocation = pCharacter->GetActorLocation() + pCharacter->GetActorForwardVector() * 200; // Change the distance as needed
		FHitResult HitResult;
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(pCharacter); // Ignore the character itself

		bool bHasHit = GetWorld()->LineTraceSingleByChannel(HitResult, CheckLocation, CheckLocation + (pCharacter->GetActorForwardVector() * 100), ECC_WorldDynamic, Params);

		if (bHasHit)
		{
			SpawnedLocation = HitResult.ImpactPoint + (HitResult.ImpactNormal * 250); // Adjust the spawn location next to the hit item
		}

		AItemBase* PCMedItem = GetWorld()->SpawnActor<AItemBase>(MedItemClass, SpawnedLocation, SpawnedRotation);

	}
}
