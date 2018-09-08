// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"



void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {

	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}


void UTankMovementComponent::IntendMoveForward(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend Move Forward %f"), Throw)


	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO: Prevent Double speed due to dual control use (Controller)

}

void UTankMovementComponent::IntendMoveBackward(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend Move Backward %f"), Throw)


	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO: Prevent Double speed due to dual control use (Controller)

}


void UTankMovementComponent::IntendTurnRight(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend turn right %f"), Throw)


	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO: Prevent Double speed du-e to dual control use (Controller)

}
void UTankMovementComponent::IntendTurnLeft(float Throw)
{

	UE_LOG(LogTemp, Warning, TEXT("Intend turn left %f"), Throw)


	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);

	//TODO: Prevent Double speed du-e to dual control use (Controller)

}