// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_AssetActor.h"
#include "Async.h"
#include "Future.h"

// Sets default values
AGZ_AssetActor::AGZ_AssetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto Funt = Async<int>(EAsyncExecution::Thread, []() {return 123; });
	int res = Funt.Get();

	UE_LOG(LogTemp, Log, TEXT("Async Test %d"), res);
}

// Called when the game starts or when spawned
void AGZ_AssetActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AGZ_AssetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

