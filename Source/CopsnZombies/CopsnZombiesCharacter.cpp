// Copyright Epic Games, Inc. All Rights Reserved.

#include "CopsnZombiesCharacter.h"

#include "HealthComponent.h"
#include "Components/WidgetComponent.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"


ACopsnZombiesCharacter::ACopsnZombiesCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));

	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget Component"));
	WidgetComponent->SetupAttachment(RootComponent);
	WidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);	// Makes sure it draws towards the player's camera
	WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));

	//Stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("Stimulus"));
	//Stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	//Stimulus->RegisterWithPerceptionSystem();
}

