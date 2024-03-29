// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();

protected:
	void RotateTurret(FVector LookAtTarget);
	void Fire();
	void HandleDestruction();

private:
	UPROPERTY(
		meta=(AllowPrivateAccess = "true"),
		VisibleAnywhere,
		BlueprintReadOnly,
		Category= "Components"
	)
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(
		meta = (AllowPrivateAccess = "true"),
		VisibleAnywhere,
		BlueprintReadWrite,
		Category = "Components"
	)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(
		meta = (AllowPrivateAccess = "true"),
		VisibleAnywhere,
		BlueprintReadWrite,
		Category = "Components"
	)
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(
		meta = (AllowPrivateAccess = "true"),
		VisibleAnywhere,
		BlueprintReadWrite,
		Category = "Components"
	)
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditAnywhere, Category="Turret")
	float TurretRotationSpeed = 15.f;

	UPROPERTY(EditDefaultsOnly, Category="Projectile")
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category="Combat")
	class USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category="Combat")
	TSubclassOf<class UCameraShakeBase> DeathCameraShakeClass;
};
