// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

#include "BehaviorTree/BehaviorTree.h"
#include "CopsnZombies/Utility/Logger.h"

ANPC::ANPC()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ANPC::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(this, BehaviorTree, GET_MEMBER_NAME_CHECKED(ANPC, BehaviorTree));
}


