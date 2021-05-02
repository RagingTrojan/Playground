// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_BaseWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS()
class LEARNINGCURVE_API ACPP_BaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_BaseWeapon();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh") USkeletalMeshComponent* SkeletalMeshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
