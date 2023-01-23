// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class COPSNZOMBIES_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();

	FORCEINLINE UAnimMontage* GetMeleeMontage() const { return MeleeMontage; }
	
	void MeleeAttack() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MeleeDamageAmount = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MeleeSpeed = 1;

private:
	void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* MeleeMontage = nullptr;
};
