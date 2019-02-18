// Fill out your copyright notice in the Description page of Project Settings.

#include "ProtoPawn.h"

// Sets default values
AProtoPawn::AProtoPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProtoPawn::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("pawn genes: %f"), DNA->Genes[0]->floatValue);

	//Root = CreateDefaultSubobject<USceneComponent>("Root");
	//RootComponent = Root;
	//DNA = CreateDefaultSubobject<UDNA>("DNA");
	//DNA->Genes[0]->floatValue = 4.7f;
	
}

// Called every frame
void AProtoPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AProtoPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

