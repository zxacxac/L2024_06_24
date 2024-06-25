// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UFloatingPawnMovement;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class VISUALSTUDIO240617_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	
	AMyPawn();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

	void RotatePropeller(UStaticMeshComponent* Where);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Pitch(float Value);

	void Roll(float Value);

	void PressBooster();

	void ReleaseBooster();

	void Fire();


	TObjectPtr<UBoxComponent> Box;

	TObjectPtr<UStaticMeshComponent> Body;

	TObjectPtr<class UMyStaticMeshComponent> Left;

	TObjectPtr<class UMyStaticMeshComponent> Right;

	TObjectPtr<UArrowComponent> Arrow;

	TObjectPtr<USpringArmComponent> SpringArm;

	TObjectPtr<UCameraComponent> Camera;

	TObjectPtr<UFloatingPawnMovement> Movement;

	float Booster;
};