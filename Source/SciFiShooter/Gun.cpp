// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	FHitResult hit;
	FVector shotDirection;
	bool bSuccess = GunTrace(hit, shotDirection);
	if(bSuccess)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), impactFX, hit.Location, shotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), impactSoundFX, hit.Location, shotDirection.Rotation());
		AActor* hitActor = hit.GetActor();
		
		if(hitActor != nullptr)
		{
			FPointDamageEvent damageEvent(Damage, hit, shotDirection, nullptr);
			AController* OwnerController = GetOwnerController();
			hitActor->TakeDamage(Damage, damageEvent, OwnerController, this);
		}
	}
}

bool AGun::GunTrace(FHitResult& hit, FVector& shotDirection)
{
	AController* OwnerController = GetOwnerController();
	if(OwnerController == nullptr) { return false; }
	
	FVector location;
	FRotator rotation;
	OwnerController->GetPlayerViewPoint(location, rotation);
	
	shotDirection = -rotation.Vector();
	
	FVector End = location + rotation.Vector() * MaxRange;
		
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(GetOwner());
	
	return GetWorld()->LineTraceSingleByChannel(hit, location, End, ECollisionChannel::ECC_GameTraceChannel1, params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if(OwnerPawn == nullptr) { return nullptr; }
	
	return OwnerPawn->GetController();
}
