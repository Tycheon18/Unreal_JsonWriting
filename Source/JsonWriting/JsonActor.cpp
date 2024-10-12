// Fill out your copyright notice in the Description page of Project Settings.


#include "JsonActor.h"
#include "JsonObjectConverter.h"
#include "Misc/FileHelper.h"


// Sets default values
AJsonActor::AJsonActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJsonActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJsonActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJsonActor::SaveJsonData()
{
	FJsonBaseArray JsonBaseArray;
	JsonBaseArray.JsonBaseArray.Add(CreateJsonBase("One", "This is One", "Black", 1));
	JsonBaseArray.JsonBaseArray.Add(CreateJsonBase("Two", "This is Two", "White", 2));

	FString JsonString;

	RandNum = FMath::RandRange(1, 99999);

	FString Rand = FString::FromInt(RandNum);

	FString Path = "TestJson" + Rand + ".json";

	FJsonObjectConverter::UStructToJsonObjectString(JsonBaseArray, JsonString);
	FFileHelper::SaveStringToFile(*JsonString, *(FPaths::ProjectContentDir() + Path));
}

FJsonBase AJsonActor::CreateJsonBase(FString Name, FString Description, FString Color, int32 Number)
{
	FJsonBase NewJsonBase;
	NewJsonBase.Name = Name;
	NewJsonBase.Description = Description;
	NewJsonBase.Color = Color;
	NewJsonBase.Number = Number;

	return NewJsonBase;
}

