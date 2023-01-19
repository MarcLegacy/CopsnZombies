// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "CopsnZombies/CopsnZombiesCharacter.h"
#include "CopsnZombies/Interfaces/MeleeInterface.h"
#include "PlayerCharacter.generated.h"

class UHealthComponent;

UCLASS()
class COPSNZOMBIES_API APlayerCharacter : public ACopsnZombiesCharacter, public IMeleeInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	// Returned variable is set in the editor.
	UAnimMontage* GetMeleeMontage() const { return MeleeMontage; }

	UHealthComponent* GetHealtComponent() const { return HealthComponent; }

private:
	void BeginPlay() override;

	void OnMeleeAttack();
	virtual void OnMeleeAttack_Implementation();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* MeleeMontage = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UHealthComponent* HealthComponent = nullptr;
};
