// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_InterfaceTest.h"
#include "Public/GZ_Interface/GZ_Interface_Actor.h"
#include "Public/GZ_Interface/GZ_Interface.h"
#include "Kismet/GameplayStatics.h"
#include "GZ_CallInterfaceActor.h"
#include "GZ_CallInterface.h"

// Sets default values
AGZ_InterfaceTest::AGZ_InterfaceTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGZ_InterfaceTest::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> ObjArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGZ_Interface_Actor::StaticClass(), ObjArray);
	if (ObjArray.Num() > 0) {
		IGZ_Interface* InterActor = Cast<IGZ_Interface>(ObjArray[0]);
		//InterActor->//目前这个遇到问题和教程文档的Excute_FuncNmae不一致
	}

	TArray<AActor*> ObjArray1;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGZ_CallInterfaceActor::StaticClass(), ObjArray1);
	if (ObjArray.Num() > 0) {
		IGZ_CallInterface* CallInterActor = Cast<IGZ_CallInterface>(ObjArray1[0]);
		//CallInterActor->//目前这个遇到问题和教程文档的Excute_FuncNmae不一致
	}

}

// Called every frame
void AGZ_InterfaceTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

