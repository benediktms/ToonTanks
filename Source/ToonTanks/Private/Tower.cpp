// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	GetWorldTimerManager().SetTimer(
		FireRateTimerHandle,
		this,
		&ATower::CheckFireCondition,
		FireRate,
		true
	);
}


bool ATower::CheckIsInRange() const
{
	if (Tank)
	{
		const float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		return Distance <= FireRange;
	}

	return false;
}

void ATower::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (CheckIsInRange())
	{
		RotateTurret(Tank->GetActorLocation());
	};
}

void ATower::CheckFireCondition()
{
	if (Tank == nullptr)
	{
		return;
	}
	if (Tank->bAlive && CheckIsInRange())
	{
		Fire();
	}
}

void ATower::HandleDestruction()
{
	Super::HandleDestruction();
	Destroy();
}
