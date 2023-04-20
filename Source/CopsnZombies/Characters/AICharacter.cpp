// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"

#include "BehaviorTree/BehaviorTree.h"
#include "CopsnZombies/Utility/Logger.h"

AAICharacter::AAICharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAICharacter::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(this, BehaviorTree, GET_MEMBER_NAME_CHECKED(AAICharacter, BehaviorTree));
}


