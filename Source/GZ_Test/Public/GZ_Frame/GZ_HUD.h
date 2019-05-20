// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GZ_HUD.generated.h"

/**
 *
 */
UCLASS()
class GZ_TEST_API AGZ_HUD : public AHUD
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UGZHUDUserWidget> GZHUDUserWidget;


protected:
	virtual void BeginPlay() override;



};
