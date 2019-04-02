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

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

