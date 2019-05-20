// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZ_HPWidget.generated.h"

/**
 *
 */
UCLASS()
class GZ_TEST_API UGZ_HPWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UGZ_HPWidget(const FObjectInitializer& Initializer);



	virtual bool Initialize() override;
public:

	UPROPERTY(Meta = (BindWidget))
		class UProgressBar* Bg_Bar;

	UPROPERTY(Meta = (BindWidget))
		class UProgressBar* Health_Bar;
};
