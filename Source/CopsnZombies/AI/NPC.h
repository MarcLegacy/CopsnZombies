// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

class UBehaviorTree;

UCLASS(Abstract)
class COPSNZOMBIES_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	ANPC();

	UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree;
};
