// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GZ_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GZ_TEST_API AGZ_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AGZ_PlayerController();

	void BeginPlay()override;
	
	void Tick(float DeltaSeconds)override;
};
