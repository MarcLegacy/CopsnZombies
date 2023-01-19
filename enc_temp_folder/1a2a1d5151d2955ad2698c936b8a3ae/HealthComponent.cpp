// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "HealthComponent.h"

#include "Utility/Logger.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
    AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	if (CurrentHealth == 0.0f)
	{
		FOnActorDeath.Broadcast();
	}
}


void UHealthComponent::Heal(float Amount)
{
	ChangeCurrentHealth(CurrentHealth + Amount);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
	}
}

void UHealthComponent::ChangeCurrentHealth(float NewAmount)
{
	if (NewAmount < 0)
	{
		CurrentHealth = 0;

		return;
	}

    if (NewAmount > MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
	else
	{
		CurrentHealth = NewAmount;
	}

	OnHealthChanged.Broadcast();
}





