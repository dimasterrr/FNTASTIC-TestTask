#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turtles/Components/Interaction/Types/InteractionInterface.h"
#include "NestButton.generated.h"

UCLASS()
class TURTLES_API ANestButton : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components, meta=(AllowPrivateAccess=true))
	USceneComponent* SceneComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	AActor* TargetActivation;
	
public:
	ANestButton();

	virtual void Interaction_Implementation(AActor* InInstigator) override;
	virtual bool CanInteract_Implementation() const override;
};
