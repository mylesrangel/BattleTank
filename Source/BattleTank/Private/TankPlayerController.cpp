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

void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	AimTowardCrosshair();

}

void ATankPlayerController::AimTowardCrosshair() {

	if (!GetControlledTank()) { return; }

	//get world location linetrace through crosshair
	//if it hits the landscape
		//tell the controlled tank to aim at this point


}

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}


