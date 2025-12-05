// Copyright Blacksheep1337

#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag,
	const bool bLogNotFound) const
{
	for (const FAuraInputAction& Action : AbilityInputActions)
	{
		if (Action.InputTag.MatchesTag(InputTag) && Action.InputAction)
		{
			return Action.InputAction;
		}
	}
	
	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Display, TEXT("Ability dont found with tag [%s]") , *InputTag.ToString());
	}
	
	return nullptr;
}
