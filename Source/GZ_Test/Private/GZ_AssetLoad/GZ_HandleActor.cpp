// Fill out your copyright notice in the Description page of Project Settings.

#include "GZ_HandleActor.h"
#include "GZ_Helper.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/ObjectLibrary.h"
#include "GZ_AssetLoad/GZ_AssetWidget.h"
#include "Engine/StreamableManager.h"
#include "Engine/Texture2D.h"
#include "Engine/Blueprint.h"
#include "UserWidget.h"

// Sets default values
AGZ_HandleActor::AGZ_HandleActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGZ_HandleActor::BeginPlay()
{
	Super::BeginPlay();


	ObjectLibratyOperate();
	StreamableManagerOperate();

	LoadUObjectBlueprint();
	//AssetState();

		//更新模型
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, [this]() {UpdateMesh(); }, 1.0f, true);
	//FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AGZ_HandleActor::UpdateMesh);
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 1.0f, true);
}



// Called every frame
void AGZ_HandleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGZ_HandleActor::AssetState()
{
	UStaticMesh* MeshAsset = FindObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));
	if (!MeshAsset)
	{
		GZHelper::Debug(FString("MeshAsset Load fail!!!"));
		LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));
		MeshAsset = FindObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/Resource/SCTanks/Meshes/SK_SCT_Block.SK_SCT_Block'"));
		MeshComp->SetStaticMesh(MeshAsset);
	}
}

void AGZ_HandleActor::UpdateMesh()
{
	if (AssetData&&AssetData->AssetGroups.Num() > 0)
	{
		UStaticMesh* FactMesh = LoadObject<UStaticMesh>(NULL, *AssetData->AssetGroups[MeshIndex].AssetPath.ToString());
		MeshComp->SetStaticMesh(FactMesh);

		MeshIndex = (MeshIndex + 1) >= AssetData->AssetGroups.Num() ? 0 : (MeshIndex + 1);
	}
}

void AGZ_HandleActor::ObjectLibratyOperate()
{
	if (!ObjectLibrary) {
		ObjectLibrary = UObjectLibrary::CreateLibrary(UObject::StaticClass(), false, false);
		ObjectLibrary->AddToRoot();
	}

	ObjectLibrary->LoadAssetDataFromPath(TEXT("/Game/Resource/UI/Texture/MenuTex"));

	TArray<FAssetData> TextureData;
	ObjectLibrary->GetAssetDataList(TextureData);

	for (size_t i = 0; i < TextureData.Num(); i++)
	{
		//GZHelper::Debug(TextureData[i].ToSoftObjectPath().ToString());
		TexturePath.AddUnique(TextureData[i].ToSoftObjectPath());
	}

}

void AGZ_HandleActor::AssignWidget(UGZ_AssetWidget* Widget)
{
	AssetWidget = Widget;
}

void AGZ_HandleActor::StreamableManagerOperate()
{
	//创建加载管理器
	StreamableManager = new FStreamableManager();
	//执行异步回调
	StreamableHandle = StreamableManager->RequestAsyncLoad(TexturePath, FStreamableDelegate::CreateUObject(this, 
		&AGZ_HandleActor::StreamableManagerLoadComplete));


}

void AGZ_HandleActor::StreamableManagerLoadComplete()
{
	if (StreamableHandle->HasLoadCompleted()) {
		
		TArray<UObject*> ObjectList;
		StreamableHandle->GetLoadedAssets(ObjectList);

		for (size_t i = 0; i < ObjectList.Num(); i++)
		{
			UTexture2D* Tex = Cast<UTexture2D>(ObjectList[i]);
			if (Tex) {
				TextureGroup.Add(Tex);
			}
		}
		FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AGZ_HandleActor::UpdateTexture);
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDelegate, 1.0f, true);
		//GZHelper::Debug(FString("HELLO StreamableManagerLoadComplete"));
	}
}

void AGZ_HandleActor::UpdateTexture()
{
	//GZHelper::Debug(FString("HELLO UpdateTexture0"));
	if (!AssetWidget)return;

	AssetWidget->AssignTexture(TextureGroup[TextureIndex]);
	TextureIndex = (TextureIndex + 1) >= TextureGroup.Num() ? 0 : TextureIndex + 1;
	//GZHelper::Debug(FString("HELLO UpdateTexture1"));
}

void AGZ_HandleActor::LoadUObjectBlueprint()
{
	LoadObject<UObject>(NULL, *UObjectPath.GetAssetPathString());
	LoadObject<AActor>(NULL, *ActorPath.GetAssetPathString());
	LoadObject<UUserWidget>(NULL, *WidgetPath.GetAssetPathString());

	UObject* Obj1 = UObjectPath.ResolveObject();
	UObject* Obj2 = ActorPath.ResolveObject();
	UObject* Obj3 = WidgetPath.ResolveObject();

	UBlueprint* Obj11 = Cast<UBlueprint>(Obj1);
	UBlueprint* Obj12 = Cast<UBlueprint>(Obj2);
	UBlueprint* Obj13 = Cast<UBlueprint>(Obj3);

	UObject* InsObject = NewObject<UObject>(this, Obj11->GeneratedClass);
	AActor* InsActor = GetWorld()->SpawnActor<AActor>(Obj12->GeneratedClass, GetActorTransform());
	//UUserWidget* InsWidget = CreateWidget<UUserWidget>(GetWorld(),);
	//AssetWidget->AssignWidget(InsWidget);

}

