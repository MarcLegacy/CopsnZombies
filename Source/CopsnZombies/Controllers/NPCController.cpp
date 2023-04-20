// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "NPCController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CopsnZombies/AI/BlackboardKeys.h"
#include "CopsnZombies/Characters/AICharacter.h"
#include "CopsnZombies/Utility/Logger.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

ANPCController::ANPCController()
{
    PrimaryActorTick.bCanEverTick = true;   // IMPORTANT: Seems that the Perception component won't be updated if this isn't set to true.

    SetupPerception();
}

void ANPCController::BeginPlay()
{
    Super::BeginPlay();

    if (const AAICharacter* NPC = GetPawn<AAICharacter>(); FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__) && FLogger::CheckAndLogIsValidPtr(NPC->GetBehaviorTree(), __FUNCTION__))
    {
        UseBlackboard(NPC->GetBehaviorTree()->BlackboardAsset, BlackboardComponent);
    }
}

void ANPCController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (const AAICharacter* NPC = GetPawn<AAICharacter>(); FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__))
    {
        RunBehaviorTree(NPC->GetBehaviorTree());
    }
}

void ANPCController::SetupPerception()
{
    SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));

    SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
    GetPerceptionComponent()->ConfigureSense(*SightConfig);
    GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());

    HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("Hearing Config"));
    GetPerceptionComponent()->ConfigureSense(*HearingConfig);

    GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ANPCController::OnSenseDetected);
}

void ANPCController::OnSenseDetected(const TArray<AActor*>& UpdatedActors)
{
    if (!FLogger::CheckAndLogIsValidPtr(BlackboardComponent, __FUNCTION__)) return;

    for (AActor* Actor : UpdatedActors)
    {
        FActorPerceptionBlueprintInfo Info;
        GetPerceptionComponent()->GetActorsPerception(Actor, Info);

        for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
        {
            if (Stimulus.IsValid()) // This should avoid the double sense with an unknown sense, but if not, find something else.
            {
                BlackboardComponent->SetValueAsObject(BlackboardKeys::TargetCharacter, Actor);
                BlackboardComponent->SetValueAsBool(BlackboardKeys::IsTargetSeen, Stimulus.WasSuccessfullySensed());
            }
        }
    }
}
