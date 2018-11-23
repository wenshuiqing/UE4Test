// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GZ_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI,Blueprintable,BlueprintType)
class UGZ_Interface : public UInterface
{
	//GENERATED_BODY()//����������������Ͷ��幹��
	GENERATED_UINTERFACE_BODY()
};

/**
 * 
 */
class GZ_TEST_API IGZ_Interface
{
	//GENERATED_BODY()
	GENERATED_IINTERFACE_BODY()
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "GZ")
		void Func1(const FString& Content);//��������������,�¼��ķ���ֵ����Ϊvoid

	UFUNCTION(BlueprintImplementableEvent, Category = "GZ")
		void Func2(const int& Value);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GZ")
		void Func3(const FString& Content);

	UFUNCTION(BlueprintNativeEvent, Category = "GZ")
		int Func4(const FString& Content);

	UFUNCTION(BlueprintImplementableEvent, Category = "GZ")
		void Func5();
};
