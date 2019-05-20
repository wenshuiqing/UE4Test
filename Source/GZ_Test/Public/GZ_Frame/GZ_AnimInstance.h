// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GZ_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GZ_TEST_API UGZ_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UGZ_AnimInstance();
	

public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "GZ")
		void PlayAct(const FName SectionName);

public:

	void SetMoveSpeed(float value);
	float GetMoveSpeed();


protected:

	UPROPERTY(BlueprintReadOnly,Category="GZ")
	float MoveSpeed;

};
