// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Upgrade.h"
#include <BrickDestroyerMP\PaletePlayerState.h>
#include "NewBallUpgrade.generated.h"

/**
 * 
 */
UCLASS()
class BRICKDESTROYERMP_API ANewBallUpgrade : public AUpgrade
{
	GENERATED_BODY()
public:

		virtual void UpgradeStart(APalete* actor) override;
		virtual void UpgradeEnd(APalete* actor) override;
};
