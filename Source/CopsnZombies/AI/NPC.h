// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "CopsnZombies/CopsnZombiesCharacter.h"
#include "NPC.generated.h"

class UBehaviorTree;

UCLASS()
class COPSNZOMBIES_API ANPC : public ACopsnZombiesCharacter
{
	GENERATED_BODY()

public:
	ANPC();

	FORCEINLINE UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree = nullptr;
};
