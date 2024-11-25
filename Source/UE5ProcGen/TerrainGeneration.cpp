// Fill out your copyright notice in the Description page of Project Settings.

#include "TerrainGeneration.h"

// Sets default values
ATerrainGeneration::ATerrainGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absoluteChunkWidth = chunkWidth * cubeSize;
	absoluteChunkDepth = chunkDepth * cubeSize;

	scale = 11;
	maxHeight = 30;

	wavesList = { FVector(5297.0f,1.0f,1.0f),FVector(8452.0f,0.5f,2.0f) ,FVector(5932.0f,0.25f,4.0f) };

	noiseMapGeneration = NewObject<NoiseMapGeneration>();
}

// Called when the game starts or when spawned
void ATerrainGeneration::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATerrainGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATerrainGeneration::GenerateChunk(FVector chunkCentre)
{
	float offsetX = -(chunkCentre.X / cubeSize);
	float offsetY = -(chunkCentre.Y / cubeSize);

	noiseMapGeneration->GeneratePerlinNoiseMap(chunkWidth, chunkDepth, scale, offsetX, offsetY, wavesList);

	//int numCubes = 0;

	for (int x = 0; x < chunkWidth; x++)
	{
		for (int y = 0; y < chunkDepth; y++)
		{
			FVector spawnLocation;
			spawnLocation.X = -(chunkCentre.X + ((absoluteChunkWidth - cubeSize) / 2)) + (x * cubeSize);
			spawnLocation.Y = -(chunkCentre.Y + ((absoluteChunkDepth - cubeSize) / 2)) + (y * cubeSize);

			// Calculate Cube Heights, needs to be multiples of cubeSize, noiseMap values are currently between 0 and 1
			int cubeLevel = std::round(terrainHeightCurve->GetFloatValue(noiseMapGeneration->GetNoiseValue(x, y)) * maxHeight);
			spawnLocation.Z = cubeLevel * cubeSize;

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Cube Surface Height: %f"), spawnLocation.Z));

			// Loop for placing cubes underneath the surface cubes, down to height Z = 0
			for (int i = cubeLevel; i >= 0; i--)
			{
				PlaceCube(spawnLocation);
				spawnLocation.Z -= cubeSize;
				//numCubes++;
			}
		}
	}

	/*if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Cube Height: %i"), numCubes));*/

}

void ATerrainGeneration::PlaceCube(FVector spawnLocation)
{
	FTransform spawnTransform;
	spawnTransform.SetLocation(spawnLocation);

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(cubeClass, spawnTransform, spawnParams);
}
