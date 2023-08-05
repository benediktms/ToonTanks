// This game is the result of a course taken from GameDev.tv. Any quereis about copy right should be taken up with them

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ToonTanksPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool bPlayerEnabled);
};
