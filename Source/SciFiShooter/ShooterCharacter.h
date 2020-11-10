// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class SCIFISHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AShooterCharacter();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// Take damage
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
	
	UFUNCTION(BlueprintPure)
	virtual bool IsDead() const;
	
	UFUNCTION(BlueprintPure)
	virtual float GetHealthPercent() const;

	// Fire weapon
	void FireMain();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Move Forward and Backward
	void MoveForward(float AxisValue);
	// Strafe Left and Right
	void StrafeRight(float AxisValue);
	//  LookUpRate
	void LookUpRate(float AxisValue);
	// LookRightRate
	void LookRightRate(float AxisValue);
	
	UPROPERTY(EditAnywhere)
	float RotationRate = 10;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;
	
	UPROPERTY()
	AGun* Gun;
	
	UPROPERTY(EditDefaultsOnly)
	float MaxHealth {100.0f};
	
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth{};
};
