// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing: %s"), *ControlledTank->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("Player Controller Begin Play"))
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// AimTowardCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank())
	{
		return;
	}

	// Get world location if linetrace through crosshair
	// if it hits something 
		// tell controlled tank to aim at this point
}