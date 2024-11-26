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

	absChunkWidth = chunkWidth * cubeSize;
	absChunkDepth = chunkDepth * cubeSize;

	terrainGeneration->Init(cubeSize, chunkWidth, chunkDepth, absChunkWidth, absChunkDepth, scale, maxHeight, waves);

	// Initial Chunk spawnings, only adding this hear as I ran out of time to make a proper Chunk Manager
	chunksCentreLocation = FVector(0.0f, 0.0f, 0.0f);
	for (int x = 0; x < numOfChunksWidth; x++)
	{
		for (int y = 0; y < numOfChunksDepth; y++)
		{
			FVector spawnLocation;
			spawnLocation.X = -(chunksCentreLocation.X + (((absChunkWidth * numOfChunksWidth) - absChunkWidth) / 2)) + (x * absChunkWidth);
			spawnLocation.Y = -(chunksCentreLocation.Y + (((absChunkDepth * numOfChunksDepth) - absChunkDepth) / 2)) + (y * absChunkDepth);
			spawnLocation.Z = 0.0f;

			PlaceChunk(spawnLocation);
		}
	}

}

// Called every frame
void ALevelGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ALevelGeneration::PlaceChunk(FVector spawnLocation)
{
	terrainGeneration->GenerateTerrainChunk(spawnLocation);

	// This is where you would add other stuff to the level, Foliage etc.
}
