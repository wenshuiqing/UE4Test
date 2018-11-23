// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GZ_CallInterface.h"
#include "GZ_CallInterfaceActor.generated.h"

UCLASS()
class GZ_TEST_API AGZ_CallInterfaceActor : public AActor,public IGZ_CallInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGZ_CallInterfaceActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual bool Func1(const FString& Content) override;

};
