// This game is the result of a course taken from GameDev.tv. Any quereis about copy right should be taken up with them

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:
	class ATank* Tank;
	class AToonTanksPlayerController* TankPlayerController;
	float StartDelay = 3.f;
	int32 TargetTowers = 0;
	int32 GetTargetTowerCount();

	void HandleGameStart();
};
