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