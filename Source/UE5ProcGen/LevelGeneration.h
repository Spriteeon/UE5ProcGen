// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "TerrainGeneration.h"

#include "LevelGeneration.generated.h"

UCLASS()
class UE5PROCGEN_API ALevelGeneration : public AActor
{
	GENERATED_BODY()
	
private:	
	UPROPERTY()
		ATerrainGeneration* terrainGeneration;

	UPROPERTY(EditAnywhere, Category = "Terrain Generation")
		int chunkWidth;
	UPROPERTY(EditAnywhere, Category = "Terrain Generation")
		int chunkDepth;

	UPROPERTY(EditAnywhere, Category = "Terrain Generation")
		int scale;
	UPROPERTY(EditAnywhere, Category = "Terrain Generation")
		int maxHeight;

	UPROPERTY(EditAnywhere, Category = "Terrain Generation")
		TArray<FVector> waves;

	int cubeSize = 100;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Sets default values for this actor's properties
	ALevelGeneration();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void PlaceChunk(FVector spawnLocation);

	bool hasPlaced = false;
	int timer = 0;

};
