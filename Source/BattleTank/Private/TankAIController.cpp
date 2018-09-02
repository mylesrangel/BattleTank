// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"




void ATankAIController::BeginPlay()
{

	Super::BeginPlay();


}

void ATankAIController::Tick(float DeltaTime){

	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());


	if (PlayerTank) {

		//Move Towards the player

		//aim at the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//fire when ready
		ControlledTank->Fire();  //TODO dont fire every frame
		
	}



}


