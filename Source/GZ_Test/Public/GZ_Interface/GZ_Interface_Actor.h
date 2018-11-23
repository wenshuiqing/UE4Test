// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GZ_Interface.h"
#include "GZ_Interface_Actor.generated.h"

UCLASS()
class GZ_TEST_API AGZ_Interface_Actor : public AActor,public IGZ_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGZ_Interface_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual int Func4_Implementation(const FString& Content)override;

};
