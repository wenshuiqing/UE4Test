// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_AssetWidget.h"
#include "GZ_AssetLoad/GZ_AssetActor.h"
#include "Kismet/GameplayStatics.h"
#include "GZ_AssetLoad/GZ_HandleActor.h"
#include "Image.h"
#include "GZ_Helper.h"
#include "GZ_AssetLoad/GZ_HandleWidget.h"

bool UGZ_AssetWidget::Initialize()
{
	//GZHelper::Debug(TEXT("HELLO Initialize"));
	if (!Super::Initialize())return false;

	TArray<AActor*> ActList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGZ_HandleActor::StaticClass(), ActList);
	if (ActList.Num() > 0) {
		AGZ_HandleActor* AssetActor = Cast<AGZ_HandleActor>(ActList[0]);
		AssetActor->AssignWidget(this);
		//GZHelper::Debug(TEXT("HELLO Initialize"));
	}



	return true;
}

void UGZ_AssetWidget::AssignTexture(UTexture2D* InTexture)
{
	TextureImage->SetBrushFromTexture(InTexture);
	//GZHelper::Debug(TEXT("HELLO AssignTexture"));
}

void UGZ_AssetWidget::AssignWidget(UUserWidget* Widget)
{
	//HandleWidget = Cast<UGZ_HandleWidget>( Widget);
}
