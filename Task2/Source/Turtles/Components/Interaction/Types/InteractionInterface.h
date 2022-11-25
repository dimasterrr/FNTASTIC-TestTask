﻿#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UINTERFACE()
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class TURTLES_API IInteractionInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Interaction)
	void Interaction(AActor* Instigator);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category=Interaction)
	bool CanInteract() const;
};
