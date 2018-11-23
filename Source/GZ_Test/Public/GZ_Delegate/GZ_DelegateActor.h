// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GZ_DelegateActor.generated.h"

DECLARE_DELEGATE(Delegate_Zero)
DECLARE_DELEGATE_OneParam(Delegate_One, FString)
DECLARE_DELEGATE_RetVal(bool, Delegate_RetBool)
DECLARE_DELEGATE_RetVal_OneParam(bool, Delegate_OneParamOneRet, FString)

DECLARE_MULTICAST_DELEGATE(Delegate_Mutil_Zero)

DECLARE_DYNAMIC_DELEGATE(FDelegate_Dynmic_Zero);//动态委托的名字必须以F开头
DECLARE_DYNAMIC_DELEGATE_OneParam(FDelegate_Dynmic_One, FString, Content);
DECLARE_DYNAMIC_DELEGATE_RetVal(bool, FDelegate_Dynmic_Ret);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegate_Dynmic_Mutil_One, FString, Content);


UCLASS()
class GZ_TEST_API AGZ_DelegateActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGZ_DelegateActor();

private:
	TFunction<void(FString)> TFuncOne;
public:
	UPROPERTY(BlueprintAssignable, Category = "GZ")//BlueprintAssignable这个属性只能在蓝图指定多播委托
		FDelegate_Dynmic_Mutil_One Dynmic_Mutil_One;

	UFUNCTION(BlueprintCallable, Category = "GZ")
		void RegFuncDel(FDelegate_Dynmic_Zero TargetFunc);


	void SetupTFuncOne(TFunction<void(FString)> TargetFuncOne);

	template<class UserClass>
	void SetupDelegateDynamicOneParam(UserClass* UserObj,typename TMemFunPtrType<false, UserClass, void(FString)>::Type TargetFunc);

	template<class UserClass>
	void SetupDelegateOneParam1(UserClass* UserObj, typename Delegate_One::TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc);

	template<typename DelegateType, class UserClass,typename... VarsTypes>
	void SetupDelegateOneParam2(UserClass* UserObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc, VarsTypes... Vars);

	template<typename DelegateType, class UserClass>
	void SetupDelegateOneParam3(UserClass* UserObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc);

	template<typename RetType, typename... VarsTypes>
	void SetupTFuncTwo(TFunction<RetType(VarsTypes... Vars)> TargetFuncOne);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	UFUNCTION(BlueprintCallable, Category = "GZ")
		void Excute_Delegate_OneParamOneRet(FString Content);
};

template<class UserClass>
void AGZ_DelegateActor::SetupDelegateDynamicOneParam(UserClass* UserObj, typename TMemFunPtrType<false, UserClass, void(FString)>::Type TargetFunc)
{
	Delegate_Zero Exc;
	Exc.BindUObject(UserObj,TargetFunc,FString("Call Delegate_Dynmic_One"));
	Exc.ExecuteIfBound();
}

template<class UserClass>
void AGZ_DelegateActor::SetupDelegateOneParam1(UserClass* UserObj, typename Delegate_One::TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc)
{
	Delegate_One Exc;
	Exc.BindUObject(UserObj, TargetFunc);
	Exc.ExecuteIfBound(FString("Call Delegate_One"));
}

template<typename DelegateType, class UserClass,  typename... VarsTypes>
void AGZ_DelegateActor::SetupDelegateOneParam2(UserClass* UserObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc, VarsTypes... Vars)
{
	Delegate_Zero Exc;
	Exc.BindUObject(UserObj, TargetFunc, Vars...);
	Exc.ExecuteIfBound();
}

template<typename DelegateType, class UserClass>
void AGZ_DelegateActor::SetupDelegateOneParam3(UserClass* UserObj, typename DelegateType::template TUObjectMethodDelegate<UserClass>::FMethodPtr TargetFunc)
{
	//方法二 ,延迟传递参数
	DelegateType Exc;
	Exc.BindUObject(UserObj, TargetFunc);
	Exc.ExecuteIfBound(FString("Call DelegateOneParam2"));
}

template<typename RetType, typename... VarsTypes>
void AGZ_DelegateActor::SetupTFuncTwo(TFunction<RetType(VarsTypes...)> TargetFuncOne)
{
	RetType ret =  TargetFuncOne(FString("Call TFuncTwo"));//这里必须提前知道方法是什么类型，有缺陷
}

