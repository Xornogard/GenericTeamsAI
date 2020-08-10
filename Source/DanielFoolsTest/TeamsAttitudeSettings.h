// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GenericTeamAgentInterface.h"
#include "TeamsAIController.h"
#include "TeamsDataTable.h"
#include "TeamsAttitudeSettings.generated.h"

UCLASS(Config = Game, DefaultConfig)
class DANIELFOOLSTEST_API UTeamsAttitudeSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* TeamNamesDataTable;

	UPROPERTY(Category = "Artifical Intelligence", EditAnywhere, BlueprintReadOnly, Config)
	TMap<FName, FTeamAttitude> TeamAttitudes;

	UTeamsAttitudeSettings(const FObjectInitializer& ObjectInitializer);
	static const UTeamsAttitudeSettings* Get();;

	UFUNCTION(Category = "Artifical Intelligence", BlueprintPure)
	static ETeamAttitude::Type GetAttitude(FGenericTeamId Of, FGenericTeamId Towards);

	bool DoTeamSettingsExist(FName ofTeamName, FName towardsTeamName) const;
	bool TryGetTeamName(FGenericTeamId teamId, FName& teamName) const;
	
};
