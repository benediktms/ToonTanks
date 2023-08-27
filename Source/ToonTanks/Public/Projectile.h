// This game is the result of a course taken from GameDev.tv. Any quereis about copy right should be taken up with them

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Mesh")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category="Movement")
	float InitialProjectileSpeed = 1300.f;

	UPROPERTY(EditAnywhere, Category="Movement")
	float ProjectileMaxSpeed = 1300.f;

	UPROPERTY(EditAnywhere, Category="Combat")
	float Damage = 50.f;

	// Multi cast delegate
	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
	);

	UPROPERTY(EditAnywhere, Category="Combat")
	class UParticleSystem* HitParticles;
};
