// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "MoveToTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "CopsnZombies/CopsnZombiesCharacter.h"
#include "CopsnZombies/AI/NPC.h"
#include "CopsnZombies/AI/NPCController.h"
#include "CopsnZombies/Utility/Logger.h"

UMoveToTarget::UMoveToTarget()
{
    NodeName = TEXT("Move To Target");

    TargetCharacterKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UMoveToTarget, TargetCharacterKey), UObject::StaticClass());
}

void UMoveToTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    TargetCharacterKey.ResolveSelectedKey(*GetBlackboardAsset());
}

EBTNodeResult::Type UMoveToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
     ANPCController* Controller = OwnerComp.GetOwner<ANPCController>();
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    ACopsnZombiesCharacter* TargetCharacter = Cast<ACopsnZombiesCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(TargetCharacterKey.SelectedKeyName));
    if (!FLogger::CheckAndLogIsValidPtr(TargetCharacter, __FUNCTION__)) return EBTNodeResult::Failed;

    Controller->MoveToActor(TargetCharacter);

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}