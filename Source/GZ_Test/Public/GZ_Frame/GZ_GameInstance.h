// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GZ_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GZ_TEST_API UGZ_GameInstance : public UGameInstance,public FTickableGameObject
{
	GENERATED_BODY()
	
public:
	UGZ_GameInstance();

	void Init()override;

	virtual void Tick(float DeltaSeconds);

	virtual TStatId GetStatId() const override;
};
