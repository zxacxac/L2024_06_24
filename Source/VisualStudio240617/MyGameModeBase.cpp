// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyPlayerController.h"
#include "MyPawn.h"

AMyGameModeBase::AMyGameModeBase()
{
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White,
			TEXT("Frank Ocean"));
	}

	UE_LOG(LogTemp, Error, TEXT("Frank Ocean"));

	PlayerControllerClass = AMyPlayerController::StaticClass();

	DefaultPawnClass = AMyPawn::StaticClass();

}