// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"

// Template class for a fake 2D TArray as these arent properly supported in Unreal Engine
// This works by having width and depth variables, so it can be treated as a 2D TArray, but under the hood is just one long TArray, this makes it easier to visualise
template <typename ElementType>
class UE5PROCGEN_API TArray2D
{
public:
	// Sets Inintial size of TArray and fills it with a given value
	void Init(const ElementType& element, int _width, int _depth)
	{
		width = _width;
		depth = _depth;
		trueArray.Init(element, _width * _depth);
	}

	FORCEINLINE ElementType& GetElement(const int x, const int y)
	{
		return trueArray[(x * width) + y];
	}

	FORCEINLINE void SetElement(const int x, const int y, const ElementType& item)
	{
		trueArray[(x * width) + y] = item;
	}

private:
	int width = 0;
	int depth = 0;
	UPROPERTY()
		TArray<ElementType> trueArray;
};
