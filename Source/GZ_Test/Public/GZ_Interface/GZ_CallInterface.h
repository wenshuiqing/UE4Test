// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GZ_CallInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI,meta=(CannotImplementInterfaceInBlueprint))
class UGZ_CallInterface : public UInterface
{
	//GENERATED_BODY()
	GENERATED_UINTERFACE_BODY()
		//构造函数只用定义不用声明，只写CPP文件
};

/**
 * 
 */
class GZ_TEST_API IGZ_CallInterface
{
	//GENERATED_BODY()
	GENERATED_IINTERFACE_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, Category = "GZ")
		virtual bool Func1(const FString& Content)=0;//必须表示为纯虚方法
};
