// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GZHUDUserWidget.generated.h"


class UGZ_HPWidget;
/**
 *
 */
UCLASS()
class GZ_TEST_API UGZHUDUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	virtual bool Initialize() override;

public:
	TArray<UGZ_HPWidget*> Arr_HPWidget;

	UPROPERTY(Meta = (BindWidget))
		class UCanvasPanel* RootPanal;

	UPROPERTY(Meta = (BindWidget))
		UGZ_HPWidget* BP_HPWidget;
};
