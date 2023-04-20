// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MoveToTarget.generated.h"

UCLASS()
class COPSNZOMBIES_API UMoveToTarget : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMoveToTarget();

private:
	void InitializeFromAsset(UBehaviorTree& Asset) override;

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = Blackboard, meta = (AllowPrivateAccess = "true"))
		FBlackboardKeySelector TargetCharacterKey;
};
