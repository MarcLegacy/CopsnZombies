// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;
struct FAIStimulus;

UCLASS()
class COPSNZOMBIES_API ANPCController : public AAIController
{
	GENERATED_BODY()

public:
    ANPCController();

    UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComponent; }
    UAISenseConfig_Sight* GetSightConfig() const { return SightConfig; }
    UAISenseConfig_Hearing* GetHearingConfig() const { return HearingConfig; }

protected:
    void BeginPlay() override;
    void OnPossess(APawn* InPawn) override;

private:
    void SetupPerception();

    UFUNCTION()
        void OnSenseDetected(const TArray<AActor*>& UpdatedActors);

    UPROPERTY()
        UBlackboardComponent* BlackboardComponent = nullptr;

    UPROPERTY()
        UAISenseConfig_Sight* SightConfig = nullptr;

    UPROPERTY()
        UAISenseConfig_Hearing* HearingConfig = nullptr;
};
