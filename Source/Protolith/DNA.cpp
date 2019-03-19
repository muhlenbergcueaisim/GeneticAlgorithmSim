// Fill out your copyright notice in the Description page of Project Settings.

#include "DNA.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UDNA::UDNA()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//InitializeComponent();
	PrimaryComponentTick.bCanEverTick = true;	

}


// Called when the game starts
void UDNA::BeginPlay()
{
	Super::BeginPlay();
	NumberOfGenes = 1;
	for (int i = 0; i < NumberOfGenes; i++)
	{
		Genes.Add(rand() % 91);
	}
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
UDNA *UDNA::Mutate(UDNA * DNA, int chance, int maxChange)
{
	for (int i = 0; i < DNA->NumberOfGenes; i++) {
		if (rand() % 100 < chance) {
			DNA->Genes[i] = DNA->Genes[i] + (rand() % (2 * maxChange + 1) - maxChange);
		}
	}

	return DNA;
}

// returns two children of the two UDNA
UDNA *UDNA::Cross(UDNA* DNA, UDNA* parent0, UDNA* parent1)
{
	int mask0, mask1, randomNum, minLen, maxLen;
	int geneCount;
	int MaxCrossPoint = 8;

	UDNA* longParent;
	DNA->Genes.Empty();

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
	geneCount = minLen;

	for (int i = 0; i < minLen; i++) {
		randomNum = rand() % MaxCrossPoint + 1;

		UE_LOG(LogTemp, Warning, TEXT("Crossing Point: %d"), randomNum);
		mask0 = 0;
		mask1 = 0;

		for (int maskI = 32; maskI > 0; maskI--) {
			if (maskI > randomNum) {
				mask0 = (mask0 << 1) | 1;
			}
			else {
				mask1 = (mask1 << 1) | 1;
			}
		}

		mask0 = mask0 << randomNum;
		UE_LOG(LogTemp, Warning, TEXT("mask0: %x"), mask0);
		UE_LOG(LogTemp, Warning, TEXT("mask1: %x"), mask1);

		DNA->Genes.Emplace((parent0->Genes[i] & mask0) | (parent1->Genes[i] & mask1));
		UE_LOG(LogTemp, Warning, TEXT("Gene contains: %d"), DNA->Genes[0]);
	}
	for (int i = minLen; i < maxLen; i++) {
		if (rand() % 2 == 0) { 
			
			DNA->Genes.Emplace(longParent->Genes[i]); 
			geneCount++; 
		} 

	}
	DNA->NumberOfGenes = geneCount; 

	return DNA; 

}