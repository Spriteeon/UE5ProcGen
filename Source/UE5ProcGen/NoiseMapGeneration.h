// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "utils/Tarray2D.h"

class UE5PROCGEN_API NoiseMapGeneration : public UClass
{
private:

	TArray2D<float> noiseMap;

public:
	NoiseMapGeneration();
	~NoiseMapGeneration();

	void GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale, float offsetX, float offsetY, TArray<FVector> waves = {});

	FORCEINLINE float GetNoiseValue(int x, int y)
	{
		return noiseMap.GetElement(x, y);
	}
};
