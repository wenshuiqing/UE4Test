// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GZ_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GZ_TEST_API AGZ_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AGZ_GameModeBase();

	void BeginPlay() override;
	
	void Tick(float DeltaSeconds)override;
};
