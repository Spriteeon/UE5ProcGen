// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeGeneration.h"

// Sets default values
ACubeGeneration::ACubeGeneration()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	absoluteChunkWidth = chunkWidth * cubeSize;
	absoluteChunkDepth = chunkDepth * cubeSize;

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
	for (int x = 0; x < chunkWidth; x++)
	{
		for (int y = 0; y < chunkDepth; y++)
		{
			FVector spawnLocation;
			spawnLocation.X = -(chunkCentre.X + ((absoluteChunkWidth - cubeSize) / 2)) + (x * cubeSize);
			spawnLocation.Y = -(chunkCentre.Y + ((absoluteChunkDepth - cubeSize) / 2)) + (y * cubeSize);

			spawnLocation.Z = FMath::RandRange(-1, 1) * cubeSize;

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
