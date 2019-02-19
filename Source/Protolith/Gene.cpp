// Fill out your copyright notice in the Description page of Project Settings.

#include "Gene.h"
// Sets default values for this component's properties
UGene::UGene()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	//Genes.Add(Gene);

}


// Called when the game starts
void UGene::BeginPlay()
{
	Super::BeginPlay();
}

//	mutates and returns the gene
UGene* UGene::Mutate(UGene* origGene)
{
	// store the original value
	float origValue = origGene->FloatValue;
	// mutate the original value
	bool isPositive = FMath::RandBool();
	float randomFloat = FMath::FRandRange(0, 0.01);
	float mutatedValue = (isPositive ? (origValue + randomFloat) : (origValue - randomFloat));

	//	set the new gene's value to the mutated value
	origGene->FloatValue = mutatedValue;

	// print a log of the new value
	UE_LOG(LogTemp, Warning, TEXT("gene value: %f"), origGene->FloatValue);

	return origGene;
}