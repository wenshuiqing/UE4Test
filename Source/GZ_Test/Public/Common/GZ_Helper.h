// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/Engine.h"
#include "GZ_Helper.generated.h"


namespace GZHelper {
	FORCEINLINE void Debug(FString content, float duration = 100.0f) {
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, duration, FColor::Green, content);
	}
}

/**
 * 
 */
UCLASS()
class GZ_TEST_API UGZ_Helper : public UObject
{
	GENERATED_BODY()
	
};
