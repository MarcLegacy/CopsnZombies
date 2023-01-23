// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "NPCController.h"

#include "NPC.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CopsnZombies/Character/AI/BlackBoardKeys.h"
#include "CopsnZombies/Utility/Logger.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"

ANPCController::ANPCController()
{
    SetupPerception();
}

void ANPCController::BeginPlay()
{
    Super::BeginPlay();

    PrimaryActorTick.bCanEverTick = false;

    if (const ANPC* NPC = GetPawn<ANPC>(); FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__) && FLogger::CheckAndLogIsValidPtr(NPC->GetBehaviorTree(), __FUNCTION__))
    {
        UseBlackboard(NPC->GetBehaviorTree()->BlackboardAsset, BlackboardComponent);
    }
}

void ANPCController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (const ANPC* NPC = GetPawn<ANPC>(); FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__))
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
    for (AActor* Actor : UpdatedActors)
    {
        FActorPerceptionBlueprintInfo Info;
        GetPerceptionComponent()->GetActorsPerception(Actor, Info);

        for (const FAIStimulus& Stimulus : Info.LastSensedStimuli)
        {
            BlackboardComponent->SetValueAsVector(BlackboardKeys::TargetPosition, Stimulus.StimulusLocation);
            BlackboardComponent->SetValueAsBool(BlackboardKeys::IsTargetSeen, Stimulus.WasSuccessfullySensed());
        }
    }
}
