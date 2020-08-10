// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DanielFoolsTestGameMode.h"
#include "DanielFoolsTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADanielFoolsTestGameMode::ADanielFoolsTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ADanielFoolsTestGameMode::StartPlay()
{
	FGenericTeamId::SetAttitudeSolver(&UTeamsAttitudeSettings::GetAttitude);
	AGameModeBase::StartPlay();
}
