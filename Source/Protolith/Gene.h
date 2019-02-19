// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Gene.generated.h"

/**
 * 
 */

UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROTOLITH_API UGene : public UActorComponent
{
	GENERATED_BODY()
public:
	//Constructor
	UGene();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:

	//Always make USTRUCT variables into UPROPERTY()
	//    any non-UPROPERTY() struct vars are not replicated

	// So to simplify your life for later debugging, always use UPROPERTY()
	UPROPERTY()
	int32 SampleInt32;

	//If you want the property to appear in BP, make sure to use this instead
	//UPROPERTY(BlueprintReadOnly)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Protolith")
		float FloatValue;

	//Set
	void SetInt(const int32 NewValue)
	{
		SampleInt32 = NewValue;
	}



	UFUNCTION(BlueprintCallable, Category = "Protolith")
		UGene* Mutate(UGene* origGene);

	
};
