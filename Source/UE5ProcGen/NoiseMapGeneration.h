// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "utils/Tarray2D.h"

class UE5PROCGEN_API NoiseMapGeneration
{
private:

public:
	NoiseMapGeneration();
	~NoiseMapGeneration();

	TArray2D<float> GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale, float offsetX, float offsetY, TArray<FVector> waves = {});
};
