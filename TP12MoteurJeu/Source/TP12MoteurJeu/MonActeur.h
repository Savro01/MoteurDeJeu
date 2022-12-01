// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "MonActeur.generated.h"

UCLASS()
class TP12MOTEURJEU_API AMonActeur : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* MonMaillage;

public:
	// Sets default values for this actor's properties
	AMonActeur();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
