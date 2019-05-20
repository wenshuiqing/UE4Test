// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_HUD.h"
#include "UI/GZHUDUserWidget.h"

void AGZ_HUD::BeginPlay()
{
	Super::BeginPlay();


	UGZHUDUserWidget* HUDWidget = CreateWidget<UGZHUDUserWidget>(GetWorld(), GZHUDUserWidget);

	HUDWidget->AddToViewport();
}
