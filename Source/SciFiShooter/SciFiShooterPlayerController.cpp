// Fill out your copyright notice in the Description page of Project Settings.


#include "SciFiShooterPlayerController.h"
#include "TimerManager.h"
#include "Blueprint/UserWidget.h"

void ASciFiShooterPlayerController::GameHasEnded(class AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	//UE_LOG(LogTemp, Warning, TEXT("Game is over"));
	
	MainHUD->RemoveFromViewport();
	
	if(bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinScreenClass);
		
		if(WinScreen != nullptr)
		{
			WinScreen->AddToViewport();
		}	
	}
	else
	{
		UUserWidget* LoseScreen = CreateWidget(this, LoseScreenClass);
		if(LoseScreen != nullptr)
		{
			LoseScreen->AddToViewport();
		}
	}
	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}

void ASciFiShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	MainHUD = CreateWidget(this, MainHUDClass);
		
	if(MainHUD!= nullptr)
	{
		MainHUD->AddToViewport();
	}	
}
