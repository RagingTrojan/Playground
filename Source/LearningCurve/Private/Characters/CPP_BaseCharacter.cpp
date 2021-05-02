// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/CPP_BaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

// Sets default values
ACPP_BaseCharacter::ACPP_BaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	SpringArmComp->SetupAttachment(RootComponent);

	ThirdPersonCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("ThirdPersonCameraComp"));
	ThirdPersonCameraComp->SetupAttachment(SpringArmComp);

	FirstPersonCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCameraComp"));
	FirstPersonCameraComp->SetupAttachment(RootComponent);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

	BaseLookRate = 45.0f;
	BaseTurnRate = 45.0f;
}

// Called when the game starts or when spawned
void ACPP_BaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACPP_BaseCharacter::MoveForward(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ACPP_BaseCharacter::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ACPP_BaseCharacter::LookRight(float Value)
{
	if (Value != 0.0f) AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ACPP_BaseCharacter::LookUp(float Value)
{
	if (Value != 0.0f) AddControllerPitchInput(Value * BaseLookRate * GetWorld()->GetDeltaSeconds());
	if (Value < 0.0f) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("LOOKUP! ----"));
	if (Value > 0.0f) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("LOOKUP! ++++"));
	
}


void ACPP_BaseCharacter::Fire()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("FIRE!"));
}

// Called every frame
void ACPP_BaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACPP_BaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ACPP_BaseCharacter::Fire);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPP_BaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPP_BaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookRight", this, &ACPP_BaseCharacter::LookRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ACPP_BaseCharacter::LookUp);
}