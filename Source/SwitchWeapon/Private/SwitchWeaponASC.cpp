// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchWeaponASC.h"

void USwitchWeaponASC::BeginPlay()
{
	Super::BeginPlay();



	//--读取表格参数--
	FString ContextStr;
	TArray<FName> RowNames;
	if (DataTable) {
		RowNames = DataTable->GetRowNames();
	}
	
	for (auto& name : RowNames)
	{
		//FEunDatas 为自定义格式的数据表
		FEunDatas* pRow = DataTable->FindRow<FEunDatas>(name, ContextStr);
		if (pRow)
		{
			FGameplayAbilitySpec Spec(pRow->AbilityClass);
			GiveAbility(Spec);
		}
		else
		{
		}
	}
	//--读取完毕

	OnAbilityEnded.AddUObject(this, &USwitchWeaponASC::AbilityEndTransfer);
}

void USwitchWeaponASC::OnTagUpdated(const FGameplayTag& Tag, bool TagExists) {
	Super::OnTagUpdated(Tag, TagExists);
	OnTagUpdatedDelegate.Broadcast(Tag, TagExists);
}

void USwitchWeaponASC::AbilityEndTransfer(const FAbilityEndedData& Data)
{
	OnAbilityEnded_BlueprintCallable.Broadcast(Data.AbilityThatEnded,Data.bWasCancelled);

}

