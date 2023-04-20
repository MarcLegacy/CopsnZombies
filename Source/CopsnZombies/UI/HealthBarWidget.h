// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

class UProgressBar;

UCLASS()
class COPSNZOMBIES_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetHealthBar(const float Value);

private:
	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true", BindWidget))
		UProgressBar* HealthBar = nullptr;
};
