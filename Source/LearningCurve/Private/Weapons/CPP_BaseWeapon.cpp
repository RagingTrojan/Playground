// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/CPP_BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Controller.h"
#include "Components/BillboardComponent.h"
#include "Interfaces/CCP_Interface.h"
#include "Projectiles/CPP_BaseProjectile.h"

// Sets default values
ACPP_BaseWeapon::ACPP_BaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	SkeletalMeshComp->SetupAttachment(RootComponent);

	FirePoint = CreateDefaultSubobject<UBillboardComponent>(TEXT("FirePoint"));
	FirePoint->SetupAttachment(SkeletalMeshComp);
}

// Called when the game starts or when spawned
void ACPP_BaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACPP_BaseWeapon::Fire()
{
	GetWorld()->SpawnActor<ACPP_BaseProjectile>(Projectile, FirePoint->GetComponentLocation(), FirePoint->GetComponentRotation());
}

void ACPP_BaseWeapon::StartFiring(float Value)
{
	GetWorldTimerManager().SetTimer(Handle_Fire, this, &ACPP_BaseWeapon::Fire, Value, true);
}

void ACPP_BaseWeapon::StopFiring()
{
	GetWorldTimerManager().ClearTimer(Handle_Fire);
}