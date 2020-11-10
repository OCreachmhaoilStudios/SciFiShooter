// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* pawnKilled)
{
	Super::PawnKilled(pawnKilled);
	
	// UE_LOG(LogTemp, Warning, TEXT("A pawn was killed."));
	
	APlayerController* PlayerController = Cast<APlayerController>(pawnKilled->GetController());
	if(PlayerController != nullptr)
	{
		EndGame(false);
	}
	
	// For loop over ShooterAI in World
	for(AShooterAIController* Controller : TActorRange<AShooterAIController>(GetWorld()))
	{
		if(!Controller->IsDead()) { return; }
	}
	
	// End game
	AKillEmAllGameMode::EndGame(true);
}

void AKillEmAllGameMode::EndGame(bool bIsPlayerWinner)
{
	for(AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);
	}
}
