// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




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
	}

}

void ATankAIController::Tick(float DeltaTime){

	Super::Tick(DeltaTime);


	if (GetPlayerTank()) {

		//Move Towards the player

		//aim at the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//fire when ready
		
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


