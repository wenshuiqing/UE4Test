// Fill out your copyright notice in the Description page of Project Settings.

#include "GZHUDUserWidget.h"
#include "UI/GZ_HPWidget.h"
#include "CanvasPanel.h"
#include "UserWidget.h"
#include <CanvasPanelSlot.h>


bool UGZHUDUserWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}
	BP_HPWidget->SetVisibility(ESlateVisibility::Hidden);
	//UGZ_HPWidget* HpWidget = WidgetTree->ConstructWidget<UGZ_HPWidget>(BP_HPWidget->StaticClass());
	//RootPanal->AddChild(HpWidget);
	UGZ_HPWidget* HPWidget = DuplicateObject<UGZ_HPWidget>(BP_HPWidget, this);
	HPWidget->SetVisibility(ESlateVisibility::Visible);
	UCanvasPanelSlot* HpSlot = RootPanal->AddChildToCanvas(HPWidget);
	HpSlot->SetAnchors(FAnchors(0.5f, 0.5f));
	HpSlot->SetOffsets(FMargin(100, 100, 100, 30));
	return true;
}
