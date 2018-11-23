// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_GameModeBase.h"
#include "GZ_Helper.h"

AGZ_GameModeBase::AGZ_GameModeBase()
{
	
	GZHelper::Debug(TEXT("AGZ_GameModeBase"));
}


void AGZ_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	GZHelper::Debug(TEXT("AGZ_GameModeBase BeginPlay"));
}

void AGZ_GameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	GZHelper::Debug(TEXT("AGZ_GameModeBase Tick"));
}
