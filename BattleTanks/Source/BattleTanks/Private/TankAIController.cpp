// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

	ATank* tankReference = GetControlledTank();

	if (tankReference) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController has a tank reference %s"), *(tankReference->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController no tank reference"));
	}

}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn()); 
}

