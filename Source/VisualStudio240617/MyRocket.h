// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyRocket.generated.h"

UCLASS()
class VISUALSTUDIO240617_API AMyRocket : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMyRocket();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<class UBoxComponent> Box;

	TObjectPtr<class UStaticMeshComponent> Mesh;

	TObjectPtr<class UProjectileMovementComponent> Movement;

};
