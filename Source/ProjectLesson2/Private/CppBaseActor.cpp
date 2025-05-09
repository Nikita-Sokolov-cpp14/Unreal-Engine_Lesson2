// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor() : Amplitude(10.0f), Frequency(4.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	SetRootComponent(mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitPosition = GetActorLocation();
	
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SinMovement();

}

void ACppBaseActor::SinMovement() {
	const float x = 0;
	const float y = 0;
	float z = Amplitude * sin(Frequency * GetWorld()->GetTimeSeconds());

	FVector ActorPosition = FVector(x, y, z) + InitPosition;
	SetActorLocation(ActorPosition);
}

