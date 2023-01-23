// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MeleeAttackTask.generated.h"

UCLASS()
class COPSNZOMBIES_API UMeleeAttackTask : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UMeleeAttackTask();

private:
    EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
