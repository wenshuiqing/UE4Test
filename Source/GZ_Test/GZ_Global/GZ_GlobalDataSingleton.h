// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GZ_GlobalDataSingleton.generated.h"

/**
 * 
 */

class UTexture2D;
UCLASS(Blueprintable,BlueprintType)
class GZ_TEST_API UGZ_GlobalDataSingleton : public UObject
{
	GENERATED_BODY()

public:
	UGZ_GlobalDataSingleton();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
		TArray<UClass*> SourceBlueprints;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
		UTexture2D* Texture;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
		FVector Vect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GZ")
		FString StrPath;

};
