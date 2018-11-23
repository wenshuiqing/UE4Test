// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_CallInterfaceActor.h"
#include "Public/Common/GZ_Helper.h"
// Sets default values
AGZ_CallInterfaceActor::AGZ_CallInterfaceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGZ_CallInterfaceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGZ_CallInterfaceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGZ_CallInterfaceActor::Func1(const FString& Content)
{
	GZHelper::Debug(Content);
	return true;
}

