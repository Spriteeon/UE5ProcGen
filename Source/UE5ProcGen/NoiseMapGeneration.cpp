// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/UnrealMathUtility.h"

#include "NoiseMapGeneration.h"

NoiseMapGeneration::NoiseMapGeneration()
{
}

NoiseMapGeneration::~NoiseMapGeneration()
{
}

std::vector<std::vector<float>> NoiseMapGeneration::GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale)
{
	std::vector<std::vector<float>> noiseMap(mapWidth, std::vector<float>(mapDepth, 0));

	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapDepth; y++)
		{
			float sampleX = x / scale;
			float sampleY = y / scale;

			float noise = 0.0f;
			noise = FMath::PerlinNoise2D(FVector2D(sampleX, sampleY));

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Noise: %f"), noise));

			noiseMap[x][y] = noise;
		}
	}

	return noiseMap;
}