// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_PlayerController.h"
#include "GZ_Helper.h"

AGZ_PlayerController::AGZ_PlayerController()
{
	GZHelper::Debug(TEXT("AGZ_PlayerController"));
}

void AGZ_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	GZHelper::Debug(TEXT("AGZ_PlayerController BeginPlay"));
}

void AGZ_PlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GZHelper::Debug(TEXT("AGZ_PlayerController Tick"));
}

