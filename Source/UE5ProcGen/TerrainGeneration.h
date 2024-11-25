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
	int chunkWidth;
	int chunkDepth;
	float absoluteChunkWidth;
	float absoluteChunkDepth;

	int cubeSize;

	int scale;
	int maxHeight;

	UPROPERTY()
		UNoiseMapGeneration* noiseMapGeneration;
	
	UPROPERTY()
		UCurveFloat* terrainHeightCurve;

	TArray<FVector> waves;
	TSubclassOf<AActor> cubeClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ATerrainGeneration();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init(int _cubeSize, int _chunkWidth, int _chunkDepth, int _scale, int _maxHeight, TArray<FVector> _waves = {});

	UFUNCTION(BlueprintCallable, Category = "Cube Chunk Spawning")
		void GenerateTerrainChunk(FVector chunkCentre);
	UFUNCTION(BlueprintCallable, Category = "Cube Spawning")
		void PlaceCube(FVector spawnLocation);

};
