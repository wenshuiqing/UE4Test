// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_DelegateActor.h"
#include "GZ_Helper.h"

// Sets default values
AGZ_DelegateActor::AGZ_DelegateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AGZ_DelegateActor::RegFuncDel(FDelegate_Dynmic_Zero TargetFunc)
{
	TargetFunc.ExecuteIfBound();
}

void AGZ_DelegateActor::SetupTFuncOne(TFunction<void(FString)> TargetFuncOne)
{
	TFuncOne = TargetFuncOne;	
	TFuncOne(TEXT("Call TFuncOne"));
}

// Called when the game starts or when spawned
void AGZ_DelegateActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGZ_DelegateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGZ_DelegateActor::Excute_Delegate_OneParamOneRet(FString Content)
{
	GZHelper::Debug(Content);
}

