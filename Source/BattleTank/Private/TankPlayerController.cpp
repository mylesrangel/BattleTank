// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "BattleTank.h"




void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	auto ControlledTankName = GetControlledTank();

	if (!ControlledTankName) {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is not posessed by anything"))

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController is %s"), *(ControlledTankName->GetName()))
	}

}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}





