// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	
	public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//Aims barrel of tank through crosshair to shoot enemy tank
	void AimTowardCrosshair();

	ATank* GetControlledTank() const;
	

};
