// Copyright Blacksheep1337

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UMMC_MaxMana();
	
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition IntDef;
	
	UPROPERTY(EditAnywhere)
	float BaseMaxMana = 50.0f;
	
	UPROPERTY(EditAnywhere)
	float AttributeMultiplier = 2.5f;
	
	UPROPERTY(EditAnywhere)
	float LevelMultiplier = 15.0f;
};
