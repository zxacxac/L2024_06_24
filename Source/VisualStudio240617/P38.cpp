// Fill out your copyright notice in the Description page of Project Settings.


#include "P38.h"

// Sets default values
AP38::AP38()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP38::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP38::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP38::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

