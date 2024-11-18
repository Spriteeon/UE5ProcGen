// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeGeneration.h"

// Sets default values
ACubeGeneration::ACubeGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absoluteChunkWidth = chunkWidth * cubeSize;
	absoluteChunkDepth = chunkDepth * cubeSize;

	wavesList = { FVector(5297.0f,1.0f,1.0f),FVector(8452.0f,0.5f,2.0f) ,FVector(5932.0f,0.25f,4.0f) };
}

// Called when the game starts or when spawned
void ACubeGeneration::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACubeGeneration::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACubeGeneration::GenerateChunk(FVector chunkCentre)
{
	int scale = 11;
	int maxHeight = 10;

	float offsetX = -(chunkCentre.X / cubeSize);
	float offsetY = -(chunkCentre.Y / cubeSize);

	std::vector<std::vector<float>> noiseMap = noiseMapGeneration.GeneratePerlinNoiseMap(chunkWidth, chunkDepth, scale, offsetX, offsetY, wavesList);

	for (int x = 0; x < chunkWidth; x++)
	{
		for (int y = 0; y < chunkDepth; y++)
		{
			FVector spawnLocation;
			spawnLocation.X = -(chunkCentre.X + ((absoluteChunkWidth - cubeSize) / 2)) + (x * cubeSize);
			spawnLocation.Y = -(chunkCentre.Y + ((absoluteChunkDepth - cubeSize) / 2)) + (y * cubeSize);

			// Calculate Cube Heights, needs to be multiples of cubeSize, noiseMap values are currently between 0 and 1
			spawnLocation.Z = std::round(noiseMap[x][y] * maxHeight) * cubeSize;

			/*if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Cube Height: %f"), spawnLocation.Z));*/

			PlaceCube(spawnLocation);
		}
	}
}

void ACubeGeneration::PlaceCube(FVector spawnLocation)
{
	FTransform spawnTransform;
	spawnTransform.SetLocation(spawnLocation);

	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	GetWorld()->SpawnActor<AActor>(cubeClass, spawnTransform, spawnParams);
}
