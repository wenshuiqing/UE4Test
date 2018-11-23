// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_GameInstance.h"
#include "GZ_Helper.h"

UGZ_GameInstance::UGZ_GameInstance()
{
	//FTickerDelegate delegate = FTickerDelegate::CreateUObject(this, &UGZ_GameInstance::Tick);
	
	GZHelper::Debug(TEXT("UGZ_GameInstance"));
}

void UGZ_GameInstance::Init()
{
	Super::Init();
	GZHelper::Debug(TEXT("UGZ_GameInstance Init"));
}

void UGZ_GameInstance::Tick(float DeltaSeconds)
{
	//GZHelper::Debug(TEXT("UGZ_GameInstance Tick"));
}

TStatId UGZ_GameInstance::GetStatId() const
{
	TStatId s;
	return s;
}
