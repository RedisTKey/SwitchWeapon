// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SwitchWeaponCharacterBase.generated.h"

UCLASS()
class SWITCHWEAPON_API ASwitchWeaponCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASwitchWeaponCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//用来管理生成的是否为残影
	UPROPERTY(BlueprintReadWrite, Category="Character Properties")
	bool bIsShadow = false;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
