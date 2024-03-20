// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SwitchWeaponASC.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTagUpdatedDel,const FGameplayTag&,Tag, bool, TagExists);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGameplayAbilityEndedDel_Blueprint, const UGameplayAbility*,AbilityReference,bool,wasCancelled);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChanged, FGameplayAttribute, Attribute, float, Value);
/**
 * 
 */
UCLASS(ClassGroup = AbilitySystem, hidecategories = (Object, LOD, Lighting, Transform, Sockets, TextureStreaming), editinlinenew, meta = (BlueprintSpawnableComponent))
class SWITCHWEAPON_API USwitchWeaponASC : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	//技能表格
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Skills")
	UDataTable* DataTable;
	//tag变化回调事件
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = GameplayTags)
	virtual void OnTagUpdated(const FGameplayTag& Tag, bool TagExists) override;

	UPROPERTY(BlueprintAssignable, Category = "Skills")
	FOnTagUpdatedDel OnTagUpdatedDelegate;

	//技能结束回调事件
	void AbilityEndTransfer(const FAbilityEndedData&);

	UPROPERTY(BlueprintAssignable, Category = "Skills")
	FGameplayAbilityEndedDel_Blueprint OnAbilityEnded_BlueprintCallable;
	//属性改变回调事件

	UPROPERTY(BlueprintAssignable, Category = GameplayAttributes)
	FOnAttributeChanged OnGameplayAttributeChanged;
};

USTRUCT(BlueprintType)
struct FEunDatas :public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FEunDatas() {}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EunDatas")
	TSubclassOf<UGameplayAbility> AbilityClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EunDatas")
	FGameplayTag AbilityTag;

};
