#include "TurtlePawn.h"
#include "Turtles/Controllers/TurtleController.h"

ATurtlePawn::ATurtlePawn()
{
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = ATurtleController::StaticClass();
}

FVector ATurtlePawn::GetStartLocation() const
{
	return StartLocation;
}

void ATurtlePawn::SetStartLocation(const FVector& NewLocation)
{
	StartLocation = NewLocation;
}

FVector ATurtlePawn::GetEndLocation() const
{
	return EndLocation;
}

void ATurtlePawn::SetEndLocation(const FVector& NewLocation)
{
	EndLocation = NewLocation;
}

ETurtleMovementMode ATurtlePawn::GetMovementMode() const
{
	return MovementMode;
}

void ATurtlePawn::SetMovementMode(const ETurtleMovementMode& NewMode)
{
	MovementMode = NewMode;
}
