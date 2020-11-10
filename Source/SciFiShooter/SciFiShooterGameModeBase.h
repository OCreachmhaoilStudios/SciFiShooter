// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/Pawn.h"
#include "SciFiShooterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SCIFISHOOTER_API ASciFiShooterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	public:
		virtual void PawnKilled(APawn* pawnKilled);
};
