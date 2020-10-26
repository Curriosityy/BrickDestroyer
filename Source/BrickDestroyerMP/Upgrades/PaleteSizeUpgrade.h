// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Upgrade.h"
#include "PaleteSizeUpgrade.generated.h"

/**
 * 
 */
class APalete;
UCLASS()
class BRICKDESTROYERMP_API APaleteSizeUpgrade : public AUpgrade
{
	GENERATED_BODY()
public:
	virtual void UpgradeStart(APalete* actor) override;
	virtual void UpgradeEnd(APalete* actor) override;
	
};
