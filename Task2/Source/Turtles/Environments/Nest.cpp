#include "Nest.h"

#include "Components/ArrowComponent.h"
#include "Engine/TargetPoint.h"
#include "Kismet/GameplayStatics.h"
#include "Turtles/Characters/TurtlePawn.h"

ANest::ANest()
{
	PrimaryActorTick.bCanEverTick = true;

	// Root
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(SceneComponent);
	
	// Start point
	StartPoint = CreateDefaultSubobject<UArrowComponent>("StartPoint");
	StartPoint->SetupAttachment(SceneComponent);
}

void ANest::Interaction_Implementation(AActor* InInstigator)
{
	if (const auto NewTurtle = GetWorld()->SpawnActorDeferred<ATurtlePawn>(SpawnClass, StartPoint->GetComponentTransform()))
	{
		NewTurtle->SetStartLocation(GetActorLocation());
		NewTurtle->SetEndLocation(DestinationPoint->GetActorLocation());
		NewTurtle->SetMovementMode(TurtleMovementMode);
		UGameplayStatics::FinishSpawningActor(NewTurtle, StartPoint->GetComponentTransform());

		SpawnedTurtle = NewTurtle;
		OnTurtleSpawned();
	}
}

bool ANest::CanInteract_Implementation() const
{
	return !SpawnedTurtle;
}

void ANest::OnTurtleSpawned_Implementation()
{
}
