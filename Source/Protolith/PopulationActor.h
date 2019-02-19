// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProtoPawn.h"
#include "PopulationActor.generated.h"

UCLASS()
class PROTOLITH_API APopulationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APopulationActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Number of seed individuals
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		int initialSize = 9;

	// the current number of individuals
	UPROPERTY(BlueprintReadOnly, Category = "Protolith")
		int currentSize;

	// enable or disable crossover
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		bool crossover = true;

	// the probability of crossover happening
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith", meta = (UIMin = "0.0", UIMax = "1.0"))
		float crossoverChance = 0.2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		AProtoPawn* pawnToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		FTransform popOrigin;

	// an array of pointers to actors in the population
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AProtoPawn*> Population;

	// initializes the population
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		TArray<AProtoPawn*> PopGenesis();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		TSubclassOf<AProtoPawn> PawnType;

	// evaluates the fitness of each member of the population
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		void EvaluateFitness(TArray<AProtoPawn*> Pop);

};

