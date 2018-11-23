// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_ReceiveActor.h"
#include "GZ_Delegate/GZ_DelegateActor.h"
#include "Kismet/GameplayStatics.h"
#include "GZ_Helper.h"

// Sets default values
AGZ_ReceiveActor::AGZ_ReceiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGZ_ReceiveActor::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> ActArray;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AGZ_DelegateActor::StaticClass(), ActArray);
	if (ActArray.Num() > 0) {
		AGZ_DelegateActor* Tar = Cast<AGZ_DelegateActor>(ActArray[0]);


		//����һ��TFunction ���ݺ���
		//Tar->SetupTFuncOne([this](FString Content) {TFunctionOne(Content); });

		//��������TMemFunPtrType ���ݺ���

		//Tar->SetupDelegateDynamicOneParam(this, &AGZ_ReceiveActor::TMemFunPtrTypeOne);

		//��������FMethodPtr ���ݺ���
		//Tar->SetupDelegateOneParam1(this, &AGZ_ReceiveActor::FMethodPtrOne);

		//������ FMethodPtr��չ
		DECLARE_DELEGATE_OneParam(FDelegate_OneParam,FString)
		//Tar->SetupDelegateOneParam2<FDelegate_OneParam>(this, &AGZ_ReceiveActor::FMethodPtrOne, FString("Call DelegateOneParam2"));
		Tar->SetupDelegateOneParam3<FDelegate_OneParam>(this, &AGZ_ReceiveActor::FMethodPtrOne);//�ӳٴ��ݲ���


		//�����壺TFunction ��չ
		//Tar->SetupTFuncTwo<bool, FString>([this](FString Content) {return TFunctionTwo(Content); });

	}
}

// Called every frame
void AGZ_ReceiveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGZ_ReceiveActor::DelegateFunc1(FString content)
{
	GZHelper::Debug(content);
	return true;
}

void AGZ_ReceiveActor::TFunctionOne(FString content)
{
	GZHelper::Debug(content);
}

bool AGZ_ReceiveActor::TFunctionTwo(FString content)
{
	GZHelper::Debug(content);
	return true;
}

void AGZ_ReceiveActor::TMemFunPtrTypeOne(FString content)
{
	GZHelper::Debug(content);
}

void AGZ_ReceiveActor::FMethodPtrOne(FString content)
{
	GZHelper::Debug(content);
}

