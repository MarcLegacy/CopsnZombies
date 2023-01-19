// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "PlayerCharacter.h"

#include "CopsnZombies/HealthComponent.h"
#include "CopsnZombies/Utility/Logger.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Component"));
}

void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void APlayerCharacter::OnMeleeAttack_Implementation()
{
	if (FLogger::CheckAndLogIsValidPtr(MeleeMontage, __FUNCTION__))
	{
		PlayAnimMontage(MeleeMontage);
	}

	// TODO: See if there's a way to do this via hitbox of the hand.



	FHitResult HitResult;
	const FVector TraceStartPosition = GetActorLocation();
	const FVector TraceEndPosition = GetActorLocation() + GetActorForwardVector() * 100.0f;	// TODO: Change hard number.
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStartPosition, TraceEndPosition, ECC_Pawn, QueryParams))
	{
        if (AActor* HitActor = HitResult.GetActor())
	    {
			FDamageEvent DamageEvent;
			HitActor->TakeDamage(5, DamageEvent, GetController(), this);
	    }
	}
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::OnMeleeAttack_Implementation);
}



