// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SCIFISHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	
	void PullTrigger();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
		UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;
		
		UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;
		
		UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;
		
		UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;
		
		UPROPERTY(EditAnywhere)
		float MaxRange{1000};

		UPROPERTY(EditAnywhere)
		UParticleSystem* impactFX;

		UPROPERTY(EditAnywhere)
		USoundBase* impactSoundFX;
		
		UPROPERTY(EditAnywhere)
		float Damage {10};
		
		bool GunTrace(FHitResult& hit, FVector& shotDirection);
		
		AController* GetOwnerController() const;
};