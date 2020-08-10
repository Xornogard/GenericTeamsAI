// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GenericTeamAgentInterface.h"
#include "TeamsDataTable.h"
/**
 * 
 */
class DANIELFOOLSTEST_API ANameDataGenericTeam
{
public:

	UPROPERTY(EditAnywhere)
	UTeamsDataTable* TeamsDataTable;

	UFUNCTION(BlueprintCallable)
	void SetTeamName(FTeamsData data);

	virtual FGenericTeamId GetGenericTeamId() const { return *m_TeamID; }

private:

	//Generic Team Interface
	FName m_TeamName;
	FGenericTeamId* m_TeamID;
};
