// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "MeleeAttackTask.h"

#include "CopsnZombies/Characters/AICharacter.h"
#include "CopsnZombies/Components/CombatComponent.h"
#include "CopsnZombies/Controllers/NPCController.h"
#include "CopsnZombies/Utility/Logger.h"

UMeleeAttackTask::UMeleeAttackTask()
{
    NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UMeleeAttackTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ANPCController* Controller = Cast<ANPCController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    const AAICharacter* NPC = Controller->GetPawn<AAICharacter>();
    if (!FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__)) return EBTNodeResult::Failed;

    const UCombatComponent* CombatComponent = NPC->FindComponentByClass<UCombatComponent>();
    if (!FLogger::CheckAndLogIsValidPtr(CombatComponent, __FUNCTION__)) return EBTNodeResult::Failed;

    CombatComponent->MeleeAttack();

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
