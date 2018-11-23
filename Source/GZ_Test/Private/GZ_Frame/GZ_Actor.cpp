// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_Actor.h"
#include "Components/SphereComponent.h"
#include "GZ_Helper.h"
// Sets default values
AGZ_Actor::AGZ_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));

	GZHelper::Debug(TEXT("AGZ_Actor"));
}

// Called when the game starts or when spawned
void AGZ_Actor::BeginPlay()
{
	Super::BeginPlay();
	GZHelper::Debug(TEXT("AGZ_Actor BeginPlay"));
}

// Called every frame
void AGZ_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GZHelper::Debug(TEXT("AGZ_Actor Tick"));
}

