

#include "MyPawn.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyStaticMeshComponent.h"
#include "MyRocket.h"

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Box->SetBoxExtent(FVector(45.f, 65.f, 15.f));

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/MESH/SM_P38_Body.SM_P38_Body'"));
	if (SM_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_Body.Object);
	}


	Left = CreateDefaultSubobject<UMyStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);

	Right = CreateDefaultSubobject<UMyStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Propeller(TEXT("/Script/Engine.StaticMesh'/Game/P38/MESH/SM_P38_Propeller.SM_P38_Propeller'"));
	if (SM_Propeller.Succeeded())
	{
		Left->SetStaticMesh(SM_Propeller.Object);
		Right->SetStaticMesh(SM_Propeller.Object);
	}
	Left->SetRelativeLocation(FVector(36.5f, 21.0f, 0.5f));
	Right->SetRelativeLocation(FVector(36.5f, -21.0f, 0.5f));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(Box);
	SpringArm->TargetArmLength = 100.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);
	Arrow->SetRelativeLocation(FVector(80.0f, 0, 0));

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->MaxSpeed = 1000.0f;

	Booster = 1.0f;
}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector(),
		Booster);

}

void AMyPawn::RotatePropeller(UStaticMeshComponent* Where)
{
	Where->AddLocalRotation(FRotator(0, 0, 3600.f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld())));
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Pitch"), this, &AMyPawn::Pitch);
	PlayerInputComponent->BindAxis(TEXT("Roll"), this, &AMyPawn::Roll);
	PlayerInputComponent->BindAction(TEXT("BOOSTER"), IE_Pressed, this, &AMyPawn::PressBooster);
	PlayerInputComponent->BindAction(TEXT("BOOSTER"), IE_Released, this, &AMyPawn::ReleaseBooster);
	PlayerInputComponent->BindAction(TEXT("Attack"), IE_Pressed, this, &AMyPawn::Fire);
}

void AMyPawn::Pitch(float Value)
{
	float Dir = FMath::Clamp(Value, -1.0f, 1.0f);

	AddActorLocalRotation(FRotator(Dir * 60.0f *
		UGameplayStatics::GetWorldDeltaSeconds(GetWorld()), 0, 0));
}

void AMyPawn::Roll(float Value)
{
	float Dir = FMath::Clamp(Value, -1.0f, 1.0f);

	AddActorLocalRotation(
		FRotator(0,
			0,
			Dir * 60.0f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()))
	);
}

void AMyPawn::PressBooster()
{
	Booster = 1.0f;
}

void AMyPawn::ReleaseBooster()
{
	Booster = 0.5f;
}

void AMyPawn::Fire()
{
	GetWorld()->SpawnActor<AMyRocket>(Arrow->K2_GetComponentLocation(),
		Arrow->K2_GetComponentRotation());
}
