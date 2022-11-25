#include "NestButton.h"

ANestButton::ANestButton()
{
	PrimaryActorTick.bCanEverTick = true;

	// Root
	SceneComponent = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(SceneComponent);
}

void ANestButton::Interaction_Implementation(AActor* InInstigator)
{
	Execute_Interaction(TargetActivation, InInstigator);
}

bool ANestButton::CanInteract_Implementation() const
{
	return !!TargetActivation && Execute_CanInteract(TargetActivation);
}
