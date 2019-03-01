// Fill out your copyright notice in the Description page of Project Settings.

#include "PopulationActor.h"
#include "math.h"

// Sets default values
APopulationActor::APopulationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Population = PopGenesis();

}

// Called when the game starts or when spawned
void APopulationActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APopulationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// initializes the population and returns an array of pawn actors
TArray<AProtoPawn*> APopulationActor::PopGenesis(TArray<FTransform> spawnTransform)
{
	TArray <AProtoPawn*> newPopulation = TArray<AProtoPawn*>();

	UWorld* world = GetWorld();

	for (int i = 0; i <= 4; i++)
	{
		//pawnType = PawnTypes[0];
		// get a reference to the world

		int randSpawn = rand() % 4;
		AProtoPawn* ReturnPawn = world->SpawnActor<AProtoPawn>(PawnType, spawnTransform[randSpawn]);

		// increment current size
		currentSize++;
		UE_LOG(LogTemp, Warning, TEXT("adding pawn to population..."));
		newPopulation.Add(ReturnPawn);
		//newPopulation[i] = ReturnPawn;
	}

	return newPopulation;
}

void APopulationActor::EvaluateFitness(TArray<AProtoPawn*> Pop)
{
	UE_LOG(LogTemp, Warning, TEXT("evaluating fitness..."));
}

// removes the weakest pawns
void APopulationActor::eliminate()
{
	TArray<AProtoPawn*> remainingPopulation = TArray<AProtoPawn*>();
	int newPopulationSize = initialSize * recuringPopulation;
	for (int i = 0; i < newPopulationSize; i++) {
		remainingPopulation.Emplace(Population[i]);
	}
	Population = remainingPopulation;
	currentSize = newPopulationSize;
}

// refills the population with a new generation
void APopulationActor::reproduce(TArray<AProtoPawn*> pop)
{
	int parent0, parent1;
	
	TArray<AProtoPawn*> nextGeneration;
	UDNA newDNA;// = UDNA::UDNA();

	while (currentSize < initialSize) {
		AProtoPawn* newPawn = GetWorld()->SpawnActor<AProtoPawn>(PawnType);

		parent0 = getIndex();
		if (twoParents) {
			do {
				parent1 = getIndex();
			} while (parent0 == parent1)
		}
		else {
			parent1 = getIndex();
		}

		//parent0 = 0;
		//rand() % Population.Num();
		//parent1 = 1;
		//rand() % Population.Num();
		//newDNA = UDNA::Cross(Population[parent0]->DNA, Population[parent1]->DNA);
		newPawn->DNA->Cross(&newDNA, Population[parent0]->DNA, Population[0]->DNA);
		//newDNA.Cross(Population[parent0]->DNA, Population[parent1]->DNA);
		newPawn->DNA->Mutate(newPawn->DNA, mutateChance, maxMutateChange);
		//newPawn.DNA = &newDNA;
		nextGeneration.Emplace(newPawn);
		currentSize++;
		/*
		if (currentSize < initialSize) {
			//newPawn.DNA = &newDNA;
			//newPawn.DNA->Mutate(&newDNA, mutateChance, maxMutateChange);
			nextGeneration.Emplace(newPawn);
			currentSize++;
		}
		*/
	}
	Population.Append(nextGeneration);
}

// handles the structure of the genetic algorithm
void APopulationActor::geneticAlgorithm()
{
	while (!stop) {
		if (fitnessesSet()) { //need a way to ensure that the fitness of each pawn has been calculated (this does it)
			// no idea what's going on here and it breaks compile
			// Population.Sort([](const AProtoPawn& left, const AProtoPawn right) {return left.fitness > right.fitness; });
			eliminate();
			reproduce(Population);
		}
	}
}

// checks if all of the pawns have had their fitness's set
bool APopulationActor::fitnessesSet()
{
	for (int i = 0; i < curentSize; i++) {
		if (!Population[i]->isFinished) {
			return false;
		}
	}
	return true;
}

// gets an index for a parent
int APopulationActor::getIndex()
{
	int randomNum, index;
	randomNum = rand() % (1 << Population.Num());
	index = Population.Num() - 1;

	while (randomNum > 0) {
		randomNum = randomNum / 2;
		index--;
	}
	return index;
}
