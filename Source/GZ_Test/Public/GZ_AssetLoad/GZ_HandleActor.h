// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataAsset.h"
#include "GZ_HandleActor.generated.h"

class UStaticMeshComponent;
class UObjectLibrary;
class UGZ_AssetWidget;
class UTexture2D;
struct FStreamableManager;
struct FStreamableHandle;
USTRUCT()
struct FGZ_AssetNode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FName AssetName;
	UPROPERTY(EditAnywhere)
		FStringAssetReference AssetPath;
};



UCLASS()
class GZ_TEST_API UGZ_AssetData :public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<UTexture2D*> AssetTextures;

	UPROPERTY(EditAnywhere)
		TArray<FGZ_AssetNode> AssetGroups;
};


UCLASS()
class GZ_TEST_API AGZ_HandleActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGZ_HandleActor();

public:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		UGZ_AssetData* AssetData;

	UPROPERTY(EditAnywhere)
		FStringAssetReference UObjectPath;

	UPROPERTY(EditAnywhere)
		FStringAssetReference ActorPath;

	UPROPERTY(EditAnywhere)
		FStringAssetReference WidgetPath;
protected:

	FTimerHandle TimerHandle;

	int32 MeshIndex;

	UObjectLibrary* ObjectLibrary;
	TArray<FSoftObjectPath> TexturePath;
	UGZ_AssetWidget * AssetWidget;
	FStreamableManager* StreamableManager;

	TArray<UTexture2D*> TextureGroup;
	int32 TextureIndex;
	TSharedPtr<FStreamableHandle> StreamableHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AssetState();

	void UpdateMesh();

	void ObjectLibratyOperate();

	void AssignWidget(UGZ_AssetWidget* Widget);

	//资源异步加载
	void StreamableManagerOperate();

	//异步加载回调
	void StreamableManagerLoadComplete();

	void UpdateTexture();


	void LoadUObjectBlueprint();

};
