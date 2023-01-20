// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "CopsnZombies/CopsnZombiesCharacter.h"
#include "CopsnZombies/Interfaces/MeleeInterface.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class COPSNZOMBIES_API APlayerCharacter : public ACopsnZombiesCharacter, public IMeleeInterface
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	// Returned variable is set in the editor.
	FORCEINLINE UAnimMontage* GetMeleeMontage() const { return MeleeMontage; }
	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; }

private:
	void BeginPlay() override;

	void OnMeleeAttack();
	virtual void OnMeleeAttack_Implementation();

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAnimMontage* MeleeMontage = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;
};
