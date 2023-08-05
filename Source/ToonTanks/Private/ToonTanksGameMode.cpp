// This game is the result of a course taken from GameDev.tv. Any quereis about copy right should be taken up with them


#include "ToonTanksGameMode.h"
#include "Tank.h"
#include "Tower.h"
#include "Kismet/GameplayStatics.h"

void AToonTanksGameMode::BeginPlay()
{
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}


void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (APlayerController* TankPlayerController = Tank->GetTankPlayerController())
		{
			Tank->DisableInput(TankPlayerController);
			TankPlayerController->bShowMouseCursor = false;
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();
	}
}
