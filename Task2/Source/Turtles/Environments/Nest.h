#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Turtles/Characters/TurtlePawn.h"
#include "Turtles/Components/Interaction/Types/InteractionInterface.h"
#include "Nest.generated.h"

class ATargetPoint;
class UArrowComponent;
class ATurtlePawn;

UCLASS()
class TURTLES_API ANest : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components, meta=(AllowPrivateAccess=true))
	USceneComponent* SceneComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Components, meta=(AllowPrivateAccess=true))
	UArrowComponent* StartPoint;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=References)
	ATurtlePawn* SpawnedTurtle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	ATargetPoint* DestinationPoint;

	// Settings
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	TSubclassOf<ATurtlePawn> SpawnClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	ETurtleMovementMode TurtleMovementMode;
	
public:
	ANest();

	virtual void Interaction_Implementation(AActor* InInstigator) override;
	virtual bool CanInteract_Implementation() const override;

	UFUNCTION(BlueprintNativeEvent, Category=Effects)
	void OnTurtleSpawned();
};
