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
	//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController Ticking"));
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

	FVector LookDirection;

	if (GetLookDirection(ScreenCoords, LookDirection)) {
		//UE_LOG(LogTemp, Warning, TEXT("TankPlayerController aiming at position (X:%f, Y:%f, Z:%f"), LookDirection.X, LookDirection.Y, LookDirection.Z);
		FVector HitLocation;
		if (GetLookVectorHitLocation(LookDirection, HitLocation)) {
			
		}
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController hitting something at position (X:%f, Y:%f, Z:%f"), HitLocation.X, HitLocation.Y, HitLocation.Z);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenCoords, FVector& OutLookDirection) const {

	FVector WorldLocation; //throw away

	return DeprojectScreenPositionToWorld(ScreenCoords.X, ScreenCoords.Y, WorldLocation, OutLookDirection);

}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const {

	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)) {
		OutHitLocation = HitResult.Location;
		
		return true;
	}
	OutHitLocation = FVector(0);
	return false;
}