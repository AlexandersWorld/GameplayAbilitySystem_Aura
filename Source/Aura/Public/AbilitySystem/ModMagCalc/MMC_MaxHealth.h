// Copyright Blacksheep1337

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxHealth.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UMMC_MaxHealth : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UMMC_MaxHealth();
	
	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
	
private:
	FGameplayEffectAttributeCaptureDefinition VigorDef;
	
	UPROPERTY(EditAnywhere)
	float BaseMaxHealth = 80.0f;
	
	UPROPERTY(EditAnywhere)
	float AttributeMultiplier = 2.5f;
	
	UPROPERTY(EditAnywhere)
	float LevelMultiplier = 10.0f;
};
