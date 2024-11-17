// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UE5PROCGEN_API NoiseMapGeneration
{
private:

public:
	NoiseMapGeneration();
	~NoiseMapGeneration();

	std::vector<std::vector<float>> GeneratePerlinNoiseMap(int mapWidth, int mapDepth, float scale);
};
