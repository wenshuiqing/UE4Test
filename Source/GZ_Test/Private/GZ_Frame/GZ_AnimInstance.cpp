// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_AnimInstance.h"

UGZ_AnimInstance::UGZ_AnimInstance()
{

}

void UGZ_AnimInstance::SetMoveSpeed(float value)
{
	MoveSpeed = value;
}

float UGZ_AnimInstance::GetMoveSpeed()
{
	return MoveSpeed;
}
