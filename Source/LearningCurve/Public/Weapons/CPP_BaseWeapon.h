// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "CPP_BaseWeapon.generated.h"

class USkeletalMeshComponent;
class UBillboardComponent;
class ACPP_BaseProjectile;

UCLASS()
class LEARNINGCURVE_API ACPP_BaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_BaseWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh") USkeletalMeshComponent* SkeletalMeshComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FirePoint") UBillboardComponent* FirePoint;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "FireRate") float FireRate;
	UPROPERTY(EditAnywhere, Category = "Projectile") TSubclassOf<class ACPP_BaseProjectile> Projectile;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void StartFiring(float Value);
	void StopFiring();
	void Fire();

	FTimerHandle Handle_Fire;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};