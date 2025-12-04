// Copyright Blacksheep1337


#include "UI/WidgetController/AttributeMenuWidgetController.h"

#include "AuraGameplayTags.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);
	
	check(AttributeInfo);
	
	for (auto& Pair :  AuraAttributeSet->TagsToAttributes)
	{
		FAuraAttributeInfo AuraAttributeInfo = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
		
		AuraAttributeInfo.AttributeValue = Pair.Value().GetNumericValue(AuraAttributeSet);
		
		AttributeInfoDelegate.Broadcast(AuraAttributeInfo);
	}
}
