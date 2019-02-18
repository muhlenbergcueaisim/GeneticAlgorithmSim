// Fill out your copyright notice in the Description page of Project Settings.

#include "KobunPawn.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
AKobunPawn::AKobunPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OurCapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootCapsuleComponent"));
	RootComponent = OurCapsuleCollision;
	OurCapsuleCollision->InitCapsuleSize(25.0f, 50.0f);
	OurCapsuleCollision->SetCollisionProfileName(TEXT("Pawn"));

	OurKobunSkeleton = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));

	// Use a spring arm to give the camera smooth, natural-feeling motion.
	OurSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	OurSpringArm->SetupAttachment(RootComponent);
	OurSpringArm->RelativeRotation = FRotator(0.f, 0.f, 90.f);
	OurSpringArm->TargetArmLength = 400.0f;
	OurSpringArm->bEnableCameraLag = true;
	OurSpringArm->CameraLagSpeed = 3.0f;

	// Create a camera and attach to our spring arm
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(OurSpringArm);
	
}

// Called when the game starts or when spawned
void AKobunPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKobunPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKobunPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

