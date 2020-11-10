// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SciFiShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SCIFISHOOTER_API AKillEmAllGameMode : public ASciFiShooterGameModeBase
{
	private:
		void EndGame(bool bIsPlayerWinner);

	GENERATED_BODY()
	
	public:
		virtual void PawnKilled(APawn* pawnKilled) override;
	
	
};
