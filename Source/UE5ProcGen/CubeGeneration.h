// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoiseMapGeneration.h"

#include "CubeGeneration.generated.h"

UCLASS()
class UE5PROCGEN_API ACubeGeneration : public AActor
{
	GENERATED_BODY()

private:
	int chunkWidth = 32;
	int chunkDepth = 32;

	float absoluteChunkWidth;
	float absoluteChunkDepth;

	int cubeSize = 100;

	NoiseMapGeneration noiseMapGeneration;

	TArray<FVector> wavesList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ACubeGeneration();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Cube Spawning")
		void GenerateChunk(FVector chunkCentre);

	UFUNCTION(BlueprintCallable, Category = "Cube Spawning")
		void PlaceCube(FVector spawnLocation);

	UPROPERTY(EditAnywhere)
		TSubclassOf<AActor> cubeClass;

};
