#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"
#include "TurtlePawn.generated.h"

UENUM(BlueprintType)
enum class ETurtleMovementMode : uint8
{
	Simple,
	Delayed,
	Reversed
};

UCLASS()
class TURTLES_API ATurtlePawn : public ACharacter /*Can replace to APawn + FloatingMovementComponent*/
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintGetter=GetStartLocation, BlueprintSetter=SetStartLocation, Category=Settings)
	FVector StartLocation;
	
	UPROPERTY(EditAnywhere, BlueprintGetter=GetEndLocation, BlueprintSetter=SetEndLocation, Category=Settings)
	FVector EndLocation;

	UPROPERTY(EditAnywhere, BlueprintGetter=GetMovementMode, BlueprintSetter=SetMovementMode, Category=Settings)
	ETurtleMovementMode MovementMode;
	
public:
	ATurtlePawn();

	UFUNCTION(BlueprintPure, Category=Mutations)
	FVector GetStartLocation() const;

	UFUNCTION(BlueprintCallable, Category=Mutations)
	void SetStartLocation(const FVector& NewLocation);

	UFUNCTION(BlueprintPure, Category=Mutations)
	FVector GetEndLocation() const;

	UFUNCTION(BlueprintCallable, Category=Mutations)
	void SetEndLocation(const FVector& NewLocation);

	UFUNCTION(BlueprintPure, Category=Mutations)
	ETurtleMovementMode GetMovementMode() const;

	UFUNCTION(BlueprintCallable, Category=Mutations)
	void SetMovementMode(const ETurtleMovementMode& NewMode);
};
