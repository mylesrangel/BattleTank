// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
//Needed for SuggestProjectileVelocity
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"



// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;

}


void UTankAimingComponent::AimAt(FVector OutHitLocation, float LaunchSpeed) {

	

	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	///startlocation of projectile (added a socket to the barrel)
	FVector StartLocation = Barrel->GetSocketLocation(FName ("Projectile"));


	///Gets projectile trace (geometry on firing a tank round)
	if (UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		OutHitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace

	)) {
		auto TankName = GetOwner()->GetName();
		auto AimDirection = OutLaunchVelocity.GetSafeNormal(); ///Convert the trace to (Smaller line)
		
		UE_LOG(LogTemp, Warning, TEXT("Suggest projectile found:") )

		MoveBarrelTowards(AimDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Suggest projectile NOT found:"))

	}


}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {

	///difference between current barrel location and where we want to aim

	//Yaw, Pitch and roll of the barrel at the current moment
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();

	//Yaw, Pitch and roll of the barrel at where we want to aim
	auto AimAsRotator = AimDirection.Rotation();

	//Difference between where we want to aim and where we are currently aiming
	auto DeltaRotator = AimAsRotator - BarrelRotator;


	//move barrel proper amount per frame (Speed of turret)
	//given a max elevation, speed, and time frame

	Barrel->Elevate(5.f);


}

