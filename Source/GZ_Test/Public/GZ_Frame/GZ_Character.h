// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GZ_Character.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_Dynmic_Mutil_OneParam, FString, SectionName);

UCLASS()
class GZ_TEST_API AGZ_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGZ_Character();

	UPROPERTY(BlueprintAssignable,BlueprintCallable,Category="GZ")
	FDelegate_Dynmic_Mutil_OneParam Delegate_Dynmic_Mutil_OneParam;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
