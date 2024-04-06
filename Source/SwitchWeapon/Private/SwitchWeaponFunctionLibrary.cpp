// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchWeaponFunctionLibrary.h"

#include "SwitchWeaponCharacterBase.h"

AActor* USwitchWeaponFunctionLibrary::SpawnActorWithShadowFlag(UObject* WorldContextObject,
	TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, bool bIsShadow,
	ESpawnActorCollisionHandlingMethod CollisionHandlingOverride, AActor* Owner)
{
	UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	if (!World || !ActorClass)
	{
		return nullptr;
	}

	// 开始延迟生成Actor
	AActor* Actor = UGameplayStatics::BeginDeferredActorSpawnFromClass(WorldContextObject, ActorClass, SpawnTransform, CollisionHandlingOverride, Owner);

	if (Actor)
	{
		// 检查Actor是否是ASwitchWeaponCharacterBase或其子类的实例
		// 后续思考一下如果有其他的类也可以是shadow，应该怎么修改，先这样
		ASwitchWeaponCharacterBase* SwitchWeaponCharacter = Cast<ASwitchWeaponCharacterBase>(Actor);
		if (SwitchWeaponCharacter && bIsShadow)
		{
			// 如果是，且bIsBlankShadow为true，则设置bIsBlankShadow属性
			SwitchWeaponCharacter->bIsShadow = bIsShadow;
		}

		// 完成生成过程
		UGameplayStatics::FinishSpawningActor(Actor, SpawnTransform);
	}

	return Actor;
}
