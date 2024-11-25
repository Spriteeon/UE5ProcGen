// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelGeneration.h"

// Sets default values
ALevelGeneration::ALevelGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	terrainGeneration = CreateDefaultSubobject<ATerrainGeneration>(TEXT("Terrain Generation"));
}

// Called when the game starts or when spawned
void ALevelGeneration::BeginPlay()
{
	Super::BeginPlay();

	terrainGeneration->Init(cubeSize, chunkWidth, chunkDepth, scale, maxHeight, waves);
}

// Called every frame
void ALevelGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	timer++;
	if (timer > 5 && !hasPlaced)
	{
		PlaceChunk(FVector(0.0f, 0.0f, 0.0f));
		hasPlaced = true;
	}

}

void ALevelGeneration::PlaceChunk(FVector spawnLocation)
{
	terrainGeneration->GenerateTerrainChunk(spawnLocation);
}
