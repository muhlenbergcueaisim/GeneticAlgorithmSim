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

