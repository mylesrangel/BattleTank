// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
//Clamp()
#include "UnrealMathUtility.h"
#include "Engine/World.h"



void UTankBarrel::Elevate(float RelativeSpeed) {
	//Tested Works 8-2018

	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = ClampedRelativeSpeed * MaxDegreesElevation * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	//Clamps elevation into a Min and Max THEN sets it to relative rotation....duh
	auto Elevation = FMath::Clamp(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);


	//test test for git (delete)

	SetRelativeRotation(FRotator(Elevation, 0 , 0));

}
