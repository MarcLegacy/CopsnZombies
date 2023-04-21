// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "CopsnZombies/Characters/CopsnZombiesCharacter.h"
#include "AICharacter.generated.h"

class UBehaviorTree;
class UStateTree;

UCLASS()
class COPSNZOMBIES_API AAICharacter : public ACopsnZombiesCharacter
{
	GENERATED_BODY()

public:
	AAICharacter();

	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }
    FORCEINLINE UStateTree* GetStateTree() const { return StateTree; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree = nullptr;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
        UStateTree* StateTree = nullptr;
};
