// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZ_AssetWidget.generated.h"

/**
 *
 */

class UImage;
class UTexture2D;
class UOverlay;
UCLASS()
class GZ_TEST_API UGZ_AssetWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	bool Initialize()override;

	UPROPERTY( Meta = (BindWidget))
		UImage* TextureImage;
	/*UPROPERTY(Meta = (BindWidget))
		UOverlay* HandleWidget;*/

	void AssignTexture(UTexture2D* InTexture);


	void AssignWidget(UUserWidget* Widget);
};
