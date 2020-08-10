// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamsAttitudeSettings.h"

UTeamsAttitudeSettings::UTeamsAttitudeSettings(const FObjectInitializer& ObjectInitializer)
{

}

const UTeamsAttitudeSettings* UTeamsAttitudeSettings::Get()
{
    return GetDefault<UTeamsAttitudeSettings>();
}

ETeamAttitude::Type UTeamsAttitudeSettings::GetAttitude(FGenericTeamId ofTeamId, FGenericTeamId towardsTeamId)
{
    const UTeamsAttitudeSettings* teamsAttitudeSettings = UTeamsAttitudeSettings::Get();

    FName ofTeamName, towardsTeamName;

    
    if (teamsAttitudeSettings->TryGetTeamName(ofTeamId, ofTeamName) &&
        teamsAttitudeSettings->TryGetTeamName(towardsTeamId, towardsTeamName) &&
        teamsAttitudeSettings->DoTeamSettingsExist(ofTeamName, towardsTeamName))
    {
        auto& attitudes = teamsAttitudeSettings->TeamAttitudes[ofTeamName].Attitudes;

        if (attitudes.Contains(towardsTeamName))
        {
            return attitudes[towardsTeamName];
        }
    }

    return ETeamAttitude::Neutral;
}

bool UTeamsAttitudeSettings::DoTeamSettingsExist(FName ofTeamName, FName towardsTeamName) const
{
    return this->TeamAttitudes.Contains(ofTeamName)
        && this->TeamAttitudes.Contains(towardsTeamName);
}

bool UTeamsAttitudeSettings::TryGetTeamName(FGenericTeamId teamId, FName& teamName) const
{
    TArray<FName> rowNames = this->TeamNamesDataTable->GetRowNames();

    for (int i = 0; i < rowNames.Num(); i++)
    {
        FTeamsData* teamData = this->TeamNamesDataTable->FindRow<FTeamsData>(rowNames[i], "");

        if (teamData != nullptr && teamData->TeamID == teamId.GetId())
        {
            teamName = teamData->TeamName;
            return true;
        }
    }
   
    return false;
}