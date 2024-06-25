// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


AMyRocket::AMyRocket()
{
 
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Box);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/MESH/SM_Rocket.SM_Rocket'"));
	if (SM_Body.Succeeded())
	{
		Mesh->SetStaticMesh(SM_Body.Object);
	}
	Mesh->SetRelativeRotation(FRotator(-90.0f, 0, 0));

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->InitialSpeed = 3000.0f;
	Movement->MaxSpeed = 3000.0f;
	Movement->ProjectileGravityScale = 0.0f;
}

void AMyRocket::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(3.0f);
	
}

void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

