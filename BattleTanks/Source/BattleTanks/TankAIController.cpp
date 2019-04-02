// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("TankAIController Begin Play"));

	ATank* PlayerController = GetPlayerController();

	if (PlayerController) {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController found the player controller %s"), *(PlayerController->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankAIController can't fine player conroller"));
	}

}

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerController() const {
	auto PlayerTankController = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTankController) {
		return nullptr;
	}
	return Cast<ATank>(PlayerTankController);
}