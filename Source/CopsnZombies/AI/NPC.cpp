// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

#include "BehaviorTree/BehaviorTree.h"
#include "Components/WidgetComponent.h"
#include "CopsnZombies/HealthBarWidget.h"
#include "CopsnZombies/HealthComponent.h"
#include "CopsnZombies/Utility/Logger.h"

ANPC::ANPC()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget Component"));
	WidgetComponent->SetupAttachment(RootComponent);
}

void ANPC::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(this, BehaviorTree, GET_MEMBER_NAME_CHECKED(ANPC, BehaviorTree));
}


