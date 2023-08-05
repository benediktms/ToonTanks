// This game is the result of a course taken from GameDev.tv. Any quereis about copy right should be taken up with them


#include "ToonTanksGameMode.h"
#include "Tank.h"
#include "ToonTanksPlayerController.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
}


void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (TankPlayerController)
		{
			TankPlayerController->SetPlayerEnabledState(false);
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}

void AToonTanksGameMode::HandleGameStart()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
	TankPlayerController = Cast<AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	if (TankPlayerController)
	{
		TankPlayerController->SetPlayerEnabledState(false);
		FTimerHandle PlayerEnabledTimerHandle;
		FTimerDelegate PlayerEnabledDelegate = FTimerDelegate::CreateUObject(
			TankPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true
		);
		GetWorldTimerManager().SetTimer(
			PlayerEnabledTimerHandle,
			PlayerEnabledDelegate,
			StartDelay,
			false
		);
	}
}
