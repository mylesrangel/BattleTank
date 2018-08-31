// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
//Clamp()
#include "UnrealMathUtility.h"
#include "Engine/World.h"



void UTankTurret::Rotate(float RelativeSpeed) {
	//Tested Works 8-2018

	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, Rotation, 0));

}