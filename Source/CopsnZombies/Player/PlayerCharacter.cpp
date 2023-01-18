// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "PlayerCharacter.h"

#include "CopsnZombies/Utility/Logger.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APlayerCharacter::OnMeleeAttack_Implementation()
{
	if (FLogger::CheckAndLogIsValidPtr(MeleeMontage, __FUNCTION__))
	{
		PlayAnimMontage(MeleeMontage);
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::OnMeleeAttack_Implementation);
}



