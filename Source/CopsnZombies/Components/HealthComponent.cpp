// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#include "HealthComponent.h"

#include "Components/WidgetComponent.h"
#include "CopsnZombies/Characters/CopsnZombiesCharacter.h"
#include "CopsnZombies/UI/HealthBarWidget.h"
#include "CopsnZombies/Utility/Logger.h"

UHealthComponent::UHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
    AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, MaxHealth);

	if (const ACopsnZombiesCharacter* CopsnZombiesCharacter = Cast<ACopsnZombiesCharacter>(GetOwner()); FLogger::CheckAndLogIsValidPtr(CopsnZombiesCharacter, __FUNCTION__))
	{
	    if (UHealthBarWidget* HealthBarWidget = Cast<UHealthBarWidget>(CopsnZombiesCharacter->GetWidgetComponent()->GetUserWidgetObject()); FLogger::CheckAndLogIsValidPtr(HealthBarWidget, __FUNCTION__))
	    {
	        HealthBarWidget->SetHealthBar(CurrentHealth / MaxHealth);
	    }
	}
}


void UHealthComponent::Heal(float Amount)
{
	if (Amount <= 0.0f) return;

	CurrentHealth = FMath::Clamp(CurrentHealth + Amount, 0.0f, MaxHealth);
}

void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}







