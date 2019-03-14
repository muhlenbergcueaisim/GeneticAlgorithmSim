// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DNA.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"

#include "ProtoPawn.generated.h"

UCLASS()
class PROTOLITH_API AProtoPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AProtoPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// this pawn's DNA object
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	UDNA* DNA;

	// this is the pawn's fintess score
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	float fitness;

	// has the pawn finished its fitness function?
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	bool isFinished;

	/*
	*	SCENE COMPONENTS
	*/

	// Root scene component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	USceneComponent* Root;

	// the blueprint component to represent pointing direction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	UArrowComponent* MyArrowComponent;

	// blueprint component for the box component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Protolith")
	UBoxComponent* MyBoxComponent;
};
