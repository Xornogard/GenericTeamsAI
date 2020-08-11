// Fill out your copyright notice in the Description page of Project Settings.


#include "TeamsAIController.h"

ATeamsAIController::ATeamsAIController()
{
	m_TeamID = new FGenericTeamId();
}

ATeamsAIController::~ATeamsAIController()
{
	if (m_TeamID != NULL)
	{
		delete m_TeamID;
	}
}

void ATeamsAIController::SetTeamName(FTeamsData data)
{
	m_TeamName = data.TeamName;

	if (m_TeamID != NULL && m_TeamID->GetId() != data.TeamID)
	{
		delete m_TeamID;
		m_TeamID = new FGenericTeamId(data.TeamID);
	}
	else
	{
		m_TeamID = new FGenericTeamId(data.TeamID);
	}
}

ETeamAttitude::Type ATeamsAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	if (const APawn* OtherPawn = Cast<APawn>(&Other)) 
	{
		if (const IGenericTeamAgentInterface* TeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController()))
		{
			return FGenericTeamId::GetAttitude(*m_TeamID, TeamAgent->GetGenericTeamId());
		}
	}

	return ETeamAttitude::Neutral;
}