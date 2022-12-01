// Fill out your copyright notice in the Description page of Project Settings.


#include "MonActeur.h"

int myVar = 5;

// Sets default values
AMonActeur::AMonActeur()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MonMaillage = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MonMaillage->SetupAttachment(RootComponent);
	ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	ConstructorHelpers::FObjectFinder<UMaterial> material(TEXT("/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak"));
	if (CubeVisualAsset.Succeeded() && material.Succeeded()) {
		MonMaillage->SetStaticMesh(CubeVisualAsset.Object);
		MonMaillage->SetMaterial(0,material.Object);
		MonMaillage->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AMonActeur::BeginPlay()
{
	Super::BeginPlay();
	FString nom = *this->GetName();
	UE_LOG(LogActor, Warning, TEXT("Mon nom est %s"), *nom);
	UE_LOG(LogActor, Warning, TEXT("Ma variable est %d"), myVar);

}

// Called every frame
void AMonActeur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 100.0f;

	SetActorLocation(NewLocation);

}

