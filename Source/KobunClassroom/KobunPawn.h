// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KobunPawn.generated.h"

UCLASS()
class KOBUNCLASSROOM_API AKobunPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKobunPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// A pointer to our static mesh component
	UPROPERTY(EditAnywhere)
		USkeletalMeshComponent* OurKobunSkeleton;

	// A capsule component for collision detection
	UPROPERTY(EditAnywhere)
		UCapsuleComponent* OurCapsuleCollision;

	// a camera boom to lag the camera follow
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USpringArmComponent* OurSpringArm;

	// a camera to view the kobun
	UPROPERTY(EditAnywhere)
		UCameraComponent* OurCamera;
	
	// A Pointer to our particle system (for KO effects, victory etc)
	UPROPERTY(EditAnywhere)
		UParticleSystemComponent* OurParticleSystem;

	// A Color picker for the cap
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kobun")
		FVector OurCapColor;

	// let's expose our fitness value to blueprint as well...
	UPROPERTY(BlueprintReadOnly)
		float OurFitness;
};
