// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TeamsAttitudeSettings.h"
#include "DanielFoolsTestGameMode.generated.h"

UCLASS(minimalapi)
class ADanielFoolsTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADanielFoolsTestGameMode();
	virtual void StartPlay();
};



