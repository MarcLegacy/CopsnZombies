// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "AIModule/Classes/BehaviorTree/Services/BTService_BlackboardBase.h"
#include "UpdateDistanceToTarget.generated.h"

UCLASS()
class COPSNZOMBIES_API UUpdateDistanceToTarget : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
    UUpdateDistanceToTarget();

private:
    void InitializeFromAsset(UBehaviorTree& Asset) override;

    void OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

    UPROPERTY(EditAnywhere, Category = Blackboard, meta = (AllowPrivateAccess))
        FBlackboardKeySelector DistanceToTargetKey;

    UPROPERTY(EditAnywhere, Category = Blackboard, meta = (AllowPrivateAccess))
        FBlackboardKeySelector TargetPositionKey;
};
