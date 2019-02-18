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

