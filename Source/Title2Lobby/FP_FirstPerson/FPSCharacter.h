// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class TITLE2LOBBY_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()
protected:
	// 1인칭 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="FPSCamera")
	UCameraComponent* FirstPersonCamera;

	// 키입력
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* MoveInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* LookInputAction;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* JumpInputAction;
	
	UPROPERTY(EditDefaultsOnly, Category = Input)
	UInputAction* FireInputAction;
public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	// 키입력 함수
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void StartFire(const FInputActionValue& Value);
	void StopFire(const FInputActionValue& Value);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category="Weapon")
	void Fire();

	// 서버에서 실행될 발사 로직
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerFire();
	bool ServerFire_Validate();
	void ServerFire_Implementation();
protected:
	// 완성본에서는 weapon에서 실행
	// 실제 라인 트레이스를 수행하는 함수
	void PerformLineTrace();
};
