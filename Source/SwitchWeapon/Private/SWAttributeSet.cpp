// Fill out your copyright notice in the Description page of Project Settings.


#include "SWAttributeSet.h"
#include "SwitchWeaponASC.h"
#include "GameplayEffectExtension.h"

void USWAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetMaxHealthAttribute()) {
		AdjustAttributeForMaxChange(Health,MaxHealth,NewValue,GetHealthAttribute());
	}
	if (Attribute == GetMaxStanceAttribute()) {
		AdjustAttributeForMaxChange(Stance, MaxStance, NewValue, GetStanceAttribute());
	}
}

void USWAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
	
	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) {
		SetHealth(FMath::Clamp(GetHealth(),0.0f,GetMaxHealth()));
		USwitchWeaponASC* AbilityComp = dynamic_cast<USwitchWeaponASC*>(GetOwningAbilitySystemComponent());
		AbilityComp->OnGameplayAttributeChanged.Broadcast(GetHealthAttribute(), GetHealth());
	}

	if (Data.EvaluatedData.Attribute == GetStanceAttribute()) {
		SetStance(FMath::Clamp(GetStance(), 0.0f, GetMaxStance()));
		USwitchWeaponASC* AbilityComp = dynamic_cast<USwitchWeaponASC*>(GetOwningAbilitySystemComponent());
		AbilityComp->OnGameplayAttributeChanged.Broadcast(GetStanceAttribute(), GetStance());
	}
}

void USWAttributeSet::AdjustAttributeForMaxChange(FGameplayAttributeData& AffectedAttribute,
												  const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty)
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp)
	{
		// Change current value to maintain the current Val / Max percent
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		float NewDelta = (CurrentMaxValue > 0.f) ? (CurrentValue * NewMaxValue / CurrentMaxValue) - CurrentValue : NewMaxValue;

		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewDelta);
	}
}


