// Fill out your copyright notice in the Description page of Project Settings.

#include "NoiseMapGeneration.h"

NoiseMapGeneration::NoiseMapGeneration()
{
}

NoiseMapGeneration::~NoiseMapGeneration()
{
}

std::vector<std::vector<float>> NoiseMapGeneration::GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale, float offsetX, float offsetY)
{
	std::vector<std::vector<float>> noiseMap(mapWidth, std::vector<float>(mapDepth, 0));

	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapDepth; y++)
		{
			float sampleX = (x + offsetX) / scale;
			float sampleY = (y + offsetY) / scale;

			float noise = 0.0f;

			// Generate noise value using PerlinNoise for a given Wave
			noise = (FMath::PerlinNoise2D(FVector2D(sampleX, sampleY)) + 1) / 2;

			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Noise: %f"), noise));

			noiseMap[x][y] = noise;
		}
	}

	return noiseMap;
}
