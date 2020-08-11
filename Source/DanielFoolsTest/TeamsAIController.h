// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "NameDataGenericTeam.h"
#include "AIController.h"
#include "TeamsAIController.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTeamAttitude
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TMap<FName,TEnumAsByte<ETeamAttitude::Type>> Attitudes;

	FTeamAttitude() { };
	static FTeamAttitude Create();
};

UCLASS()
class DANIELFOOLSTEST_API ATeamsAIController : public AAIController
{
	GENERATED_BODY()

public:

	ATeamsAIController();
	~ATeamsAIController();

	UFUNCTION(BlueprintCallable)
		void SetTeamName(FTeamsData data);

	virtual FGenericTeamId GetGenericTeamId() const { return *m_TeamID; }
	ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

private:

	//Generic Team Interface
	FName m_TeamName;
	FGenericTeamId* m_TeamID;
};
