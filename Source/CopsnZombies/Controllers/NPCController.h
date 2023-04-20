// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPCController.generated.h"

class UAISenseConfig_Hearing;
class UAISenseConfig_Sight;

UCLASS()
class COPSNZOMBIES_API ANPCController : public AAIController
{
	GENERATED_BODY()

public:
    ANPCController();

    FORCEINLINE UBlackboardComponent* GetBlackboardComponent() const { return BlackboardComponent; }
    FORCEINLINE UAISenseConfig_Sight* GetSightConfig() const { return SightConfig; }
    FORCEINLINE UAISenseConfig_Hearing* GetHearingConfig() const { return HearingConfig; }

private:
    void BeginPlay() override;
    void OnPossess(APawn* InPawn) override;
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
