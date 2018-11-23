// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_Character.h"
#include "GZ_Helper.h"

// Sets default values
AGZ_Character::AGZ_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GZHelper::Debug(TEXT("AGZ_Character"));
}

// Called when the game starts or when spawned
void AGZ_Character::BeginPlay()
{
	Super::BeginPlay();
	GZHelper::Debug(TEXT("AGZ_Character BeginPlay"));
}

// Called every frame
void AGZ_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GZHelper::Debug(TEXT("AGZ_Character Tick"));
}

// Called to bind functionality to input
void AGZ_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

