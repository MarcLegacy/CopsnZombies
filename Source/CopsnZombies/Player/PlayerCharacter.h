// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "CopsnZombies/CopsnZombiesCharacter.h"
#include "CopsnZombies/Interfaces/MeleeInterface.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class COPSNZOMBIES_API APlayerCharacter : public ACopsnZombiesCharacter, public IMeleeInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	// Returned variable is set in the editor.
	UAnimMontage* GetMontage() const { return MeleeMontage; }
private:
	void OnMeleeAttack();
	virtual void OnMeleeAttack_Implementation();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* MeleeMontage;
};
