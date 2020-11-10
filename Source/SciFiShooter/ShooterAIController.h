// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SCIFISHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	private:
		UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;
		
	protected:
		virtual void BeginPlay() override;
		
	public:
	// Called every frame
	// virtual void Tick(float DeltaTime) override;
	bool IsDead() const;
};
