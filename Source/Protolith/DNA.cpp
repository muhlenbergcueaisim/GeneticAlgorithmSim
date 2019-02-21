// Fill out your copyright notice in the Description page of Project Settings.

#include "DNA.h"

// Sets default values for this component's properties
UDNA::UDNA()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	float floatVal = 0.7f;
	
	//Genes.Add(Gene);

}


// Called when the game starts
void UDNA::BeginPlay()
{
	Super::BeginPlay();

	// ...
	NumberOfGenes = 1;
	for (int i = 0; i <= NumberOfGenes; i++)
	{
		//UStruct newGene;
		//Genes[i] = &newGene;
		//Genes[i]->floatValue = 0;
	}
	// ...
	
}

// Called every frame
void UDNA::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// returns a replicate of the DNA object
UDNA* UDNA::Replicate(UDNA* origDNA)
{
	UDNA* alias = origDNA;
	return alias;
}

// mutates the DNA
UDNA * UDNA::Mutate(UNDA * DNA, int chance)
{
	for (int i = 0; i < DNA->NumberOfGenes; i++) {
		if (rand() % 100 < chance) {
			if (rand() % 2 == 0) {
				DNA->Genes[i]++;
			}
			else {
				DNA->Genes[i]--;
			}
		}
	}

	return DNA;
}

// returns two children of the two UDNA
TArray<UDNA*> UDNA::Cross(UDNA* parent0, UDNA* parent1)
{
	TArray<UDNA*> children = TArray<UNDA*>();
	int mask0, mask1, randomNum, minLen, maxLen, child0GeneCount, child1GeneCount;
	UDNA* longParent;

	children.Emplace(UDNA::UDNA());
	children.Emplace(UDNA::UDNA());

	if (parent0->NumberOfGenes < parent1->NumberOfGenes) {
		minLen = parent0->NumberOfGenes;
		maxLen = parent1->NumberOfGenes;
		longParent = parent1;
	}
	else {
		minLen = parent1->NumberOfGenes;
		maxLen = parent0->NumberOfGenes;
		longParent = parent0;
	}
	child0GeneCount = minLen;
	child1GeneCount = minLen;

	for (int i = 0; i < minLen; i++) {
		randomNum = rand() % 32 + 1;
		mask0 = 0;
		mask1 = 0;
		for (int maskI = 32; maskI > 0; maskI--) {
			if (maskI > randomNum) {
				mask0 = (mask0 & 1) << 1;
			}
			else {
				mask1 = (mask1 & 1) << 1;
			}
		}
		mask0 = mask0 << randomNum;
		children[0]->Genes.Emplace((parent0->Genes[i] & mask0) | (parent1->Genes[i] & mask1));
		children[1]->Genes.Emplace((parent0->Genes[i] & mask1) | (parent1->Genes[i] & mask0));
	}
	for (int i = minLen; i < maxLen; i++) {
		randomNum = rand() % 3;
		if (randomNum == 0) {
			children[0]->Genes.Emplace(longPraent->Genes[i]);
			child0GeneCount++;
		}
		else if (randomNum == 1) {
			children[1]->Genes.Emplace(longPraent->Genes[i]);
			child1GeneCount++;
		}
		else {
			children[0]->Genes.Emplace(longPraent->Genes[i]);
			children[1]->Genes.Emplace(longPraent->Genes[i]);
			child0GeneCount++;
			child1GeneCount++;
		}
	}
	children[0]->NumberOfGenes = child0GeneCount;
	children[1]->NumberOfGenes = child1GeneCount;
	return children;
}