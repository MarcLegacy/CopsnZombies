// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "FindRandomPosition.h"

#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "CopsnZombies/AI/NPCController.h"
#include "CopsnZombies/Utility/Logger.h"

UFindRandomPosition::UFindRandomPosition()
{
    NodeName = TEXT("Find Random Position");

    RandomPositionKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UFindRandomPosition, RandomPositionKey));
}

void UFindRandomPosition::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    RandomPositionKey.ResolveSelectedKey(*GetBlackboardAsset());    // Added safety checks
}

EBTNodeResult::Type UFindRandomPosition::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    const ANPCController* Controller = OwnerComp.GetOwner<ANPCController>();
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return EBTNodeResult::Failed;

    if (const UNavigationSystemV1* NavigationSystem = UNavigationSystemV1::GetCurrent(GetWorld()))
    {
        FNavLocation NavLocation;

        if (NavigationSystem->GetRandomPointInNavigableRadius(Controller->GetPawn()->GetActorLocation(), SearchRadius, NavLocation))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(RandomPositionKey.SelectedKeyName, NavLocation.Location);
        }
    }

    FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    return EBTNodeResult::Succeeded;
}
