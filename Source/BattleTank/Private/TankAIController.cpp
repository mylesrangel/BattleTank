// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{

	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto TankAiSpotted = GetPlayerTank();

	UE_LOG(LogTemp, Warning, TEXT("Controlled AI Tank: %s"),*ControlledTank->GetName())
	
	if (!TankAiSpotted) {
		UE_LOG(LogTemp, Warning, TEXT("Controlled AI Tank sees nothing"), )

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled AI Tank sees %s"), *TankAiSpotted->GetName())

	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());


}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerTank) { return nullptr; }
	else {
		return Cast<ATank>(PlayerTank);
	}
}


