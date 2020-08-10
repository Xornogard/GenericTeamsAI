// Fill out your copyright notice in the Description page of Project Settings.


#include "NameDataGenericTeam.h"

void ANameDataGenericTeam::SetTeamName(FTeamsData data)
{
	this->m_TeamName = data.TeamName;

	if (m_TeamID != nullptr && m_TeamID->GetId() != data.TeamID)
	{
		delete m_TeamID;
		m_TeamID = new FGenericTeamId(data.TeamID);
	}
	else
	{
		m_TeamID = new FGenericTeamId(data.TeamID);
	}
}
