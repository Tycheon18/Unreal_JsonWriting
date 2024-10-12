// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "JsonActor.generated.h"

USTRUCT(BlueprintType)
struct FJsonBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JsonData")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JsonData")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JsonData")
	FString Color;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JsonData")
	int32 Number;
};

USTRUCT(BlueprintType)
struct FJsonBaseArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JsonData")
	TArray<FJsonBase> JsonBaseArray;
};

UCLASS()
class JSONWRITING_API AJsonActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AJsonActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:

	int32 RandNum;

public:

	UFUNCTION(BlueprintCallable)
	void SaveJsonData();

	UFUNCTION(BlueprintCallable)
	FJsonBase CreateJsonBase(FString Name, FString Description, FString Color, int32 Number);
};
