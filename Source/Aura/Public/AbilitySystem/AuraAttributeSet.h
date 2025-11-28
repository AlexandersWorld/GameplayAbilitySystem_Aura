// Copyright Blacksheep1337

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "AuraAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()
	
	FEffectProperties() {}
	FEffectProperties(const UAbilitySystemComponent* AbilitySystemComponent, const AActor* SourceAvatarActor, AController* 
		SourceAvatarController, ACharacter* SourceAvatarCharacter, FGameplayEffectContextHandle* EffectContextHandle)
		: SourceASC(SourceASC), SourceAvatarActor(SourceAvatarActor), SourceAvatarController(SourceAvatarController),
			SourceAvatarCharacter(SourceAvatarCharacter), EffectContextHandle(EffectContextHandle)
	{
		
	};
	
	struct FGameplayEffectContextHandle* EffectContextHandle;
	
	UPROPERTY()
	const class UAbilitySystemComponent* SourceASC = nullptr;
	UPROPERTY()
	const class AActor* SourceAvatarActor = nullptr;
	UPROPERTY()
	class AController* SourceAvatarController = nullptr;
	UPROPERTY()
	class ACharacter* SourceAvatarCharacter = nullptr;
	
	UPROPERTY()
	const class UAbilitySystemComponent* TargetASC = nullptr;
	UPROPERTY()
	const class AActor* TargetAvatarActor = nullptr;
	UPROPERTY()
	class AController* TargetAvatarController = nullptr;
	UPROPERTY()
	class ACharacter* TargetAvatarCharacter = nullptr;
};
	
/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual  void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;	
	void SetEffectProperties(const struct FGameplayEffectModCallbackData& Data, FEffectProperties& Props);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Vital Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Vital Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
