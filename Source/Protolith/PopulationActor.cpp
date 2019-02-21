// Fill out your copyright notice in the Description page of Project Settings.

#include "PopulationActor.h"

// Sets default values
APopulationActor::APopulationActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Population = PopGenesis();

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
TArray<AProtoPawn*> APopulationActor::PopGenesis()
{
	TArray <AProtoPawn*> newPopulation = TArray<AProtoPawn*>();
	
	for (int i = 0; i <= initialSize; i++)
	{
		//pawnType = PawnTypes[0];
		// get a reference to the world
		UWorld* world = GetWorld();

		//AProtoPawn* ReturnPawn = world->SpawnActor<AProtoPawn>(PawnType, popOrigin);

		// increment current size
		currentSize++;
		UE_LOG(LogTemp, Warning, TEXT("adding pawn to population..."));
		//newPopulation.Add(ReturnPawn);
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
	curentSize = newPopulationSize;
}

// refills the population with a new generation
void APopulationActor::reproduce()
{
	int parent0, parent1;
	TArray<UDNA*> newDNA = TArray<UDNA*>
	TArray<AProtoPawn*> nextGeneration = TArray<AProtoPawn*>();
	AProtoPawn* newPawn;

	while (curentSize < initialSize) {
		parent0 = rand() % Population.Num();
		parent1 = rand() % Population.Num();
		newDNA = UDNA::Cross(Population[parent0]->DNA, Population[parent1]->DNA);

		newPawn = AProtoPawn::AProtoPawn();
		newPawn->DNA = UDNA::Mutate(newDNA[0], mutateChance);
		nextGeneration.Emplace(newPawn);
		curentSize++;

		if (curentSize < initialSize) {
			newPawn = AProtoPawn::AProtoPawn();
			newPawn->DNA = UDNA::Mutate(newDNA[1], mutateChance);
			nextGeneration.Emplace(newPawn);
			curentSize++;
		}
	}
	Population.Append(nextGeneration, nextGeneration.Num());
}

// handles the structure of the genetic algorithm
void APopulationActor::geneticAlgorithm()
{
	while (!stop) {
		//need a way to ensure that the fitness of each pawn has been calculated
		Population.Sort([](const AProtoPawn& left, const AProtoPawn right) {return left.fitness > right.fitness; });
		eliminate();
		reproduce();
	}
}

