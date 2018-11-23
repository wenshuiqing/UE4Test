// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GZ_ReceiveActor.generated.h"

UCLASS()
class GZ_TEST_API AGZ_ReceiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGZ_ReceiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "GZ")
	bool DelegateFunc1(FString content);


	void TFunctionOne(FString content);
	bool TFunctionTwo(FString content);

	void TMemFunPtrTypeOne(FString content);

	void FMethodPtrOne(FString content);
};
