// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CopsnZombiesCharacter.generated.h"

class UWidgetComponent;
class UHealthComponent;

UENUM(BlueprintType)
enum ERace
{
	ER_Undefined	UMETA(DisplayName = "Undefined Race"),
    ER_Human		UMETA(DisplayName = "Human Race"),
	ER_Undead		UMETA(DisplayName = "Undead Race")
};

UCLASS(config=Game)
class ACopsnZombiesCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ACopsnZombiesCharacter();

	FORCEINLINE UHealthComponent* GetHealtComponent() const { return HealthComponent; }
	FORCEINLINE UWidgetComponent* GetWidgetComponent() const { return WidgetComponent; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<ERace> Race = ER_Undefined;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UHealthComponent* HealthComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UWidgetComponent* WidgetComponent = nullptr;
};

