// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "SwitchWeaponFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SWITCHWEAPON_API USwitchWeaponFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
public:
	UFUNCTION(BlueprintCallable, Category = "Character Spawning", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "ActorClass"))
	static AActor* SpawnActorWithShadowFlag(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, bool bIsShadow, ESpawnActorCollisionHandlingMethod CollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::Undefined, 
		AActor* Owner = nullptr);
};
