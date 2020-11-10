// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SciFiShooterPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SCIFISHOOTER_API ASciFiShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void BeginPlay() override;
	
	public:
		virtual void GameHasEnded(class AActor* EndGameFocus, bool bIsWinner) override;
	
	private:
		UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> MainHUDClass;
		
		UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> LoseScreenClass;
		
		UPROPERTY(EditAnywhere)
		TSubclassOf<class UUserWidget> WinScreenClass;
		
		UPROPERTY(EditAnywhere)
		float RestartDelay = 5.0f;
		
		FTimerHandle RestartTimer;
		
		UPROPERTY()
		UUserWidget* MainHUD;
};
