// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Gene.h"
#include "DNA.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROTOLITH_API UDNA : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDNA();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// an array of our genes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		TArray<UGene*> Genes;

	// an individual gene struct
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		//UStruct* Gene;

	// number of genes
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
		int NumberOfGenes;

	// returns a copy of itself
	UFUNCTION(BlueprintCallable, Category = "Protolith")
		UDNA* Replicate(UDNA* origDNA);


};