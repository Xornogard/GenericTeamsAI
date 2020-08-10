// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "TeamsDataTable.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTeamsData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName TeamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		uint8 TeamID;
};

UCLASS()
class DANIELFOOLSTEST_API UTeamsDataTable : public UDataTable
{
	GENERATED_BODY()
	
};
