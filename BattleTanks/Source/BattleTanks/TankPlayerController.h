// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where
	//the crossair intersects the world
	void AimTowardCrossair();
	//Return true if the crossair hits the landscape, and a OUT FVector of the position
	bool GetSightHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
		float CrossAirXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrossAirYLocation = 0.33333f;
	
};
