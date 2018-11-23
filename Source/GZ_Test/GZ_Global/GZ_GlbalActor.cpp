// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_GlbalActor.h"
#include "GZ_Global/GZ_GlobalDataSingleton.h"
#include "Public/Common/GZ_Helper.h"
// Sets default values
AGZ_GlbalActor::AGZ_GlbalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGZ_GlbalActor::BeginPlay()
{
	Super::BeginPlay();
	UGZ_GlobalDataSingleton* GlobalDataSingleton = Cast<UGZ_GlobalDataSingleton>(GEngine->GameSingleton);
	GZHelper::Debug(GlobalDataSingleton->StrPath);
}

// Called every frame
void AGZ_GlbalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

