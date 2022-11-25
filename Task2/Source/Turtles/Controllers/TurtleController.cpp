#include "TurtleController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Turtles/Characters/TurtlePawn.h"

ATurtleController::ATurtleController()
{
	PrimaryActorTick.bCanEverTick = true;
}