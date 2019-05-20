// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_HPWidget.h"

UGZ_HPWidget::UGZ_HPWidget(const FObjectInitializer& Initializer):Super(Initializer)
{

}

bool UGZ_HPWidget::Initialize()
{
	if (!Super::Initialize())
	{
		return false;
	}


	return true;
}
