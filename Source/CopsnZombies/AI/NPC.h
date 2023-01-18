// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"

class UBehaviorTree;

UCLASS()
class COPSNZOMBIES_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	ANPC();

	UBehaviorTree* GetBehaviorTree() const { return BehaviorTree; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* BehaviorTree;
};
