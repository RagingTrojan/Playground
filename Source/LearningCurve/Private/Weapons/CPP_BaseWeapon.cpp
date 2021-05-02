// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/CPP_BaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ACPP_BaseWeapon::ACPP_BaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
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