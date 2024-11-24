// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NoiseMapGeneration.h"

#include "TerrainGeneration.generated.h"

UCLASS()
class UE5PROCGEN_API ATerrainGeneration : public AActor
{
	GENERATED_BODY()

private:
	int chunkWidth = 16;
	int chunkDepth = 16;
	float absoluteChunkWidth;
	float absoluteChunkDepth;

	int cubeSize = 100;

	int scale;
	int maxHeight;

	NoiseMapGeneration noiseMapGeneration;
	TArray<FVector> wavesList;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	ATerrainGeneration();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Cube Chunk Spawning")
		void GenerateChunk(FVector chunkCentre);
	UFUNCTION(BlueprintCallable, Category = "Cube Spawning")
		void PlaceCube(FVector spawnLocation);

	UPROPERTY(EditAnywhere, Category = "Cube Spawning")
		TSubclassOf<AActor> cubeClass;
	UPROPERTY(EditAnywhere, Category = "Cube Spawning")
		UCurveFloat* terrainHeightCurve;

};
