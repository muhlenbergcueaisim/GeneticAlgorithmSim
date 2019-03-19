// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "Struct_DNA.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class PROTOLITH_API UStruct_DNA : public UUserDefinedStruct
{
	GENERATED_BODY()

public:
	// number of genes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	int NumberOfGenes;

	// Array of Floats
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	TArray<float> Genes;
};
