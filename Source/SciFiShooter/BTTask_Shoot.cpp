// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterCharacter.h"
#include "BTTask_Shoot.h"
#include "AIController.h"

UBTTask_Shoot::UBTTask_Shoot()
{
	NodeName = TEXT("Shoot");
}

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	
	if(OwnerComp.GetAIOwner() == nullptr) { return EBTNodeResult::Failed; }
	AShooterCharacter* Character = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if(Character == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	else
	{
		Character->FireMain();
		return EBTNodeResult::Succeeded;
	}
}
