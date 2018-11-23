// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_Interface_Actor.h"
#include "Public/Common/GZ_Helper.h"

// Sets default values
AGZ_Interface_Actor::AGZ_Interface_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGZ_Interface_Actor::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AGZ_Interface_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AGZ_Interface_Actor::Func4_Implementation(const FString& Content)
{
	GZHelper::Debug(Content);
	return 0;
}

