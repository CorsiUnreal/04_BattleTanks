// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Begin Play"));

	ATank* tankReference = GetControlledTank();
	
	if (tankReference) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController has a tank reference %s"), *(tankReference->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController no tank reference"));
	}

}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Ticking"));
	AimTowardCrossair();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrossair() {
	if (!GetControlledTank()) { return; }

	FVector OutHitLocation;
	if (GetSightHitLocation(OutHitLocation)) {

	}

}

bool ATankPlayerController::GetSightHitLocation(FVector& OutHitLocation) const {

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	float XCoord = ViewportSizeX * CrossAirXLocation;
	float YCoord = ViewportSizeY * CrossAirYLocation;

	auto ScreenCoords = FVector2D(XCoord, YCoord);

	return true;
}

