// Fill out your copyright notice in the Description page of Project Settings.

#include "NoiseMapGeneration.h"

NoiseMapGeneration::NoiseMapGeneration()
{
}

NoiseMapGeneration::~NoiseMapGeneration()
{
}

std::vector<std::vector<float>> NoiseMapGeneration::GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale, float offsetX, float offsetY, TArray<FVector> waves)
{
	std::vector<std::vector<float>> noiseMap(mapWidth, std::vector<float>(mapDepth, 0));

	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapDepth; y++)
		{
			float sampleX = (x + offsetX) / scale;
			float sampleY = (y + offsetY) / scale;

			float noise = 0.0f;
			float normalization = 0.0f;

			// wave[0] = seed, wave[1] = frequency, wave[2] = amplitude
			for (const FVector& wave : waves)
			{
				// Generate noise value using PerlinNoise for a given Wave
				noise += wave[2] * ((FMath::PerlinNoise2D(FVector2D((sampleX * wave[1]) + wave[0], (sampleY * wave[1]) + wave[0])) + 1) / 2);
				normalization += wave[2];
			}

			/*if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Noise: %f"), noise));*/

			// Normalize the noise value so that it is within 0 and 1
			noise /= normalization;
			noiseMap[x][y] = noise;
		}
	}

	return noiseMap;
}
