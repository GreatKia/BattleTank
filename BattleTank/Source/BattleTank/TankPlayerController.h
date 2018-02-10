// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // must be the last #include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;


private:
	
	ATank* GetControlledTank() const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	// Start the tank moving the barrel towards crosshair
	void AimTowardCrosshair();
	
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	bool GetLookVectorHitLocation(FVector LineTraceStartPosition, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossaHairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
	float CrossaHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
