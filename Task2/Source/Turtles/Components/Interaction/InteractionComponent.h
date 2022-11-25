﻿#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetIsChanged, AActor*, TargetActor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TURTLES_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Category=Develope, meta=(AllowPrivateAccess="true"))
	AActor* TargetActor;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Settings)
	bool DrawDebug = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Settings)
	float Distance = 200.f;

public:
	UPROPERTY(BlueprintAssignable, Category=Hendlers)
	FTargetIsChanged TargetIsChanged;
	
private:
	void TickTraceHandler(float DeltaTime);
	
public:
	UInteractionComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category=Interaction)
	void TryInteract();
};
