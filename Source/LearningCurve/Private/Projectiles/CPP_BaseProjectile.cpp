// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectiles/CPP_BaseProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACPP_BaseProjectile::ACPP_BaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACPP_BaseProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACPP_BaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

