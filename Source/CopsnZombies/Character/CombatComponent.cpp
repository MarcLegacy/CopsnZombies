// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "CombatComponent.h"

#include "CopsnZombies/Utility/Logger.h"
#include "GameFramework/Character.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCombatComponent::MeleeAttack() const
{
	ACharacter* OwnerCharacter = GetOwner<ACharacter>();

	if (!FLogger::CheckAndLogIsValidPtr(MeleeMontage, __FUNCTION__) || !FLogger::CheckAndLogIsValidPtr(OwnerCharacter, __FUNCTION__) || !OwnerCharacter->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(MeleeMontage)) return;

	OwnerCharacter->PlayAnimMontage(MeleeMontage, MeleeSpeed);

	// TODO: See if there's a way to do this via hitbox of the hand.

	FHitResult HitResult;
	const FVector TraceStartPosition = OwnerCharacter->GetActorLocation();
	const FVector TraceEndPosition = OwnerCharacter->GetActorLocation() + OwnerCharacter->GetActorForwardVector() * 100.0f;	// TODO: Change hard number.
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetOwner());

	if (GetWorld()->LineTraceSingleByChannel(HitResult, TraceStartPosition, TraceEndPosition, ECC_Pawn, QueryParams))
	{
		if (AActor* HitActor = HitResult.GetActor())
		{
			FDamageEvent DamageEvent;
			HitActor->TakeDamage(MeleeDamageAmount, DamageEvent, OwnerCharacter->GetController(), GetOwner());
		}
	}
}

void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	FLogger::CheckAndLogIsPropertySet(GetOwner(), MeleeMontage, GET_MEMBER_NAME_CHECKED(UCombatComponent, MeleeMontage));
}



