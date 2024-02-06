// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSCharacter.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AFPSCharacter::AFPSCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	// 3인칭 메시 1인칭 머리에 카메라 
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	FirstPersonCamera->bUsePawnControlRotation = true;
	FirstPersonCamera->SetupAttachment(GetMesh(), FName("head"));
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();

	if(InputValue.X != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), InputValue.X);
	}

	if(InputValue.Y != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), InputValue.Y);	
	}
}

void AFPSCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D InputValue = Value.Get<FVector2D>();

	if(InputValue.X != 0.0f)
	{
		AddControllerYawInput(InputValue.X);
	}

	if(InputValue.Y != 0.0f)
	{
		AddControllerPitchInput(InputValue.Y);	
	}
}

void AFPSCharacter::StartFire(const FInputActionValue& Value)
{
	Fire();
}

void AFPSCharacter::StopFire(const FInputActionValue& Value)
{
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedPlayerInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	const APlayerController* PlayerController = Cast<APlayerController>(GetController());

	if (EnhancedPlayerInputComponent == nullptr || PlayerController == nullptr)
	{
		return;
	}
	
	UEnhancedInputLocalPlayerSubsystem* EnhancedSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	if(EnhancedSubsystem == nullptr)
	{
		return;
	}

	EnhancedSubsystem->AddMappingContext(InputMappingContext, 1);

	EnhancedPlayerInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Move);
	EnhancedPlayerInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &AFPSCharacter::Look);
	EnhancedPlayerInputComponent->BindAction(JumpInputAction, ETriggerEvent::Started, this, &ACharacter::Jump);
	EnhancedPlayerInputComponent->BindAction(FireInputAction, ETriggerEvent::Started, this, &AFPSCharacter::StartFire);
	EnhancedPlayerInputComponent->BindAction(FireInputAction, ETriggerEvent::Completed, this, &AFPSCharacter::StopFire);
}

void AFPSCharacter::Fire()
{
	if (HasAuthority()) {
		PerformLineTrace();
	} else {
		ServerFire();
	}
}

bool AFPSCharacter::ServerFire_Validate()
{
	return true;
}

void AFPSCharacter::ServerFire_Implementation()
{
	PerformLineTrace();
}

void AFPSCharacter::PerformLineTrace()
{
	
	FVector EyeLocation;
	FRotator EyeRotation;
	GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector TraceEnd = EyeLocation + (EyeRotation.Vector() * 10000);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this); // 자기 자신은 무시
	QueryParams.bTraceComplex = true;

	if (GetWorld()->LineTraceSingleByChannel(HitResult, EyeLocation, TraceEnd, ECC_Visibility, QueryParams)) {
		// 히트 이벤트 처리
		AActor* HitActor = HitResult.GetActor();
		// HitActor에 대한 처리 로직 추가
		// 데미지 떨어지는 로직 추가
	}
	// 라인트레이스 시각화
	if (GetWorld())
	{
		DrawDebugLine(GetWorld(),EyeLocation,TraceEnd,FColor::Red,false,1.0f, 0, 1.0f);
	}
}

