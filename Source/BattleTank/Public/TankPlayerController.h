// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
//#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

//This class is included at the top. TESTING
class APawn;

class ATank;
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

	private:

	//Aims barrel of tank through crosshair to shoot enemy tank
	void AimTowardCrosshair();

	ATank* GetControlledTank() const;

	bool GetSightRayHitLocation(FVector &) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	bool GetLookVectorHitLocation(FVector, FVector&) const;

	bool GetLookDirection(FVector2D, FVector&) const;


	

};
