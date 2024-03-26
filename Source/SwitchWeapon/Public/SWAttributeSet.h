// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "SWAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName,PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName,PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class SWITCHWEAPON_API USWAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	//virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(USWAttributeSet,Health)

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(USWAttributeSet, MaxHealth)

	UPROPERTY(BlueprintReadOnly, Category = "Stance")
	FGameplayAttributeData Stance;
	ATTRIBUTE_ACCESSORS(USWAttributeSet, Stance)

	UPROPERTY(BlueprintReadOnly, Category = "Stance")
	FGameplayAttributeData MaxStance;
	ATTRIBUTE_ACCESSORS(USWAttributeSet, MaxStance)

protected:
	void AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty);

	
};
