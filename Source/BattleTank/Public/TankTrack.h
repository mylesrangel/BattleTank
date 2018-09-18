// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "SpawnPoint.h"
#include "TankTrack.generated.h"


/**
 *  TankTrack is used to set maximum driving force and to apply forces to the tank
 */




UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)	
	void SetThrottle(float Throttle);
	
	//max for per track in neutons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 400000; //Assume 40 ton tank with 1g acceleration

	void DriveTrack(float CurrentThrottle);

private:

	TArray<class ASprungWheel*> GetWheels() const;


};
