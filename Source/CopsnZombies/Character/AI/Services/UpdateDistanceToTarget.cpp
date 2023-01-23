// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "UpdateDistanceToTarget.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "CopsnZombies/AI/NPC.h"
#include "CopsnZombies/AI/NPCController.h"
#include "CopsnZombies/Utility/Logger.h"
#include "Kismet/GameplayStatics.h"

UUpdateDistanceToTarget::UUpdateDistanceToTarget()
{
    NodeName = TEXT("Update Distance To Target");
    bNotifyBecomeRelevant = true;

    DistanceToTargetKey.AddFloatFilter(this, GET_MEMBER_NAME_CHECKED(UUpdateDistanceToTarget, DistanceToTargetKey));
    TargetPositionKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UUpdateDistanceToTarget, TargetPositionKey));
}

void UUpdateDistanceToTarget::InitializeFromAsset(UBehaviorTree& Asset)
{
    Super::InitializeFromAsset(Asset);

    const UBlackboardData* BlackboardData = GetBlackboardAsset();

    DistanceToTargetKey.ResolveSelectedKey(*BlackboardData);
    TargetPositionKey.ResolveSelectedKey(*BlackboardData);
}

void UUpdateDistanceToTarget::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::OnBecomeRelevant(OwnerComp, NodeMemory);

    const ANPCController* Controller = Cast<ANPCController>(OwnerComp.GetAIOwner());
    if (!FLogger::CheckAndLogIsValidPtr(Controller, __FUNCTION__)) return;

    const ANPC* NPC = Controller->GetPawn<ANPC>();
    if (!FLogger::CheckAndLogIsValidPtr(NPC, __FUNCTION__)) return;

    const FVector TargetPosition = OwnerComp.GetBlackboardComponent()->GetValueAsVector(TargetPositionKey.SelectedKeyName);

    OwnerComp.GetBlackboardComponent()->SetValueAsFloat(DistanceToTargetKey.SelectedKeyName, FVector::Dist(NPC->GetActorLocation(), TargetPosition));
}
